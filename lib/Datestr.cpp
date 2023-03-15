#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <map>

namespace datestr {

    /*Function to take a number formatted as a string, and add it to a vector of date components if it will successfully
    ** convert to a number. Otherwise returns an "error vector" containing a singular -1
    ** Inputs: A vector of integers, and a string which should contain a number
    ** Output: The vector with the number added to it, or the error vector {-1}
    */
    void addToDateVector(std::vector<int>& dateVect, std::string number) {
        //Do nothing if it is already an error vector
        if(dateVect.size() > 0 && dateVect.at(0) != -1) {
            //Test if string will convert to integer
            try {
                dateVect.push_back(stoi(number));
            } catch(std::exception &err) {
                dateVect = {-1};
            }
        }
    }

    /* Overloaded version of addToDateVector, which also accepts a reference to a string stream and returns the error
    ** vector if the string stream is empty
    ** Inputs: A reference to a vector of integers, a string which should contain a number, and a reference to a string stream
    ** Output: The vector is updated to either add the number, or the error vector {-1}
    */
    void addToDateVector(std::vector<int>& dateVect, std::string number, std::stringstream& ss) {
        //Do nothing if it is already an error vector
        if(dateVect.size() > 0 && dateVect.at(0) != -1) {
            //Check if string stream is empty
            if(ss.rdbuf()->in_avail() == 0) {
                dateVect = {-1};
            } else {
                //Test if string will convert to integer
                try {
                    dateVect.push_back(stoi(number));
                } catch(std::exception &err) {
                    dateVect = {-1};
                }
            }
        }
    }
    
    /*Function to take a date formatted as MM/DD/YYYY and return as a vector
    ** Vector is formatted as {Month, Day, Year}, {Month, Day, Year, Hour, Minute}, or {-1} if stringis not formatted correctly
    ** Input: A date formatted as a string mm/DD/YYYY or mm/DD/YYYY HH:MM
    ** Output: A vector containing the components of the date as integers: {m, D, Y}, {m, D, Y, H, M}, or {-1}
    ** Returns vector containing -1 if string is improperly formatted
    */
    std::vector<int> parseDate(std::string dateString) {
        std::stringstream ss(dateString);
        std::string parse;
        std::vector<int> parsedDate;

        //Get month, day, and year
        std::getline(ss, parse, '-');
        addToDateVector(parsedDate, parse, ss);
        std::getline(ss, parse, '-');
        addToDateVector(parsedDate, parse, ss);
        std::getline(ss, parse, ' ');
        addToDateVector(parsedDate, parse);

        //If the string ends here, then the string was formatted mm/DD/YYYY. Return vector of length 3
        if(ss.rdbuf()->in_avail() == 0) {
            return parsedDate;
        }

        //Otherwise, get hour and minute
        std::getline(ss, parse, ':');
        addToDateVector(parsedDate, parse, ss);
        std::getline(ss, parse);
        addToDateVector(parsedDate, parse);

        return parsedDate;
    };

    /* Function that takes two dates formatted as strings and returns true if the first is before or equal to the second
    ** Inputs: Two dates formatted as strings mm/DD/YYYY HH:MM
    ** Output: A boolean value representing if the first date is before or equal to the second date
    */
    bool date_is_before(std::string date1, std::string date2) {
        std::vector<int> d1 = parseDate(date1);
        std::vector<int> d2 = parseDate(date2);

        //Array to specify the order to compare date elements: year, month, day, hour, minute
        int comparisonOrder[] = {2, 0, 1, 3, 4};
        for(int i = 0; i < 5; i++) {
            if(d1.at(comparisonOrder[i]) < d2.at(comparisonOrder[i])) {
                //This component of date1 is less than this component in date2, meaning date1 is before date2
                return true;
            } else if(d1.at(comparisonOrder[i]) > d2.at(comparisonOrder[i])) {
                //This component of date1 is greater than this component in date2, meaning date1 is after date2
                return false;
            }
        }
        //If we reach the end, and all date components are the same, then they are the same date and time
        return true;
    };

    /* Function to take a month name and return it's corresponding number
    ** Input: A month, formatted as a string containing the month's name
    ** Output: A month, formatted as an integer from 1-12, or -1 if month entered does not exist
    */
    int getMonthNumber (std::string month) {
        std::map <std::string, int> monthList {
            {"January", 1},
            {"February", 2},
            {"March", 3},
            {"April", 4},
            {"May", 5},
            {"June", 6},
            {"July", 7},
            {"August", 8},
            {"September", 9},
            {"October", 10},
            {"November", 11},
            {"December", 12}
        };
        
        const auto iter = monthList.find(month);
        if (iter != monthList.cend()) {
            return iter->second;
        }
        return -1;
    };

    /* Function to return the current date as a vector of date components as integers
    ** Output: A vector of integers corresponding to the components of the current date {m, D, Y}
    */
    std::vector<int> getCurrentDate() {
        // Calculate the current date
        time_t curr_time;
        tm * curr_tm;
        char date_char[100];
        char separator = ' ';
        std::string s;
        int i = 0;
        int currentYear;
        int count = 0;
        std::string currentMonth;
        int currentDay;

        std::vector<int> currentDate;

        time(&curr_time);
        curr_tm = localtime(&curr_time); 
        strftime(date_char, 50, "Today is %B %d, %Y", curr_tm);

        //Split the current date char into the year
        std::string date_string = date_char;

        while (date_string[i] != '\0') {
            if (date_string[i] != separator) {
                // Append the char to the temp string
                s += date_string[i]; 
            } else {
                count++;
                if (count == 3) {
                    currentMonth = s;
                    // currentDate.push_back(currentMonthNum);
                }
                if (count == 4) {
                    s.pop_back();
                    currentDay = stoi(s);
                    // currentDate.push_back(currentDay);
                }
                s.clear();
            }
            i++;
        }

        currentYear = stoi(s);
        int currentMonthNum = getMonthNumber(currentMonth);

        currentDate.push_back(currentMonthNum);
        currentDate.push_back(currentDay);
        currentDate.push_back(currentYear);
  
        return currentDate;
    };

    /* Function that takes a date formatted as a string and returns if it is a validly formatted string before the current date
    ** Input: Date formatted as a string mm/DD/YYYY HH:MM
    ** Output: Boolean value representing if the input date is formatted correctly and before the current date
    */
    bool checkValidDueDate (std::string inputDateString) {
            // Return bool for if date is valid
            bool valid = true;

            // Calculate the input date
            int inputMonth, inputDay, inputYear, inputHour, inputMinute;
            std::vector<int> inputDate = parseDate(inputDateString);
            inputMonth = inputDate.at(0);
            inputDay = inputDate.at(1);
            inputYear =  inputDate.at(2);
            inputHour = inputDate.at(3);
            inputMinute = inputDate.at(4);

            // Calculate the current date
            int currentMonth, currentDay, currentYear, currentHour, currentMinute;
            std::vector<int> currentDate = getCurrentDate();
            currentMonth = inputDate.at(0);
            currentDay = inputDate.at(1);
            currentYear =  inputDate.at(2);
            currentHour = inputDate.at(3);
            currentMinute = inputDate.at(4);

            // Check that the month is between 1 and 12,
            // the day is between 1 and 31 (checks specific months below if passes here),
            // the year is not before the current year,
            // the month is not before the current month, 
            // and the day is not before the current day
            if ((inputMonth < 1 || inputMonth > 12) || (inputDay < 1 || inputDay > 31) || (inputYear < currentYear) || (inputMonth < currentMonth) || (inputDay < currentDay)) {
                valid = false;
            }

            // Check that the input days is valid based on the specific month
            // April, June, September, November - 30 days
            else if (inputMonth == 4 || inputMonth == 6 || inputMonth == 9 || inputMonth == 11) {
                if (inputDay > 30) {
                    valid = false;
                }
            }
           
            // February - 28 days and leap year
            else if (inputMonth == 2) {
                // Leap year
                if ((inputYear % 4 == 0 && inputYear % 100 != 0) || inputYear % 400 == 0) {
                    if (inputDay > 29) {
                        valid = false;
                    }
                } else if (inputDay > 28) {
                    valid = false;
                }
            }
            return valid;
        }

}
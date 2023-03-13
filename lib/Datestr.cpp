#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <map>

namespace datestr {
    
    /*Function to take a date formatted as MM/DD/YYYY and return as a vector
    ** Input: A date formatted as a string mm/DD/YYYY HH:MM
    ** Output: A vector containing the components of the date as integers: {m, D, Y, H, M}
    */
    std::vector<int> parseDate(std::string dateString) {
        std::stringstream ss(dateString);
        std::string parse;
        std::vector<int> parsedDate;

        std::getline(ss, parse, '-');
        parsedDate.push_back(stoi(parse));
        std::getline(ss, parse, '-');
        parsedDate.push_back(stoi(parse));
        std::getline(ss, parse, ' ');
        parsedDate.push_back(stoi(parse));
        std::getline(ss, parse, ':');
        parsedDate.push_back(stoi(parse));
        std::getline(ss, parse);
        parsedDate.push_back(stoi(parse));

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
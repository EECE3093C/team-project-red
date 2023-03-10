#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <sstream>
#include <map>
#include <list>
#include <iterator>
#include <algorithm>

static std::vector<int> parseDate(std::string dateString) {
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

static bool date_is_before(std::string date1, std::string date2) {
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

class Task {
    protected:

    ///* Member Variables for the Class *///
        
        // String for extra things to do
        std::string m_thingsToDo;
        
        // String for item date
        std::string m_dueDate;
  
        // Priority Enum for item priority -- not sure how to use this so doing string for right now
        enum m_priority
        {
            high = 1,
            medium = 2,
            low = 3
        };
        std::string m_priority;

        // Combined overall Priority based on 
        int m_overallPriority;

        // Vector of Items in ToDo List
        std::vector<std::string> toDoList;
    
    public:

        // Task Constructor
        Task(std::string thingsToDo, std::string dueDate, std::string priority)
        {
            m_thingsToDo = thingsToDo;
            m_dueDate = dueDate;
            m_priority = priority;
            
            // Check that the due date is valid
            bool validDueDate = checkValidDueDate();

            if (validDueDate == false)
            {
                std::cout << "Due date is invalid.";
            }
        }

        // Default Constructor
        Task() {}

        //Getters
        std::string thingsToDoItem()
        {
            return m_thingsToDo;        
        }

        std::string getDueDate() {
            return m_dueDate;
        }

        // Helper function to take the input month and convert it to an int
        int getMonthNumber (std::string month)
        {
            std::map <std::string, int> monthList
            {
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
            if (iter != monthList.cend())
            {
                return iter->second;
            }
            return -1;
        }

        // Helper function to get the current date
        std::list<int> getCurrentDate()
        {
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

            std::list <int> currentDate;

            time(&curr_time);
            curr_tm = localtime(&curr_time); 
            strftime(date_char, 50, "Today is %B %d, %Y", curr_tm);

            // Split the current date char into the year
            std::string date_string = date_char;

            while (date_string[i] != '\0')
            {
                if (date_string[i] != separator) 
                {
                    // Append the char to the temp string
                    s += date_string[i]; 
                } 
                else 
                {
                    count++;
                    if (count == 3)
                    {
                        currentMonth = s;
                        // currentDate.push_back(currentMonthNum);
                    }
                    if (count == 4)
                    {
                        s.pop_back();
                        currentDay = stoi(s);
                        // currentDate.push_back(currentDay);
                    }
                    s.clear();
                }
                i++;
            }

            currentYear = stoi(s);
            currentDate.push_back(currentYear);
            int currentMonthNum = getMonthNumber(currentMonth);
            currentDate.assign(1, currentYear);
            currentDate.push_front(currentDay);
            currentDate.push_front(currentMonthNum);
            s.clear();
  
            return currentDate;
        }

        // Helper function to split the input date into a vector
        std::list<int> getInputDate()
        {
            int k = 0;
            std::string s;
            int inputMonth;
            int inputDay;
            int inputYear;
            char inputSeparator = '-';
            int inputCount = 0;
            std::list<int> inputDate;

            while (m_dueDate[k] != '\0')
            {
                if (m_dueDate[k] != inputSeparator) 
                {
                    // Append the char to the temp string
                    s += m_dueDate[k]; 
                } 
                else
                {
                    inputCount++;
                    if (inputCount == 1)
                    {
                        inputMonth = stoi(s);
                    }
                    if (inputCount == 2)
                    {
                        inputDay = stoi(s);
                    }
                    s.clear();
                }
                k++;
            }
            inputYear = stoi(s);

            inputDate.push_back(inputYear);
            inputDate.assign(1, inputYear);
            inputDate.push_front(inputDay);
            inputDate.push_front(inputMonth);
            s.clear();

            return inputDate;
        }

        // Method to check that a due date is not in the past and is 
        // formatted correctly
        // FORMATTING: MM-DD-YYYY
        bool checkValidDueDate ()
        {
            // Return bool for if date is valid
            bool valid = true;


            // Calculate the input date
            int inputMonth, inputDay, inputYear;
            std::list<int> inputDate = getInputDate();
            inputMonth = inputDate.front();
            inputYear =  inputDate.back();
            std::list<int>::iterator input = inputDate.begin();
            std::advance(input, 1);
            inputDay = *input;


            // Calculate the current date
            int currentYear, currentMonth, currentDay;
            std::list <int> currentDate = getCurrentDate();
            currentMonth = currentDate.front();
            currentYear = currentDate.back();
            std::list<int>::iterator it = currentDate.begin();
            std::advance(it, 1);
            currentDay = *it;


            // Check that the month is between 1 and 12,
            // the day is between 1 and 31 (checks specific months below if here passes),
            // the year is not before the current year,
            // the month is not before the current month, 
            // and the day is not before the current day
            if ((inputMonth < 1 || inputMonth > 12) || (inputDay < 1 || inputDay > 31) || (inputYear < currentYear) || 
                    (inputMonth < currentMonth) || (inputDay < currentDay))
            {
                valid = false;
            }


            // Check that the input days is valid based on the specific month
            // April, June, September, November - 30 days
            else if (inputMonth == 4 || inputMonth == 6 || inputMonth == 9 || inputMonth == 11)
            {
                if (inputDay > 30)
                {
                    valid = false;
                }
            }
           
            // February - 28 days and leap year
            else 
            {
                if (inputMonth == 2)
                {
                    // Leap year
                    if ((inputYear % 4 == 0 && inputYear % 100 != 0) || inputYear % 400 == 0)
                    {
                        if (inputDay > 29)
                        {
                            valid = false;
                        }
                    }
                    // Not a leap year
                    else if (inputDay > 28)
                    {
                        valid = false;
                    }
                }
            }

            return valid;

        }

        // Method to return overall priority based on due date and priority given by user
        int overallPriority()
        {
            // Integer 1 - 10 that ranks the priority of the task, 1 being highest and 10 being lowest
            int overallPriority = 0;

            // Method locals
            int priorityInt;

            
            // Convert the priority string into number format
            if (m_priority == "High" || m_priority == "high")
            {
                priorityInt = 3;
            }
            else if (m_priority == "Medium" || m_priority == "medium")
            {
                priorityInt = 2;
            }
            else 
            {
                priorityInt = 1;
            }            
            

            // Calculate the current date
            int currentYear, currentMonth, currentDay;
            std::list <int> currentDate = getCurrentDate();
            currentMonth = currentDate.front();
            currentYear = currentDate.back();
            std::list<int>::iterator it = currentDate.begin();
            std::advance(it, 1);
            currentDay = *it;


            // Calculate the input date
            int inputMonth, inputDay, inputYear;
            std::list<int> inputDate = getInputDate();
            inputMonth = inputDate.front();
            inputYear =  inputDate.back();
            std::list<int>::iterator input = inputDate.begin();
            std::advance(input, 1);
            inputDay = *input;


            // Compare the two dates
            while (overallPriority == 0)
            {   
                // Assign lowest priorities if the years are different and 
                // the month is not December    
                if (inputYear > currentYear)
                {
                    if (inputMonth != 12)
                    {
                        overallPriority = 10;
                        break;
                    }
                }
                if (inputYear == currentYear)
                {
                    if (inputMonth == currentMonth)
                    {
                        // Assign highest priority if it is the current date
                        if (currentDay == inputDay)
                        {
                            overallPriority = 1;
                            break;
                        }
                        
                        // Calculate the date difference if the months are the same
                        int difference = inputDay - currentDay;
                        if (difference <= 2)
                        {
                            if (priorityInt == 3)
                            {
                                overallPriority = 1;
                                break;
                            }
                            if (priorityInt == 2)
                            {
                                overallPriority = 2;
                                break;
                            }
                            if (priorityInt == 1)
                            {
                                overallPriority = 3;
                                break;
                            }                   
                        }
                        else if (difference <= 5)
                        {
                            if (priorityInt == 3)
                            {
                                overallPriority = 4;
                                break;
                            }
                            if (priorityInt == 2)
                            {
                                overallPriority = 5;
                                break;
                            }
                            if (priorityInt == 1)
                            {
                                overallPriority = 6;
                                break;
                            }                   
                        }
                        else 
                        {
                            if (priorityInt == 3)
                            {
                                overallPriority = 7;
                                break;
                            }
                            if (priorityInt == 2)
                            {
                                overallPriority = 8;
                                break;
                            }
                            if (priorityInt == 1)
                            {
                                overallPriority = 9;
                                break;
                            }                   
                        }
                    }
                    // If the months are different, calculate the difference and in months and date
                    // and assign priority
                    else 
                    {
                        int monthDifference = inputMonth - currentMonth;

                        if (monthDifference > 3)
                        {
                            overallPriority = 10;
                            break;
                        }

                        else if (monthDifference >= 2)
                        {
                            if (priorityInt == 3)
                            {
                                overallPriority = 7;
                                break;
                            }
                            if (priorityInt == 2)
                            {
                                overallPriority = 8;
                                break;
                            }
                            if (priorityInt == 1)
                            {
                                overallPriority = 9;
                                break;
                            }                   
                        }
                        else
                        {
                            // If the month is only one away, the date needs to be checked to see the difference
                            if (currentDay >= 26)  // INFINITE LOOP HERE
                            {
                                if (inputDay <= 2)
                                {
                                    // If the month is February, assign it high priority because of less days
                                    if (currentMonth == 2)
                                    {
                                        if (priorityInt == 3)
                                        {
                                            overallPriority = 3;
                                            break;
                                        }
                                        if (priorityInt == 2)
                                        {
                                            overallPriority = 4;
                                            break;
                                        }
                                        if (priorityInt == 1)
                                        {
                                            overallPriority = 5;
                                            break;
                                        }                   
                                    }
                                    else 
                                    {
                                        if (priorityInt == 3)
                                        {
                                            overallPriority = 7;
                                            break;
                                        }
                                        if (priorityInt == 2)
                                        {
                                            overallPriority = 8;
                                            break;
                                        }
                                        if (priorityInt == 1)
                                        {
                                            overallPriority = 9;
                                            break;
                                        }                   
                                    }
                                }
                                else
                                {
                                    if (priorityInt == 3)
                                        {
                                            overallPriority = 7;
                                            break;
                                        }
                                        if (priorityInt == 2)
                                        {
                                            overallPriority = 8;
                                            break;
                                        }
                                        if (priorityInt == 1)
                                        {
                                            overallPriority = 9;
                                            break;
                                        }  
                                }

                            }
                            else 
                            {
                                if (priorityInt == 3)
                                {
                                    overallPriority = 7;
                                    break;
                                }
                                if (priorityInt == 2)
                                {
                                    overallPriority = 8;
                                    break;
                                }
                                if (priorityInt == 1)
                                {
                                    overallPriority = 9;
                                    break;
                                }  
                            }
                        }
                    }
                }
            }
            return overallPriority;
        }

        //Operator overloads for < and >
        bool operator<(Task task) {
            if(overallPriority() < task.overallPriority()) {
                return true;
            } else if(overallPriority() > task.overallPriority()) {
                return false;
            } else {
                return date_is_before(getDueDate(), task.getDueDate());
            }
        }

        bool operator>(Task task) {
            if(overallPriority() > task.overallPriority()) {
                return true;
            } else if(overallPriority() < task.overallPriority()) {
                return false;
            } else {
                return !date_is_before(getDueDate(), task.getDueDate());
            }
        }
};
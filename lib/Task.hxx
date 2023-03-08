#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <sstream>
#include <algorithm>


// THINGS TO ADD:
    // 1. Method that orders the things on the list based on priority and date 
            // will need function that calculates current date and time
            // need to discuss how we want to evaluate hierarchy between priority and date
    // 2. Method to output things to do List in a text file along with calendar, etc.
    // 3. Need to incorporate CANVAS tasks as well, but that is seperate from here

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
        //Default Constructor
        Task() {
            m_thingsToDo = "";
            m_dueDate = "01-01-1970";
            m_priority = "low";
        }

        //Task Constructor
        Task(std::string thingsToDo, std::string dueDate, std::string priority)
        {
            m_thingsToDo = thingsToDo;
            m_dueDate = dueDate;
            m_priority = priority;
        }

        //Getters
        std::string thingsToDoItem()
        {
            return m_thingsToDo;        
        }

        std::string getDueDate() {
            return m_dueDate;
        }

        // Method to return overall priority based on due date and priority given by user
        int overallPriority()
        {
            // Integer 1 - 10 that ranks the priority of the task, 1 being highest and 10 being lowest
            int overallPriority = 0;

            // Method locals
            int priorityInt;
            time_t curr_time;
            tm * curr_tm;
            char date_char[100];
            std::vector <std::string> months {"January", "February", "March", "April",
                                            "May", "June", "July", "August", "September", 
                                            "October", "November", "December"};
            
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
            time(&curr_time);
            curr_tm = localtime(&curr_time); 
            strftime(date_char, 50, "Today is %B %d, %Y", curr_tm);

            // Split the current date char into month, day, year
            char separator = ' ';
            int i = 0;
            int count = 0;
            std::string s;
            std::string currentMonth;
            int currentDay;
            int currentYear;

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
                    }
                    if (count == 4)
                    {
                        s.pop_back();
                        currentDay = stoi(s);
                    }
                    s.clear();
                }
                i++;
            }
            currentYear = stoi(s);
            s.clear();

            // Split the input date into month, day, year
            // YYYY-Month-Day -- input of user for now 
            // 2023-March-01 -- CHANGE TO 03-01-2023
            int k = 0;
            std::string inputMonth;
            int inputDay;
            int inputYear;
            char inputSeparator = '-';
            int inputCount = 0;

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
                        inputYear = stoi(s);
                    }
                    if (inputCount == 2)
                    {
                        inputMonth = s;
                    }
                    s.clear();
                }
                k++;
            }
            inputDay = stoi(s);

            // Compare the two dates
            while (overallPriority == 0)
            {   
                // Assign lowest priorities if the years are different and 
                // the month is not December    
                if (inputYear > currentYear)
                {
                    if (inputMonth != "December")
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
                        std::vector<std::string>::iterator inputItr = std::find(months.begin(), months.end(), inputMonth);
                        std::vector<std::string>::iterator currentItr = std::find(months.begin(), months.end(), currentMonth);

                        int inputMonthNum = std::distance(months.begin(), inputItr);
                        int currentMonthNum = std::distance(months.begin(), currentItr);

                        int monthDifference = inputMonthNum - currentMonthNum;

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
                            if (currentDay >= 26)
                            {
                                if (inputDay <= 2)
                                {
                                    if (currentMonth == "February")
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
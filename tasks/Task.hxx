#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <algorithm>


// THINGS TO ADD:
    // 1. Method that orders the things on the list based on priority and date 
            // will need function that calculates current date and time
            // need to discuss how we want to evaluate hierarchy between priority and date
    // 2. Method to output things to do List in a text file along with calendar, etc.
    // 3. Need to incorporate CANVAS tasks as well, but that is seperate from here
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
        }

        // Method to return things to do item
        std::string thingsToDoItem()
        {
            return m_thingsToDo;        
        }

        // Method to return overall priority based on due date and priority given by user
        int overallPriority(std::string dueDate, std::string priority)
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
            if (priority == "High" || priority == "high")
            {
                priorityInt = 3;
                std::cout << "priorityint " << priorityInt;
            }
            else if (priority == "Medium" || priority == "medium")
            {
                priorityInt = 2;
                std::cout << "priorityint " << priorityInt;
            }
            else 
            {
                priorityInt = 1;
                std::cout << "priorityint " << priorityInt;
            }
            
            
            // Calculate the current date
            time(&curr_time);
            curr_tm = localtime(&curr_time); 
            strftime(date_char, 50, "Today is %B %d, %Y", curr_tm);
            std::cout << date_char << std::endl;

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
                        std::cout << s << std::endl;
                    }
                    if (count == 4)
                    {
                        s.pop_back();
                        currentDay = stoi(s);
                        std::cout << s << std::endl;
                    }
                    s.clear();
                }
                i++;
            }
            currentYear = stoi(s);
            std::cout << s << std::endl; 
            s.clear();

            // Split the input date into month, day, year
            int k = 0;
            std::string inputMonth;
            int inputDay;
            int inputYear;
            char inputSeparator = '-';
            int inputCount = 0;

            while (dueDate[k] != '\0')
            {
                if (dueDate[k] != inputSeparator) 
                {
                    // Append the char to the temp string
                    s += dueDate[k]; 
                } 
                else
                {
                    inputCount++;
                    if (inputCount == 1)
                    {
                        inputYear = stoi(s);
                        std::cout << s << std::endl;
                    }
                    if (inputCount == 2)
                    {
                        inputMonth = s;
                        std::cout << s << std::endl;
                    }
                    s.clear();
                }
                k++;
            }
            inputDay = stoi(s);
            std::cout << s << std::endl;

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
                        std::cout << "Priority assigned to 10";
                        break;
                    }
                }
                if (inputYear == currentYear)
                {
                    if (inputMonth == currentMonth)
                    {
                        std::cout << "Months are the same!" << std::endl;
                        // Assign highest priority if it is the current date
                        if (currentDay == inputDay)
                        {
                            overallPriority = 1;
                            std::cout << "Priority assigned to 1";
                            break;
                        }
                        
                        // Calculate the date difference if the months are the same
                        int difference = inputDay - currentDay;
                        if (difference <= 2)
                        {
                            if (priorityInt == 3)
                            {
                                overallPriority = 1;
                                std::cout << "Priority assigned to 1";
                                break;
                            }
                            if (priorityInt == 2)
                            {
                                overallPriority = 2;
                                std::cout << "Priority assigned to 2";
                                break;
                            }
                            if (priorityInt == 1)
                            {
                                overallPriority = 3;
                                std::cout << "Priority assigned to 3";
                                break;
                            }                   
                        }
                        else if (difference <= 5)
                        {
                            if (priorityInt == 3)
                            {
                                overallPriority = 4;
                                std::cout << "Priority assigned to 4";
                                break;
                            }
                            if (priorityInt == 2)
                            {
                                overallPriority = 5;
                                std::cout << "Priority assigned to 5";
                                break;
                            }
                            if (priorityInt == 1)
                            {
                                overallPriority = 6;
                                std::cout << "Priority assigned to 6";
                                break;
                            }                   
                        }
                        else 
                        {
                            if (priorityInt == 3)
                            {
                                overallPriority = 7;
                                std::cout << "Priority assigned to 7";
                                break;
                            }
                            if (priorityInt == 2)
                            {
                                overallPriority = 8;
                                std::cout << "Priority assigned to 8";
                                break;
                            }
                            if (priorityInt == 1)
                            {
                                overallPriority = 9;
                                std::cout << "Priority assigned to 9";
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
                            std::cout << "Priority assigned to 10";
                            break;
                        }

                        else if (monthDifference >= 2)
                        {
                            if (priorityInt == 3)
                            {
                                overallPriority = 7;
                                std::cout << "Priority assigned to 7";
                                break;
                            }
                            if (priorityInt == 2)
                            {
                                overallPriority = 8;
                                std::cout << "Priority assigned to 8";
                                break;
                            }
                            if (priorityInt == 1)
                            {
                                overallPriority = 9;
                                std::cout << "Priority assigned to 9";
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
                                            std::cout << "Priority assigned to 3";
                                            break;
                                        }
                                        if (priorityInt == 2)
                                        {
                                            overallPriority = 4;
                                            std::cout << "Priority assigned to 4";
                                            break;
                                        }
                                        if (priorityInt == 1)
                                        {
                                            overallPriority = 5;
                                            std::cout << "Priority assigned to 5";
                                            break;
                                        }                   
                                    }
                                    else 
                                    {
                                        if (priorityInt == 3)
                                        {
                                            overallPriority = 7;
                                            std::cout << "Priority assigned to 7";
                                            break;
                                        }
                                        if (priorityInt == 2)
                                        {
                                            overallPriority = 8;
                                            std::cout << "Priority assigned to 8";
                                            break;
                                        }
                                        if (priorityInt == 1)
                                        {
                                            overallPriority = 9;
                                            std::cout << "Priority assigned to 9";
                                            break;
                                        }                   
                                    }
                                }
                                else
                                {
                                    if (priorityInt == 3)
                                        {
                                            overallPriority = 7;
                                            std::cout << "Priority assigned to 7";
                                            break;
                                        }
                                        if (priorityInt == 2)
                                        {
                                            overallPriority = 8;
                                            std::cout << "Priority assigned to 8";
                                            break;
                                        }
                                        if (priorityInt == 1)
                                        {
                                            overallPriority = 9;
                                            std::cout << "Priority assigned to 9";
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
};
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Datestr.cpp"

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
        // Default Constructor
        Task() {}

        //Task Constructor
        Task(std::string thingsToDo, std::string dueDate, std::string priority) {
            m_thingsToDo = thingsToDo;
            m_dueDate = dueDate;
            m_priority = priority;
            
            // Check that the due date is valid
            bool validDueDate = datestr::checkValidDueDate(dueDate);

            if (validDueDate == false) {
                std::cout << "Due date is invalid.";
            }
        }

        //Getters
        std::string thingsToDoItem() {
            return m_thingsToDo;        
        }

        std::string getDueDate() {
            return m_dueDate;
        }

        // Method to check that a due date is not in the past and is 
        // formatted correctly
        // FORMATTING: MM-DD-YYYY
        

        // Method to return overall priority based on due date and priority given by user
        int overallPriority() {
            // Integer 1 - 10 that ranks the priority of the task, 1 being highest and 10 being lowest
            int overallPriority = 0;

            // Method locals
            int priorityInt;

            // Convert the priority string into number format
            if (m_priority == "High" || m_priority == "high") {
                priorityInt = 3;
            } else if (m_priority == "Medium" || m_priority == "medium") {
                priorityInt = 2;
            } else {
                priorityInt = 1;
            }            
            
            // Calculate the current date
            int currentYear, currentMonth, currentDay;
            std::vector<int> currentDate = datestr::getCurrentDate();
            currentMonth = currentDate.at(0);
            currentDay = currentDate.at(1);
            currentYear = currentDate.at(2);

            // Calculate the due date
            int dueMonth, dueDay, dueYear;
            std::vector<int> inputDate = datestr::parseDate(m_dueDate);
            dueMonth = inputDate.at(0);
            dueDay = inputDate.at(1);
            dueYear =  inputDate.at(2);

            // Compare the two dates
            while (overallPriority == 0) {   
                // Assign lowest priorities if the years are different and 
                // the month is not December    
                if (dueYear > currentYear) {
                    if (dueMonth != 12) {
                        overallPriority = 10;
                        break;
                    }
                }
                if (dueYear == currentYear) {
                    if (dueMonth == currentMonth) {
                        // Assign highest priority if it is the current date
                        if (currentDay == dueDay) {
                            overallPriority = 1;
                            break;
                        }
                        
                        // Calculate the date difference if the months are the same
                        int difference = dueDay - currentDay;
                        if (difference <= 2) {
                            if (priorityInt == 3) {
                                overallPriority = 1;
                                break;
                            }
                            if (priorityInt == 2) {
                                overallPriority = 2;
                                break;
                            }
                            if (priorityInt == 1) {
                                overallPriority = 3;
                                break;
                            }                   
                        } else if (difference <= 5) {
                            if (priorityInt == 3) {
                                overallPriority = 4;
                                break;
                            }
                            if (priorityInt == 2) {
                                overallPriority = 5;
                                break;
                            }
                            if (priorityInt == 1) {
                                overallPriority = 6;
                                break;
                            }                   
                        } else {
                            if (priorityInt == 3) {
                                overallPriority = 7;
                                break;
                            }
                            if (priorityInt == 2) {
                                overallPriority = 8;
                                break;
                            }
                            if (priorityInt == 1) {
                                overallPriority = 9;
                                break;
                            }                   
                        }
                    }
                    
                    // If the months are different, calculate the difference and in months and date
                    // and assign priority
                    else {
                        int monthDifference = dueMonth - currentMonth;

                        if (monthDifference > 3) {
                            overallPriority = 10;
                            break;
                        } else if (monthDifference >= 2) {
                            if (priorityInt == 3) {
                                overallPriority = 7;
                                break;
                            }
                            if (priorityInt == 2) {
                                overallPriority = 8;
                                break;
                            }
                            if (priorityInt == 1) {
                                overallPriority = 9;
                                break;
                            }                   
                        } else {
                            // If the month is only one away, the date needs to be checked to see the difference
                            if (currentDay >= 26)  {
                                if (dueDay <= 2) {
                                    // If the month is February, assign it high priority because of less days
                                    if (currentMonth == 2) {
                                        if (priorityInt == 3) {
                                            overallPriority = 3;
                                            break;
                                        }
                                        if (priorityInt == 2) {
                                            overallPriority = 4;
                                            break;
                                        }
                                        if (priorityInt == 1) {
                                            overallPriority = 5;
                                            break;
                                        }                   
                                    } else {
                                        if (priorityInt == 3) {
                                            overallPriority = 7;
                                            break;
                                        }
                                        if (priorityInt == 2) {
                                            overallPriority = 8;
                                            break;
                                        }
                                        if (priorityInt == 1) {
                                            overallPriority = 9;
                                            break;
                                        }                   
                                    }
                                } else {
                                    if (priorityInt == 3) {
                                        overallPriority = 7;
                                        break;
                                    }
                                    if (priorityInt == 2) {
                                        overallPriority = 8;
                                        break;
                                    }
                                    if (priorityInt == 1) {
                                        overallPriority = 9;
                                        break;
                                    }  
                                }
                            } else {
                                if (priorityInt == 3) {
                                    overallPriority = 7;
                                    break;
                                }
                                if (priorityInt == 2) {
                                    overallPriority = 8;
                                    break;
                                }
                                if (priorityInt == 1) {
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
                return datestr::date_is_before(getDueDate(), task.getDueDate());
            }
        }

        bool operator>(Task task) {
            if(overallPriority() > task.overallPriority()) {
                return true;
            } else if(overallPriority() < task.overallPriority()) {
                return false;
            } else {
                return !datestr::date_is_before(getDueDate(), task.getDueDate());
            }
        }
};
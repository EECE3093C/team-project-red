#include <string>
#include <iostream>
#include <vector>


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

        // Method to return things to do item
        std::string thingsToDoItem()
        {
            return m_thingsToDo;        
        }

        int getOverallPriority() {
            return m_overallPriority;
        }

        // ADD OVERALL PRIORITY FUNCTION
};
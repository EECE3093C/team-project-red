#include <string>
#include <iostream>
#include <vector>


// THINGS TO ADD:
    // 1. Method that orders the things on the list based on priority and date 
            // will need function that calculates current date and time
            // need to discuss how we want to evaluate hierarchy between priority and date
    // 2. Method to output things to do List in a text file along with calendar, etc.
    // 3. Need to incorporate CANVAS tasks as well, but that is seperate from here
class Tasks {
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

        // Vector of Items in ToDo List
        std::vector<std::string> toDoList;

        // Filler variable for Canvas Assignments - need to look into API
        std::string canvasAssignment;
    
    public:

        // Method to return things to do item
        std::string thingsToDoItem()
        {
            return m_thingsToDo;        
        }

        // Method to add items to vector of things to do tasks
        void addTaskItem (std::string& item, std::string& priority, std::string& date)
        {
            m_thingsToDo = item;
            m_priority = priority;
            m_dueDate = date;
            toDoList.insert(toDoList.end(), {m_thingsToDo, m_priority, m_dueDate});
        }

        // Method to Display Things To Do List
        std::vector<std::string> thingsToDoList()
        {
            for(int i=0; i < toDoList.size(); i++)
            {
                std::cout << toDoList.at(i) << ' ';
            }           
            return toDoList;
        }
};
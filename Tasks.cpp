#include <string>
#include <iostream>
#include <vector>


// Probably need to put this in a seperate header file !
class Tasks {
    protected:

    //* Member Variables for the Class *//
        
        // String for extra things to do
        std::string m_thingsToDo;
        
        // String for item date
        std::string m_dueDate;
  
        // Priority Enum for item priority -- not sure how to use this so doing int for right now
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




int main()
{
    Tasks task;

    std::string item = "run";
    std::string priority = "high";
    std::string date = "19-Feb-2023";

    task.addTaskItem(item, priority, date);
    task.addTaskItem(item, priority, date);
    task.thingsToDoList();

    // Create a function here that tasks user input of item, priority, and date
    // until user enters done and adds them all to the vectors

    // Then would need to order pairs based on priority and due date - give them different
    // weights


    return 0;
}
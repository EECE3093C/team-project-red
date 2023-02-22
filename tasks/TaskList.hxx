#include <string>
#include <iostream>
#include <vector>
#include <Task.hxx>

class TaskList 
{
    protected:
        // Task item from Tasks Class
        Task m_Task;

        // Vector of Items in ToDo List
        std::vector<Task> toDoList;
  
    public: 
        // Preston edit this method
        void addTaskItem (Task& task)
        {
            m_Task = task;
            toDoList.insert(toDoList.end(), {m_Task});
        }


};
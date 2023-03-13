#include <iostream>
#include "../lib/TaskList.hxx"

int main() {
    //Declare data structures to hold events and tasks
    TaskList tasks = TaskList();

    //Welcome message and options
    std::cout << "Welcome to [Software Name]!" << std::endl;
    std::cout << "Main menu:" << std::endl;
    std::cout << "C - Authenticate with Canvas" << std::endl;
    std::cout << "T - Manually add Task" << std::endl;
    std::cout << "E - Manually add Event" << std::endl;
    std::cout << "G - Generate my weekly schedule!" << std::endl;
    std::cout << "Q - Quit" << std::endl;

    //Menu selection
    char choice;
    std::cin >> choice;
    while(tolower(choice) != 'c' && tolower(choice) != 't' && tolower(choice) != 'e' && tolower(choice) != 'g' && tolower(choice) != 'q') {
        std::cout << "Invalid menu option. Please enter a menu option from the list" << std::endl;
    }

    while(tolower(choice) != 'q') {
        //Log-in to Canvas
        if(tolower(choice) == 'c') {
            std::cout << "Canvas integration is still in development" << std::endl;
        }

        //Fetch Canvas events and tasks

        //Manually add tasks
        if(tolower(choice) == 't') {
            std::string taskName, taskDate, taskPriority;
            std::cout << "Enter the name of the task: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, taskName);
            std::cout << "Enter the due date of the task (format: \"YYYY-MMMMM-DD\")" << std::endl;
            std::getline(std::cin, taskDate);
            std::cout << "Enter the priority for the task (\"high\", \"medium\", or \"low\")" << std::endl;
            std::getline(std::cin, taskPriority);
            tasks.addTask(Task(taskName, taskDate, taskPriority));
        }

        //Manually add events
        if(tolower(choice) == 'e') {
            std::cout << "Events are not yet supported" << std::endl;
        }

        //Miscellaneous schedule constraints

        //Partition into days

        //Display tasks
        if(tolower(choice) == 'g') {
            std::cout << "Prioritized tasks" << std::endl;

            int i = 1;
            while(!tasks.isEmpty()) {
                std::cout << "Task " << i << ": " << tasks.nextTask().thingsToDoItem() << std::endl; 
                i = i + 1;
            }
        }

        //Re-display menu and prompt
        std::cout << "Main menu:" << std::endl;
        std::cout << "C - Authenticate with Canvas" << std::endl;
        std::cout << "T - Manually add Task" << std::endl;
        std::cout << "E - Manually add Event" << std::endl;
        std::cout << "G - Generate my weekly schedule!" << std::endl;
        std::cout << "Q - Quit" << std::endl;

        std::cin >> choice;
        while(tolower(choice) != 'c' && tolower(choice) != 't' && tolower(choice) != 'e' && tolower(choice) != 'g' && tolower(choice) != 'q') {
            std::cout << "Invalid menu option. Please enter a menu option from the list" << std::endl;
        }
    }

    std::cout << "Quitting [Software Name]" << std::endl;
    return 0;
}
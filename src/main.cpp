#include <iostream>
#include <vector>
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

            //Get task name
            std::cout << "Enter the name of the task: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, taskName);

            //Get due date
            std::cout << "Enter the due date of the task (format: \"MM-DD-YYYY\" or \"MM-DD-YYYY HH:MM\")" << std::endl;
            std::cout << "If entered without the time, a time of 11:59 PM will be assumed" << std::endl;
            std::getline(std::cin, taskDate);
            std::vector<int> vectDate = datestr::parseDate(taskDate);
            while(vectDate.size() == 1) {
                //Date was improperly formatted. Re-prompt
                std::cout << "Date must be formatted as \"MM-DD-YYYY\" or \"MM-DD-YYYY HH:MM\"" << std::endl;
                std::cout << "Please re-enter the due date: " << std::endl;
                std::getline(std::cin, taskDate);
                vectDate = datestr::parseDate(taskDate);
            }

            //Check if implicit 11:59 PM must be added on to end of date
            if(vectDate.size() == 3) {
                taskDate = taskDate + " 23:59";
            }

            //Get task priority
            std::cout << "Enter the priority for the task (\"high\", \"medium\", or \"low\")" << std::endl;
            std::getline(std::cin, taskPriority);
            while(taskPriority != "high" && taskPriority != "medium" && taskPriority != "low") {
                std::cout << "Task priority must be \"high\", \"medium\", or \"low\"" << std::endl;
                std::cout << "Please re-enter the priority: " << std::endl;
                std::getline(std::cin, taskPriority);
            }

            //Create new task
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
                std::cout << "Task " << i << ": " << tasks.nextTask().getTaskName() << std::endl; 
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
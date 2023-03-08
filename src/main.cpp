#include <iostream>
#include "lib/TaskList.hxx"
using namespace std;

int main() {
    //Declare data structures to hold events and tasks
    TaskList tasks = TaskList();

    //Welcome message and options
    cout << "Welcome to [Software Name]!" << endl;
    cout << "Main menu:" << endl;
    cout << "C - Authenticate with Canvas" << endl;
    cout << "T - Manually add Task" << endl;
    cout << "E - Manually add Event" << endl;
    cout << "G - Generate my weekly schedule!" << endl;
    cout << "Q - Quit" << endl;

    //Menu selection
    char choice;
    cin >> choice;
    while(tolower(choice) != 'c' && tolower(choice) != 't' && tolower(choice) != 'e' && tolower(choice) != 'g' && tolower(choice) != 'q') {
        cout << "Invalid menu option. Please enter a menu option from the list" << endl;
    }

    while(tolower(choice) != 'q') {
        //Log-in to Canvas
        if(tolower(choice) == 'c') {
            cout << "Canvas integration is still in development" << endl;
        }

        //Fetch Canvas events and tasks

        //Manually add tasks
        if(tolower(choice) == 't') {
            string taskName, taskDate, taskPriority;
            cout << "Enter the name of the task: " << endl;
            cin.ignore();
            getline(cin, taskName);
            cout << "Enter the due date of the task (format: \"YYYY-MMMMM-DD\")" << endl;
            getline(cin, taskDate);
            cout << "Enter the priority for the task (\"high\", \"medium\", or \"low\")" << endl;
            getline(cin, taskPriority);
            tasks.addTask(Task(taskName, taskDate, taskPriority));
        }

        //Manually add events
        if(tolower(choice) == 'e') {
            cout << "Events are not yet supported" << endl;
        }

        //Miscellaneous schedule constraints

        //Partition into days

        //Display tasks
        if(tolower(choice) == 'g') {
            cout << "Prioritized tasks" << endl;

            int i = 1;
            while(!tasks.isEmpty()) {
                cout << "Task " << i << ": " << tasks.nextTask().thingsToDoItem() << endl; 
                i = i + 1;
            }
        }

        //Re-display menu and prompt
        cout << "Main menu:" << endl;
        cout << "C - Authenticate with Canvas" << endl;
        cout << "T - Manually add Task" << endl;
        cout << "E - Manually add Event" << endl;
        cout << "G - Generate my weekly schedule!" << endl;
        cout << "Q - Quit" << endl;

        cin >> choice;
        while(tolower(choice) != 'c' && tolower(choice) != 't' && tolower(choice) != 'e' && tolower(choice) != 'g' && tolower(choice) != 'q') {
            cout << "Invalid menu option. Please enter a menu option from the list" << endl;
        }
    }

    cout << "Quitting [Software Name]" << endl;
    return 0;
}
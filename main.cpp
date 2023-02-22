#include <iostream>
using namespace std;

int main() {
    //Declare data structures to hold events and tasks

    //Welcome message and options
    cout << "Welcome to [Software Name]!" << endl;
    cout << "Main menu:" << endl;
    cout << "C - Authenticate with Canvas" << endl;
    cout << "T - Manually add Task" << endl;
    cout << "E - Manually add Event" << endl;
    cout << "G - Generate my weekly schedule!" << endl;
    cout << "Q - Quit";

    //Menu selection
    char choice;
    cin >> choice;
    while(choice != 'c' && choice != 't' && choice != 'e' && choice != 'g' && choice != 'q') {
        cout << "Invalid menu option. Please enter a menu option from the list" << endl;
    }

    while(choice != 'q') {
        //Log-in to Canvas

        //Fetch Canvas events and tasks

        //Manually add tasks

        //Manually add events

        //Miscellaneous schedule constraints

        //Sort tasks

        //Partition into days

        //Display tasks
    }

    cout << "Quitting [Software Name]" << endl;
    return 0;
}
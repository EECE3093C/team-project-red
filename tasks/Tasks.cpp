#include <string>
#include <iostream>
#include <vector>
#include "Tasks.hxx"


int main()
{
    Tasks task;
    std::string userInput;
    std::string userItem;
    std::string userPriority;
    std::string userDate;

    // Standard output that takes the individual things to do items from the User.
    // THINGS TO ADD HERE!!
        // 1. Check if the date is in the past or formated incorrectly (could use date datatype)
        // 2. Check the Priority is a valid priorty type
    std::cout << "Welcome to ____ (INSERT PRODUCT NAME HERE)! Insert your personal things to do list here. We will connect to Canvas to get your assignments and classwork. If you have personal things to do to enter, type Y, otherwise, type C \n";
    std::cin >> userInput;

    while (userInput == "Y" || userInput == "y")
    {
        std::cout << "Insert the name of your task as you would like it to appear on your things to do list. \n";
        std::cin >> userItem;
        std::cout << "Insert the priority of the task at hand using one of the following terms: high, medium, low \n";
        std::cin >> userPriority;
        std::cout << "Insert the due date of the task in the format DD-MM-YYYY \n";
        std::cin >> userDate;
        task.addTaskItem(userItem, userPriority, userDate);
        std::cout << "Have more items to add? If so, type Y. If you're done, type N \n";
        std::cin >> userInput;       
    }

    task.thingsToDoList();

    return 0;
}
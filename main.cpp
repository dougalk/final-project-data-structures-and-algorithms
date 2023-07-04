#include "LinkedList.h"
#include <iostream>

int main() 
{
    LinkedList TaskList;

    while (true) {
        std::cout << "Press 1 to add a Task, 2 to add a SubTask or any other key to quit: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string taskName, taskDescription, taskDueDate;
            int taskPriority;
            std::cout << "Enter task name: ";
            std::cin.ignore();
            std::getline(std::cin, taskName);
            std::cout << "Enter task description: ";
            std::getline(std::cin, taskDescription);
            std::cout << "Enter task due date (YYYY-MM-DD): ";
            std::getline(std::cin, taskDueDate);
            std::cout << "Enter task priority (integer): ";
            std::cin >> taskPriority;
            TaskList.addTask(taskName, taskDescription, taskDueDate, taskPriority);
        }
        else if (choice == 2) {

            //Ask for name of parent task
            std::string parentTaskName, subtaskName, subtaskDescription, subtaskDueDate;
            int subtaskPriority;
            std::cout << "Enter name of parent task: ";
            std::cin.ignore();
            std::getline(std::cin, parentTaskName);

            //check if parent task exists first, to avoid user wasting time inputting details
            Task* parentTask = TaskList.getTask(parentTaskName);
            if (parentTask) {
                // If parent task exists, you can now ask for subtask details
                std::string subtaskName, subtaskDescription, subtaskDueDate;
                int subtaskPriority;
                std::cout << "Enter subtask name: ";
                std::getline(std::cin, subtaskName);
                std::cout << "Enter subtask description: ";
                std::getline(std::cin, subtaskDescription);
                std::cout << "Enter subtask due date (YYYY-MM-DD): ";
                std::getline(std::cin, subtaskDueDate);
                std::cout << "Enter subtask priority (integer): ";
                std::cin >> subtaskPriority;
                parentTask->addSubTask(subtaskName, subtaskDescription, subtaskDueDate, subtaskPriority);
            }
            else {
                // If parent task doesn't exist, inform the user immediately
                std::cout << "Parent task not found. Try again with valid task name.";
            }
        }
        else {
            break;
        }
    }

    return 0;
}

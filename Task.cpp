#include "Task.h"
#include <iostream>

// Constructor
Task::Task(const std::string& name, const std::string& description,
           const std::string& dueDate, int priority)
           : name(name), description(description),
             dueDate(dueDate), priority(priority) {}

// Function to add subtasks
Task* Task::addSubTask(const std::string& name, 
                       const std::string& description,
                       const std::string& dueDate, 
                       int priority) {
    Task* newTask = new Task(name, description, dueDate, priority);
    subTasks.push_back(newTask);
    return newTask;
}

// Destructor to delete all subtasks when a task is destroyed and reallocate memory
Task::~Task() {
    for (Task* subTask : subTasks) {
        delete subTask;
    }
}

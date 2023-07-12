#include "Task.h"
#include <iostream>
#include <queue>

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

Task* Task::findSubTaskBFS(const std::string& name) {
    std::queue<Task*> searchQueue;
    searchQueue.push(this); // Start with the current task
    while (!searchQueue.empty()) {
        Task* currentTask = searchQueue.front();
        searchQueue.pop();
        // Check if the current task is the one we're looking for
        if (currentTask->getName() == name) {
            return currentTask;
        }
        // If not, add all its subtasks to the search queue
        for (Task* subTask : currentTask->subTasks) {
            searchQueue.push(subTask);
        }
    }
    // If we've gone through all tasks and subtasks and haven't found a match, return null
    return nullptr;
}



#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

class Task {
private:
    std::string name;
    std::string description;
    std::string dueDate;
    int priority;
    std::vector<Task*> subTasks; //This represents the subtrees/children of a Task node.

public:
    // Constructor
    Task(const std::string& name, const std::string& description,
         const std::string& dueDate, int priority);
    
    // Method to add subtask
    //In the addSubTask method, a new Task is created and its address is added to the subTasks vector, thus adding a new child node to the tree.
    Task* addSubTask(const std::string& name, 
                     const std::string& description,
                     const std::string& dueDate, 
                     int priority);
    
    // Getters
    std::string getName() { return name; }
    std::string getDescription() { return description; }
    std::string getDueDate() { return dueDate; }
    int getPriority() { return priority; }

    // Method to find subtask using BFS
    Task* findSubTaskBFS(const std::string& name);

    // Destructor
    ~Task();

    // ... Other necessary methods ...
};

#endif //TASK_H



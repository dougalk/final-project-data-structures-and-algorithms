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
    std::vector<Task*> subTasks;

public:
    // Constructor
    Task(const std::string& name, const std::string& description,
         const std::string& dueDate, int priority);
    
    // Method to add subtask
    Task* addSubTask(const std::string& name, 
                     const std::string& description,
                     const std::string& dueDate, 
                     int priority);
    
    // Getters
    std::string getName() { return name; }
    std::string getDescription() { return description; }
    std::string getDueDate() { return dueDate; }
    int getPriority() { return priority; }

    // Destructor
    ~Task();

    // ... Other necessary methods ...
};

#endif //TASK_H

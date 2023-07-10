#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Task.h"

class Node {
public:
    Task* task;
    Node* next;

    Node(Task* task): task(task), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    //Constructor
    LinkedList(): head(nullptr) {}
    //Destructor
    ~LinkedList();

    // Add a task at the start of the linked list
    Task* addTask(const std::string& name, 
                  const std::string& description,
                  const std::string& dueDate, 
                  int priority) {
        Task* newTask = new Task(name, description, dueDate, priority);
        Node* newNode = new Node(newTask);

        // If the list is not empty, set the new node's next pointer to the current head
        if (head != nullptr) {
            newNode->next = head;
        } 
        // Set the head to the new node
        head = newNode;

        return newTask;
    }

    //getTask declaration
    Task* getTask(const std::string& taskName);

    void displayAllTasks();

};

#endif //LINKED_LIST_H

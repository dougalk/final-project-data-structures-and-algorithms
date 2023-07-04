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

    // Add a task at the end of the linked list
    Task* addTask(const std::string& name, 
                  const std::string& description,
                  const std::string& dueDate, 
                  int priority) {
        Task* newTask = new Task(name, description, dueDate, priority);
        Node* newNode = new Node(newTask);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* tempNode = head;
            while (tempNode->next) {
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;
        }
        return newTask;
    }
    //getTask declaration
    Task* getTask(const std::string& taskName);

    // Add methods here to access and manipulate tasks in the list
};

#endif //LINKED_LIST_H

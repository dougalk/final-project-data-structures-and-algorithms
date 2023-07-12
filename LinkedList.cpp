#include "LinkedList.h"
#include <iostream>

LinkedList::~LinkedList() {
    Node* currentNode = head;
    while (currentNode) {
        Node* nodeToBeDeleted = currentNode;
        currentNode = currentNode->next;
        delete nodeToBeDeleted->task;
        delete nodeToBeDeleted;
    }
}

    //getTask method
Task* LinkedList::getTask(const std::string& taskName) {
    Node* currentNode = head;
    while(currentNode != nullptr) {
        if(currentNode->task->getName() == taskName) {
            return currentNode->task;
        }
        currentNode = currentNode->next;
    }
    return nullptr; // Return nullptr if task not found
}

//displayAllTasks method. Uses sequential traversal
void LinkedList::displayAllTasks() {
    Node* currentNode = head;
    while(currentNode != nullptr) {
        std::cout << "Task Name: " << currentNode->task->getName() << std::endl;
        std::cout << "\tTask Description: " << currentNode->task->getDescription() << std::endl;
        std::cout << "\tTask Due Date: " << currentNode->task->getDueDate() << std::endl;
        std::cout << "\tTask Priority: " << currentNode->task->getPriority() << std::endl;
        currentNode = currentNode->next;
        if (currentNode != nullptr) {
            std::cout << "------------------------------------------" << std::endl;
        }
    }
}


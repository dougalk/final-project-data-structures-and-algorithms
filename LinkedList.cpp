#include "LinkedList.h"

LinkedList::~LinkedList() {
    Node* currentNode = head;
    while (currentNode) {
        Node* nodeToBeDeleted = currentNode;
        currentNode = currentNode->next;

        delete nodeToBeDeleted->task;
        delete nodeToBeDeleted;
    }
}

    //getTask method. Uses Sequential Search Algorithm to search through LinkedList
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


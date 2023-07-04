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


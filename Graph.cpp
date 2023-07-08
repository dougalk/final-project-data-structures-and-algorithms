#include "Graph.h"
#include <iostream>

Graph::Graph() {}

//the adjacencyList member represents the adjacency list of the graph: keys are tasks and values are vectors containing all tasks that the key task depends on.


void Graph::addTask(Task* task) {
    adjacencyList[task];  // Adds the task to the adjacency list 
                          // but since it has no dependencies yet,
                          // its corresponding vector is empty.
}

void Graph::addDependency(Task* task1, Task* task2) {
    adjacencyList[task1].push_back(task2);
}

void Graph::displayDependencies(Task* task) {
    std::cout << task->getName() << " depends on: ";
    for (const auto& dependency : adjacencyList[task]) {
        std::cout << dependency->getName() << ", ";
    }
    std::cout << std::endl;
}

bool Graph::isDependent(Task* task1, Task* task2) {
    for (const auto& task : adjacencyList[task1]) {
        if (task == task2) {
            return true;
        }
    }
    return false;
}

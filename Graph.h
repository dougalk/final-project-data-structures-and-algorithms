#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include <set>
#include <stack>
#include "Task.h"

class Graph {
public:
    Graph();
    void addTask(Task* task);
    void addDependency(Task* task1, Task* task2);
    void displayDependencies(Task* task);
    bool isDependent(Task* task1, Task* task2);
    void displayAllTasksDependenciesDFS();

private:
    std::map<Task*, std::vector<Task*> > adjacencyList;
};

#endif

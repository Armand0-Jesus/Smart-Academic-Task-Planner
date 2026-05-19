#ifndef DEPENDENCYGRAPH_H
#define DEPENDENCYGRAPH_H

#include <iostream>
#include "TaskList.h"

using namespace std;

const int MAX_TASKS = 100;

class DependencyGraph {
private:
    int dependencies[MAX_TASKS][MAX_TASKS];
    int taskIds[MAX_TASKS];
    int taskCount;

    int findTaskIndex(int taskId) const;
    void addTaskIfNotExists(int taskId);
    bool hasPath(int startIndex, int targetIndex, bool visited[]) const;
    bool createsCycle(int prerequisiteId, int dependentId) const;

public:
    DependencyGraph();

    bool addDependency(int prerequisiteId, int dependentId, TaskList& taskList);
    bool canCompleteTask(int taskId, TaskList& taskList) const;
    void showMissingPrerequisites(int taskId, TaskList& taskList) const;
    void displayDependencies() const;

};

#endif

#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"

struct Node;

class TaskList {
private:
    Node* head;
    bool idExists(int id) const;

public:
    TaskList();
    ~TaskList();

    void createTask(const Task& task);
    void showTasks() const;
    Task* searchById(int id);
    bool deleteTask(int id);
};

#endif
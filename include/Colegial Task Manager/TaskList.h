#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"

struct Node;

class TaskList {
private:
    Node* head;
    
public:
    TaskList();
    ~TaskList();

    bool idExists(int id) const; // anadida
  
    void createTask(const Task& task);
    void addTask(const Task& task); // anadida
    void showTasks() const;
    void displayAll() const; // anadida
    Task* searchById(int id);
    bool deleteTask(int id);
    bool markCompleted(int id); // anadida
    bool Empty() const; // anadida
};

#endif





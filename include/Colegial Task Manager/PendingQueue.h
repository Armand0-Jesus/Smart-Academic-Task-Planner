#ifndef PENDINGQUEUE_H
#define PENDINGQUEUE_H

#include <iostream>
#include "Task.h"
using namespace std;

struct QueueNode;

class PendingQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    PendingQueue();
    ~PendingQueue();

    void enqueue(Task task);
    bool dequeue();
    void display() const;
    bool Empty() const;
};

#endif

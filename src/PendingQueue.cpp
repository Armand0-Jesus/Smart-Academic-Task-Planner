#include "PendingQueue.h"

#include <iostream>

using namespace std;
struct QueueNode {
    Task data;
    QueueNode* next;

    QueueNode(Task task) {
        data = task;
        next = nullptr;
    }
};

PendingQueue::PendingQueue() {
    front = nullptr;
    rear = nullptr;
}

PendingQueue::~PendingQueue() {
    while (front != nullptr) {
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        temp = nullptr;
    }

    rear = nullptr;
}

void PendingQueue::enqueue(Task task) {
    QueueNode* newNode = new QueueNode(task);

    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

bool PendingQueue::dequeue() {
    if (front == nullptr) {
        return false;
    }

    QueueNode* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    temp = nullptr;
    return true;
}

void PendingQueue::display() const {
    if (front == nullptr) {
        cout << "No hay tareas pendientes." << endl;
        return;
    }

    QueueNode* current = front;
    int number = 1;

    cout << "--- Tareas Pendientes ---" << endl;

    while (current != nullptr) {
        cout << number << ". [" << current->data.getId() << "] "
             << current->data.getTitle()
             << " | Prioridad: " << current->data.getPriorityText()
             << " | Fecha: " << current->data.getDueDate() << endl;

        current = current->next;
        number++;
    }
}

bool PendingQueue::Empty() const {
    return front == nullptr;
}


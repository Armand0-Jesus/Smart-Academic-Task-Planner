#include <iostream>
#include "TaskList.h"

using namespace std;

struct Node {
    Task data;
    Node* next;
};

TaskList::TaskList() : head(nullptr) {
}

TaskList::~TaskList() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
        temp = nullptr;
    }
}

bool TaskList::idExists(int id) const {
    Node* current = head;

    while (current != nullptr) {
        if (current->data.getId() == id) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void TaskList::createTask(const Task& task) {
    if (idExists(task.getId())) {
        cout << "ID already exists.\n";
        return;
    }

    Node* newNode = new Node{task, nullptr};

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    cout << "Task created succesfully!\n";
}

void TaskList::showTasks() const {
    cout << "--- SHOW ALL TASKS ---\n";

    if (head == nullptr) {
        cout << "No tasks are registered.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        current->data.display();
        cout << "--------------------------\n";
        current = current->next;
    }
}

Task* TaskList::searchById(int id) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data.getId() == id) {
            return &(current->data);
        }
        current = current->next;
    }

    return nullptr;
}

bool TaskList::deleteTask(int id) {
    if (head == nullptr) {
        return false;
    }

    if (head->data.getId() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;

    while (current->next != nullptr && current->next->data.getId() != id) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;

    return true;
}
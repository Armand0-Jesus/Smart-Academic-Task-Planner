#include "TaskList.h"

#include <iostream>

using namespace std;
struct Node {
    Task data;
    Node* next;

    Node(const Task& task) {
        data = task;
        next = nullptr;
    }
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

    head = nullptr;
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
        cout << "El ID ya existe.\n";
        return;
    }

    
    Node* newNode = new Node{task};

    
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

    cout << "La tarea se creo con exito!\n";
}

void TaskList::addTask(const Task& task) {
    createTask(task);
}

void TaskList::showTasks() const {
    cout << "--- Mostrar Todas las Tareas ---\n";

    if (head == nullptr) {
        cout << "Todavia no hay tareas registradas.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        current->data.display();
        cout << "--------------------------\n";
        current = current->next;
    }
}

void TaskList::displayAll() const {
    showTasks();
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
    temp = nullptr;

    return true;
}

bool TaskList::markCompleted(int id) {
    Task* task = searchById(id);

    if (task == nullptr) {
        return false;
    }

    task->setStatus("Completada");
    return true;
}

bool TaskList::Empty() const {
    return head == nullptr;
}


#include <iostream>
#include "TaskList.h"

using namespace std;
// estructura nodo
struct Node {
    Task data;
    Node* next;
};
// constructor de la clae
TaskList::TaskList() : head(nullptr) {
}
// destructor 
TaskList::~TaskList() {
    Node* current = head;
// recorre todita la lista y elimina nodos
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
        temp = nullptr;
    }
}
// funcin para ver si un id ya existe 
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
// funcion para crear nueva tarea 
void TaskList::createTask(const Task& task) {
    if (idExists(task.getId())) {
        cout << "ID already exists.\n";
        return;
    }
// se crea u un nuevo nodo
    Node* newNode = new Node{task, nullptr};
// lista vacia 
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }
// ultimo nodo apunta al nuevo
        current->next = newNode;
    }

    cout << "Task created succesfully!\n";
}
// veamos todas las tareas registradas 
void TaskList::showTasks() const {
    cout << "--- SHOW ALL TASKS ---\n";

    if (head == nullptr) {
        cout << "No tasks are registered.\n";
        return;
    }

    Node* current = head;
// recorre lista 
    while (current != nullptr) {
        current->data.display();
        cout << "--------------------------\n";
        current = current->next;
    }
}
// funcion para buscar tarea por el id 
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
// funcion para eliminar una tarea, true si si se elimino, false si no 
bool TaskList::deleteTask(int id) {
    if (head == nullptr) {
        return false;
    }
// si la tarea se elimio esta en el primer nodo 
    if (head->data.getId() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
// recorrer lista hasta encontrar el nodo que se quiere eliminar 
    while (current->next != nullptr && current->next->data.getId() != id) {
        current = current->next;
    }
// no hay id? FALSE
    if (current->next == nullptr) {
        return false;
    }
// se elimina el nodo 
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;

    return true;
}

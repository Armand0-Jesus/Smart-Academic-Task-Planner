#include "TaskList.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void TaskList::saveToFile(const string& filename) const {
    ofstream file(filename);

    if (!file) {
        cout << "ERROR: No se pudo abrir el archivo para guardar datos.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        file << current->data.getId() << "|"
             << current->data.getTitle() << "|"
             << current->data.getDescription() << "|"
             << current->data.getCourse() << "|"
             << current->data.getPriority() << "|"
             << current->data.getDueDate() << "|"
             << current->data.getStatus() << endl;

        current = current->next;
    }

    file.close();
    cout << "Los datos fueron guardados correctamente en el archivo 'task.txt'\n";
}

void TaskList::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cout << "AVISO: No se encontro un archivo previo guardado. Se comenzara en una lista vacia.\n";
        return;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        string idStr;
        string title;
        string description;
        string course;
        string priorityStr;
        string dueDate;
        string status;

        getline(ss, idStr, '|');
        getline(ss, title, '|');
        getline(ss, description, '|');
        getline(ss, course, '|');
        getline(ss, priorityStr, '|');
        getline(ss, dueDate, '|');
        getline(ss, status, '|');

        if (idStr.empty() || title.empty() || description.empty() ||
            course.empty() || priorityStr.empty() || dueDate.empty() || status.empty()) {
            cout << "AVISO: Hay informacion incompleta.\n";
            continue;
        }

        int id;
        int priority;

        try {
            id = stoi(idStr);
            priority = stoi(priorityStr);
        } catch (...) {
            cout << "AVISO: Hay informacion invalida.\n";
            continue;
        }

        if (priority < 1 || priority > 3) {
            cout << "AVISO: La prioridad de la tarea es invalida.\n";
            continue;
        }

        if (!idExists(id)) {
            Task task(id, title, description, course, priority, dueDate, status);
            createTask(task);
        }
    }

    file.close();
    cout << "Los datos fueron cargados correctamente desde el archivo 'task.txt'\n";
}

    
}


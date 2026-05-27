#include "ActionStack.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct ActionNode {
    string action;
    ActionNode* next;

    ActionNode(string action) {
        this->action = action;
        next = nullptr;
    }
};

ActionStack::ActionStack() {
    top = nullptr;
}

ActionStack::~ActionStack() {
    clear();
}

void DependencyGraph::clear() {
   while (top != nullptr) {
        ActionNode* temp = top;
        top = top->next;
        delete temp;
        temp = nullptr;
    }
}

void ActionStack::saveToFile(const string& filename) const {
    ofstream file(filename);

    if (!file) {
        cout << "ERROR: No se pudo abrir el archivo de historial para guardar.\n";
        return;
    }

    ActionNode* current = top;

    while (current != nullptr) {
        file << current->action << endl;
        current = current->next;
    }

    file.close();
    cout << "Historial guardado correctamente en '" << filename << "'.\n";
}

void ActionStack::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cout << "AVISO: No se encontro historial previo guardado.\n";
        return;
    }

    clear();

    const int MAX_ACTIONS = 1000;
    string actions[MAX_ACTIONS];
    string line;
    int count = 0;

    while (getline(file, line) && count < MAX_ACTIONS) {
        if (!line.empty()) {
            actions[count] = line;
            count++;
        }
    }

    for (int i = count - 1; i >= 0; i--) {
        push(actions[i]);
    }

    file.close();
    cout << "Historial cargado correctamente desde '" << filename << "'.\n";
}

void ActionStack::push(string action) {
    ActionNode* newNode = new ActionNode(action);
    newNode->next = top;
    top = newNode;
}

bool ActionStack::pop() {
    if (top == nullptr) {
        return false;
    }

    ActionNode* temp = top;
    top = top->next;
    delete temp;
    temp = nullptr;
    return true;
}

void ActionStack::display() const {
    if (top == nullptr) {
        cout << "No hay acciones en el historial." << endl;
        return;
    }

    ActionNode* current = top;
    int number = 1;

    cout << "--- HISTORIAL DE ACCIONES ---" << endl;

    while (current != nullptr) {
        cout << number << ". " << current->action << endl;
        current = current->next;
        number++;
    }
}

bool ActionStack::Empty() const {
    return top == nullptr;
}



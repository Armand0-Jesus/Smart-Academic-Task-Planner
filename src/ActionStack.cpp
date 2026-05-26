#include "ActionStack.h"

#include <iostream>
#include <string>

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
    while (top != nullptr) {
        ActionNode* temp = top;
        top = top->next;
        delete temp;
        temp = nullptr;
    }
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



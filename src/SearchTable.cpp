#include "SearchTable.h"

SearchTable::SearchTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

SearchTable::~SearchTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = table[i];

        while (current != nullptr) {
            HashNode* temp = current;
            current = current->next;
            delete temp;
            temp = nullptr;
        }
    }
}

int SearchTable::hashFunction(int key) const {
    if (key < 0) {
        key = key * -1;
    }

    return key % TABLE_SIZE;
}

void SearchTable::insert(int key, Task* taskPtr) {
    int index = hashFunction(key);

    HashNode* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            current->taskPtr = taskPtr;
            return;
        }

        current = current->next;
    }

    HashNode* newNode = new HashNode(key, taskPtr);
    newNode->next = table[index];
    table[index] = newNode;
}

Task* SearchTable::search(int key) const {
    int index = hashFunction(key);

    HashNode* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->taskPtr;
        }

        current = current->next;
    }

    return nullptr;
}

bool SearchTable::remove(int key) {
    int index = hashFunction(key);

    HashNode* current = table[index];
    HashNode* previous = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (previous == nullptr) {
                table[index] = current->next;
            }
            else {
                previous->next = current->next;
            }

            delete current;
            current = nullptr;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

void SearchTable::displayTable() const {
    cout << "--- Busqueda ---" << endl;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr) {
            cout << "Indice " << i << ": ";

            HashNode* current = table[i];

            while (current != nullptr) {
                cout << "[" << current->key << "] ";
                current = current->next;
            }

            cout << endl;
        }
    }
}

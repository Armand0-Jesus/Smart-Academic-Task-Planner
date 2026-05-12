#ifndef SEARCHTABLE_H
#define SEARCHTABLE_H

#include <iostream>
#include "Task.h"
using namespace std;

const int TABLE_SIZE = 101;

struct HashNode;

class SearchTable {
private:
    HashNode* table[TABLE_SIZE];

    int hashFunction(int key) const;

public:
    SearchTable();
    ~SearchTable();

    void insert(int key, Task* taskPtr);
    Task* search(int key) const;
    bool remove(int key);
    void displayTable() const;
};

#endif

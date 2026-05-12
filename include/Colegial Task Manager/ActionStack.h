#ifndef ACTIONSTACK_H
#define ACTIONSTACK_H

#include <iostream>
#include <string>
using namespace std;

struct ActionNode;

class ActionStack {
private:
    ActionNode* top;

public:
    ActionStack();
    ~ActionStack();

    void push(string action);
    bool pop();
    void display() const;
    bool Empty() const;
};

#endif

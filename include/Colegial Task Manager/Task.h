#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
private:
    int id;
    string title;
    string description;
    string course;
    int priority;
    string dueDate;
    string status;

public:
    Task();
    Task(int id, string title, string description, string course, int priority, string dueDate, string status);

    int getId() const;
    string getTitle() const;
    string getDescription() const;
    string getCourse() const;
    int getPriority() const;
    string getDueDate() const;
    string getStatus() const;

    void display() const;
};

#endif
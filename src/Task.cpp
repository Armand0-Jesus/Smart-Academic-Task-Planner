#include <iostream>
#include "Task.h"

using namespace std;

// contructor por defecto 
// se inician valores basicos 

Task::Task() : id(0), priority(3), status("Pending") {
}
// constructor con parametros 
Task::Task(int id, string title, string description, string course, int priority, string dueDate, string status) {
    this->id = id;
    this->title = title;
    this->description = description;
    this->course = course;
    this->priority = priority;
    this->dueDate = dueDate;
    this->status = status;
}
// getters para clase Task
int Task::getId() const {
    return id;
}

string Task::getTitle() const {
    return title;
}
 
string Task::getDescription() const {
    return description;
}

string Task::getCourse() const {
    return course;
}

int Task::getPriority() const {
    return priority;
}

string Task::getDueDate() const {
    return dueDate;
}

string Task::getStatus() const {
    return status;
}
// muestra en pantalla toda la info de la tarea 
void Task::display() const {
    cout << "[" << id << "] " << title << "\n";
    cout << "Course: " << course << "\n";
    cout << "Description: " << description << "\n";
    cout << "Priority: " << priority << "\n";
    cout << "Due Date: " << dueDate << "\n";
    cout << "Status: " << status << "\n";
}

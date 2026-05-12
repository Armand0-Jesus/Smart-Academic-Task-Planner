#include<iostream>
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

// getter para validacion de prioridad
string Task::getPriorityText() const {
    if (priority == 1) {
        return "Alta";
    }
    else if (priority == 2) {
        return "Media";
    }
    else if (priority == 3) {
        return "Baja";
    }
    else {
        return "Prioridad invalida";
    }
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

// setters para clase Task
void Task::setTitle(string title) {
    this->title = title;
}

void Task::setDescription(string description) {
    this->description = description;
}

void Task::setCourse(string course) {
    this->course = course;
}

void Task::setPriority(int priority) {
    this->priority = priority;
}

void Task::setDueDate(string dueDate) {
    this->dueDate = dueDate;
}

void Task::setStatus(string status) {
    this->status = status;
}

// muestra en pantalla toda la info de la tarea 
void Task::display() const {
    cout << "[" << id << "] " << title << "\n";
    cout << "Course: " << course << "\n";
    cout << "Description: " << description << "\n";
    cout << "Priority: " << getPriorityText() << "\n";
    cout << "Due Date: " << dueDate << "\n";
    cout << "Status: " << status << "\n";
}


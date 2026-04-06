#include <iostream>
#include "Task.h"

using namespace std;

// contructor por defecto 
// se iknician valores basicos 

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
// devuelve id
int Task::getId() const {
    return id;
}
// devuelve nombre de la tarea 
string Task::getTitle() const {
    return title;
}
// descripcion 
string Task::getDescription() const {
    return description;
}
// que curso pertenece la tarea 
string Task::getCourse() const {
    return course;
}
// devuleve prioridad 
int Task::getPriority() const {
    return priority;
}
// devuelve fecha de entrega 
string Task::getDueDate() const {
    return dueDate;
}
// devuelve estatus 
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

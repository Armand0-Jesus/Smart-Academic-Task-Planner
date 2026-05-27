#include "Task.h"
#include "TaskList.h"
#include "PendingQueue.h"
#include "ActionStack.h"
#include "SearchTable.h"
#include "DependencyGraph.h"

#include <cassert>
#include <iostream>
#include <cstdio>

using namespace std;

void testTaskCreation() {
    Task task(101, "Estudiar", "Repasar listas enlazadas", "COMP2501", 1, "2026-05-20", "Pendiente");

    assert(task.getId() == 101);
    assert(task.getTitle() == "Estudiar");
    assert(task.getCourse() == "COMP2501");
    assert(task.getPriority() == 1);
    assert(task.getStatus() == "Pendiente");
}

void testTaskListOperations() {
    TaskList list;

    Task task1(101, "Estudiar", "Repasar pilas y colas", "COMP2501", 1, "2026-05-20", "Pendiente");
    Task task2(102, "Proyecto", "Terminar planificador de tareas", "COMP3075", 2, "2026-06-01", "Pendiente");

    list.createTask(task1);
    list.createTask(task2);

    assert(list.idExists(101));
    assert(list.idExists(102));
    assert(!list.idExists(999));

    Task* found = list.searchById(101);
    assert(found != nullptr);
    assert(found->getTitle() == "Estudiar");

    bool deleted = list.deleteTask(102);
    assert(deleted);
    assert(!list.idExists(102));
}

void testSearchTable() {
    Task task(201, "Ensayo", "Escribir borrador", "INGL1111", 2, "2026-05-27", "Pendiente");

    SearchTable table;
    table.insert(task.getId(), &task);

    Task* found = table.search(201);
    assert(found != nullptr);
    assert(found->getTitle() == "Ensayo");

    assert(table.remove(201));
    assert(table.search(201) == nullptr);
}

void testFilePersistence() {
    TaskList list;

    Task task1(301, "Estudiar", "Repasar grafos", "COMP2501", 1, "2026-05-20", "Pendiente");
    Task task2(302, "Proyecto", "Terminar Hito 5", "COMP3075", 2, "2026-06-01", "Completada");

    list.createTask(task1);
    list.createTask(task2);

    list.saveToFile("test_tasks.txt");

    TaskList loadedList;
    loadedList.loadFromFile("test_tasks.txt");

    Task* found1 = loadedList.searchById(301);
    Task* found2 = loadedList.searchById(302);

    assert(found1 != nullptr);
    assert(found1->getTitle() == "Estudiar");
    assert(found1->getCourse() == "COMP2501");
    assert(found1->getStatus() == "Pendiente");

    assert(found2 != nullptr);
    assert(found2->getTitle() == "Proyecto");
    assert(found2->getStatus() == "Completada");

    remove("test_tasks.txt");
}

int main() {
    testTaskCreation();
    testTaskListOperations();
    testSearchTable();
    testFilePersistence();

    cout << "Todas las pruebas fueron completadas exitosamente!\n";
    return 0;
}
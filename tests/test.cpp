#include "Task.h"
#include "TaskList.h"
#include "PendingQueue.h"
#include "ActionStack.h"
#include "SearchTable.h"
#include "DependencyGraph.h"

#include <cassert>
#include <iostream>
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
    Task task(201, "Ensayo", "Escribir borrador", "INGL", 2, "2026-05-27", "Pendiente");

    SearchTable table;
    table.insert(task.getId(), &task);

    Task* found = table.search(201);
    assert(found != nullptr);
    assert(found->getTitle() == "Ensayo");

    assert(table.remove(201));
    assert(table.search(201) == nullptr);
}

int main() {
    testTaskCreation();
    testTaskListOperations();
    testSearchTable();

    cout << "Todas las pruebas fueron completadas exitosamente!\n";
    return 0;
}
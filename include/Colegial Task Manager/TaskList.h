/**
 * @file TaskList.h
 * @brief Defines la clase TaskList utilizando listas enlazadas.
 */

#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"

struct Node;

/**
 * @class TaskList
 * @brief Manages la conexion principal de tares utilizando listas enlazadas.
 */
class TaskList {
private:
    Node* head;
    
public:
    /**
     * @brief Creates una lista vacia para Task.
     */
    TaskList();

    /**
     * @brief Destructor para liberar memoria allocada.
     */
    ~TaskList();

    /**
     * @brief Revisa si una tarea ya existe.
     * @param id ID para buscar.
     * @return true si el ID existe, false sino.
     */
    bool idExists(int id) const; // anadida
    
     /**
     * @brief Anade nueva tarea a la lista enlazada.
     * @param task Tarea a agregar.
     */
    void createTask(const Task& task);

    /**
     * @brief Agrega tarea a la lista enlazada.
     * @param task Tarea a agregar.
     */
    void addTask(const Task& task); // anadida

    /**
     * @brief Muestra todas las tereas guardadas en la lista enlazada.
     */
    void showTasks() const;

    /**
     * @brief Muestra cada tarea que hay en la lista enlazada.
     */
    void displayAll() const; // anadida

    /**
     * @brief Busca una tarea por su ID.
     * @param id ID de la tarea a buscar.
     * @return Puntero a la tarea si se encuentra, nullptr sino.
     */
    Task* searchById(int id);

    /**
     * @brief Elimina una tarea de la lista enlazada.
     * @param id ID de la tarea a eliminar.
     * @return true si la tarea fue eliminada, false sino.
     */
    bool deleteTask(int id);

    /**
     * @brief Marca una tarea como completada.
     * @param id ID de la tarea a marcar como completada.
     * @return true si la tarea fue actualizada, false sino.
     */
    bool markCompleted(int id); // anadida

    /**
     * @brief Revisa si la lista de tareas está vacía.
     * @return true si la lista no tiene tareas, false sino.
     */
    bool Empty() const; // anadida
};

#endif





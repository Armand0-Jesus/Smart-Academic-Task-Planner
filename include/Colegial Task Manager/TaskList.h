/**
 * @file TaskList.h
 * @brief Define la clase TaskList utilizando listas enlazadas.
 */
#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"

struct Node;

class SearchTable;
class PendingQueue;

/**
 * @class TaskList
 * @brief Maneja la conexion principal de tares utilizando listas enlazadas.
 */
class TaskList {
private:
    Node* head;
    
public:
    /**
     * @brief Crea una lista vacia para Task.
     */
    TaskList();

    /**
     * @brief Destructor para liberar memoria allocada.
     */
    ~TaskList();

    /**
     * @brief Elimina todas las tareas almacenadas en la lista enlazada.
     */
    void clear();

    /**
     * @brief Reconstruye la tabla de busqueda (estructuras auxiliares) usando las tareas actuales.
     * 
     * @param searchTable Tabla hash que se va a reconstruir.
     * @param pendingQueue Cola de tareas pendientes que se va a reconstruir.
     */
    void rebuildSearchAndQueue(SearchTable& searchTable, PendingQueue& pendingQueue);

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
     * @brief Revisa si la lista de tareas esta vacía.
     * @return true si la lista no tiene tareas, false sino.
     */
    bool Empty() const; // anadida

    /**
     * @brief Guarda todas las tareas en un archivo txt (tasks.txt).
     *
     * @param filename Nombre del archivo donde se guardaran las tareas.
     */
    void saveToFile(const std::string& filename) const;

    /**
     * @brief Limpia la lista actual y agrega las tareas encontradas en tasks.txt.
     * 
     * @param filename Nombre del archivo desde donde se cargaran las tareas.
     */
    void loadFromFile(const std::string& filename);
};

#endif




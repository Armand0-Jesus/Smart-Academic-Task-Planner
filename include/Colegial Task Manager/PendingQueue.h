/**
 * @file PendingQueue.h
 * @brief Defines la clase PendingQueue para manejar tareas pendientes.
 */
#ifndef PENDINGQUEUE_H
#define PENDINGQUEUE_H

#include "Task.h"

struct QueueNode;

/**
 * @class PendingQueue
 * @brief Implementa una cola (queue) para manejar tareas pendientes.
 *
 * Pending queue guarda las tareas que esten todavia pendientes y 
 * procesandose en orden FIFO, significando que la primera tarea p
 * pendiente sera la primera en ser procesada.
 */
class PendingQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
     /**
     * @brief Crea una cola vacia de la tarea pendiente.
     */
    PendingQueue();

     /**
     * @brief Destruye la cola y su memoria alocada.
     */
    ~PendingQueue();

    void clear();

    /**
     * @brief Agrega una tarea pendiente a la parte trasera de la cola.
     * @param task Task objecto para agregar a la cola.
     */
    void enqueue(Task task);

    /**
     * @brief Elimina la tarea que este al tope de la cola.
     * @return true si la tarea fue removida, false sino.
     */
    bool dequeue();

    /**
     * @brief Muestra las tareas pendientes en el orden de cola.
     */
    void display() const;

    /**
     * @brief Revisa si la cola de tareas pendientes esta vacia.
     * @return true si la cola esta vacia, false sino.
     */
    bool Empty() const;
};

#endif

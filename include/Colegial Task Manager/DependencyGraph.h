/**
 * @file DependencyGraph.h
 * @brief Define la clase DependencyGraph para manejar dependencias entre tareas.
 */
#ifndef DEPENDENCYGRAPH_H
#define DEPENDENCYGRAPH_H

#include <iostream>
#include "TaskList.h"

/**
 * @brief Cantidad maxima de tareas que se pueden representar en el grafo.
 */
const int MAX_TASKS = 100;

/**
 * @class DependencyGraph
 * @brief Representa las dependencias entre tareas utilizando un grafo.
 *
 * El grafo se representa mediante una matriz de adyacencia, donde la conexion de
 * dos tareas indica que tienen una relación de dependencia.
 */
class DependencyGraph {
private:
    /**
     * @brief Matriz de adyacencia que almacena las dependencias entre las tareas.
     *
     * Puede significar que la tarea en la posicion j (segunda posicion) 
     * depndera de la tarea i (tarea en primera posicion).
     */
    int dependencies[MAX_TASKS][MAX_TASKS];

    /**
     * @brief Arreglo que guarda los IDs de las tareas registradas en el grafo.
     */
    int taskIds[MAX_TASKS];

    /**
     * @brief Cantidad actual de tareas registradas en el grafo.
     */
    int taskCount;

    /**
     * @brief Busca la posicion de la tarea dentro del arreglo de IDs.
     *
     * @param taskId ID de la tarea que se desea buscar.
     * @return Indice de la tarea si existe, -1 sino.
     */
    int findTaskIndex(int taskId) const;

    /**
     * @brief Agrega una tarea al grafo si todavia no existe.
     *
     * @param taskId ID de la tarea que se desea agergar.
     */
    void addTaskIfNotExists(int taskId);

    /**
     * @brief Verifica si existe un camino entre dos tareas en el grafo.
     *
     *
     * @param startIndex Indice desde donde empieza la busqueda.
     * @param targetIndex Indice de la tarea destino.
     * @param visited Arreglo que marca las tareas ya visitadas/pasadas durante la busqueda.
     * @return true si existe un camino hacia la tarea destino, false sino.
     */
    bool hasPath(int startIndex, int targetIndex, bool visited[]) const;

    /**
     * @brief Verifica si agregar una dependencia puede crear un ciclo en el grafo.
     *
     * Los ciclos ocurren cuando una tarea termina dependiendo directa o 
     * indirectmanete de si misma
     *
     * @param prerequisiteId ID de la tarea que debe completarse primero.
     * @param dependentId ID de la tarea que depende del prerrequisito.
     * @return true si la dependencia crea un ciclo, false sino.
     */
    bool createsCycle(int prerequisiteId, int dependentId) const;

public:
    /**
     * @brief Crea grafo de dependencias vacio.
     */
    DependencyGraph();

    /**
     * @brief Agrega la dependencia entre las dos tareas.
     *
     * La funcion tambien valida que ambas tareas existan, que la dependencia
     * no este duplicada, que la tarea no dependa de si misma y que no termine
     * creando un ciclo.
     *
     * @param prerequisiteId ID de la tarea que debe completarse primero.
     * @param dependentId ID de la tarea que depende del prerrequisito.
     * @param taskList Lista de tareas utilizada para validar que ambas tareas existen.
     * @return true si la dependencia fue agregada correctamente, false sino.
     */
    bool addDependency(int prerequisiteId, int dependentId, TaskList& taskList);

    /**
     * @brief Verifica si la tarea se puede completar.
     *
     * @param taskId ID de la tarea que se desea completar.
     * @param taskList Lista de tareas utilizada para revisar el estado de los prerrequisitos.
     * @return true si la tarea puede completarse, false sino.
     */
    bool canCompleteTask(int taskId, TaskList& taskList) const;

    /**
     * @brief Muestra los prerrequisitos que todavia faltan para completar.
     *
     * @param taskId ID de la tarea que se desea revisar.
     * @param taskList Lista de tareas utilizada para verificar estado de los prerrequisitos.
     */
    void showMissingPrerequisites(int taskId, TaskList& taskList) const;

    /**
     * @brief Muestra todas las dependencias que han sido registradas en el grafo.
     */
    void displayDependencies() const;

};

#endif

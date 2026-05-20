/**
 * @file SearchTable.h
 * @brief Define la clase SearchTable para busqueda eficiente de tareas.
 */
#ifndef SEARCHTABLE_H
#define SEARCHTABLE_H

#include <iostream>
#include "Task.h"
using namespace std;

const int TABLE_SIZE = 101;

struct HashNode;

/**
 * @class SearchTable
 * @brief Implementa una tabla hash para busqueda por ID.
 *
 * SearchTable ayuda al programa buscar tareas mas agilmente comparado a 
 * a una lista enlazada. Utiliza el ID de tarea como llave.
 */
class SearchTable {
private:
    HashNode* table[TABLE_SIZE];

    /**
     * @brief Calculates el indice hash para la tarea
     * @param id Task ID to hash.
     * @return Indice en la tabla hash.
     *
    int hashFunction(int key) const;

public:
     /**
     * @brief Crea una tabla vacia de busqueda.
     */
    SearchTable();

    /**
     * @brief Libera la memoria alocada en el heap.
     */
    ~SearchTable();

    /**
     * @brief Inserta una tarea a la tabla hash.
     * @param id ID de tarea usafa como llave
     * @param task Puntero a la tarea que se va a almacenar.
     */
    void insert(int key, Task* taskPtr);

     /**
     * @brief Busca una tarea por ID.
     * @param id ID de la tarea a buscar.
     * @return Puntero a la tarea si fue encontrada, nullptr sino.
     */
    Task* search(int key) const;

     /**
     * @brief Eliminar tarea de la tabla hash.
     * @param id ID de la tarea que se desea eliminar.
     * @return true si la tarea fue eliminada, false sino.
     */
    bool remove(int key);

     /**
     * @brief Muestra el contenido de la tabla hash.
     *
     */
    void displayTable() const;
};

#endif

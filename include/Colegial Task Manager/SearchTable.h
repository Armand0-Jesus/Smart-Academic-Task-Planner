/**
 * @file SearchTable.h
 * @brief Define la clase SearchTable para busqueda eficiente de tareas.
 */
#ifndef SEARCHTABLE_H
#define SEARCHTABLE_H

#include "Task.h"

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
     * @brief Calcula el indice hash para la tarea
     * @param key ID de la tarea que se convertira en indice.
     * @return Indice en la tabla hash.
     */
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
     * @brief Elimina todas las entradas de la tabla hash y deja todos los espacios de la tabla vacios.
     */
    void clear();

    /**
     * @brief Inserta una tarea a la tabla hash.
     * @param key ID de tarea usada como llave.
     * @param taskPtr Puntero a la tarea que se va a almacenar.
     */
    void insert(int key, Task* taskPtr);

    /**
     * @brief Busca una tarea por ID.
     * @param key ID de la tarea a buscar.
     * @return Puntero a la tarea si fue encontrada, nullptr sino.
     */
    Task* search(int key) const;

    /**
     * @brief Eliminar tarea de la tabla hash.
     * @param key ID de la tarea que se desea eliminar.
     * @return true si la tarea fue eliminada, false sino.
     */
    bool remove(int key);

    /**
     * @brief Muestra el contenido de la tabla hash.
     */
    void displayTable() const;
};

#endif

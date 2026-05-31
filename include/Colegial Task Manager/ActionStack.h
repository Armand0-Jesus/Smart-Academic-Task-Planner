/**
 * @file ActionStack.h
 * @brief Define la clase ActionStack para el historial de acciones
 */
#ifndef ACTIONSTACK_H
#define ACTIONSTACK_H

#include <string>

struct ActionNode;

/**
 * @class ActionStack
 * @brief Implementa una pila (stack) para el historial de acciones recientes
 *
 * La clase es usada para grabar eventos como la creacion,
 * eliminacion, busqueda o finalizacion de tareas.
 */
class ActionStack {
private:
    ActionNode* top;

public:
    /**
     * @brief Crea una pila vacia de acciones.
     */
    ActionStack();

    /**
     * @brief Destruye la memoria alocada que utilizaba el stack.
     */
    ~ActionStack();

    /**
     * @brief Elimina todas las acciones almacenadas en la pila.
     */
    void clear();

    /**
     * @brief Guarda el historial de acciones en un archivo de texto (history.txt).
     *
     * @param filename Nombre del archivo donde se guardara el historial.
     */
    void saveToFile(const std::string& filename) const;

    /**
     * @brief Limpia el historial actual antes de cargar las acciones el archivo history.txt.
     * 
     * @param filename Nombre del archivo desde donde se cargaran las acciones.
     */
    void loadFromFile(const std::string& filename);

    /**
     * @brief Agrega la nueva accion al tope de la pila.
     * @param action Descripcion de la accion realizada.
     */
    void push(std::string action);

    /**
     * @brief Remueve la accion mas reciente de la pila.
     * @return true si la accion fue removida, false sino.
     */
    bool pop();

    /**
     * @brief Muestra el historial de acciones en orden de nuevo a mas viejo.
     */
    void display() const;

    /**
     * @brief Revisa si ActionStack esta vacio.
     * @return true si la pila esta vacio, false sino.
     */
    bool Empty() const;
};

#endif

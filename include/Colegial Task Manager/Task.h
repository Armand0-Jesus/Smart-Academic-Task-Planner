/**
 * @file Task.h
 * @brief Define la clase Task usada para representar una tarea academica.
 */

#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

/**
 * @class Task
 * @brief Representa una tarea academica en el planificador academico
 *
 * Guarda toda la informacion basica relacionada con las tareas,
 * incluye ID, titulo, descripcion, curso, prioridad, fecha de vencimiento
 * y estado actual.
 */
class Task {
private:
    int id;
    string title;
    string description;
    string course;
    int priority;
    string dueDate;
    string status;

public:
    /**
     * @brief Constructor por defecto.
     */
    Task();

    /**
     * @brief Constructor parametrizado.
     *
     * Crea un objeto con toda la información requerida para la tarea.
     *
     * @param id Identifiacdor unico para la tarea.
     * @param title Titulo de la tarea.
     * @param description Descripcion corta de la tarea.
     * @param course Curso/Clase relacionada con la tarea.
     * @param priority Nivel de prioridad de la tarea.
     * @param dueDate Fecha de vencimiento de la tarea.
     * @param status Estado actual de la tarea.
     */
    Task(int id, string title, string description, string course, int priority, string dueDate, string status);

    /** 
     * @name Getters
     * @brief Funciones para acceder a atributos de tareas.
     * @{
     */

    int getId() const;
    string getTitle() const;
    string getDescription() const;
    string getCourse() const;
    int getPriority() const;
    string getDueDate() const;
    string getStatus() const;
    string getPriorityText() const;

    /** @}  */

    /** 
     * @name Setters
     * @brief Funciones para modificar atributos de tareas.
     * @{
     */

    void setTitle(string title);
    void setDescription(string description);
    void setCourse(string course);
    void setPriority(int priority);
    void setDueDate(string dueDate);
    void setStatus(string status);

    /** @}  */

    /**
     * @brief Muestra en pantalla la información de la tarea.
     */
    void display() const;
   
};

#endif

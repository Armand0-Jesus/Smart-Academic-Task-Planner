/**
 * @file Task.h
 * @brief Define la clase Task usada para representar una tarea academica.
 */
#ifndef TASK_H
#define TASK_H

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
    std::string title;
    std::string description;
    std::string course;
    int priority;
    std::string dueDate;
    std::string status;

public:
    /**
     * @brief Constructor por defecto.
     */
    Task();

    /**
     * @brief Constructor parametrizado.
     *
     * Crea un objeto con toda la informacion requerida para la tarea.
     *
     * @param id Identifiacdor unico para la tarea.
     * @param title Titulo de la tarea.
     * @param description Descripcion corta de la tarea.
     * @param course Curso/Clase relacionada con la tarea.
     * @param priority Nivel de prioridad de la tarea.
     * @param dueDate Fecha de vencimiento de la tarea.
     * @param status Estado actual de la tarea.
     */
    Task(int id, std::string title, std::string description, std::string course, int priority, std::string dueDate, std::string status);

    /** 
     * @name Getters
     * @brief Funciones para acceder a atributos de tareas.
     * @{
     */

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getCourse() const;
    int getPriority() const;
    std::string getDueDate() const;
    std::string getStatus() const;
    std::string getPriorityText() const;

    /** @}  */

    /** 
     * @name Setters
     * @brief Funciones para modificar atributos de tareas.
     * @{
     */

    void setTitle(std::string title);
    void setDescription(std::string description);
    void setCourse(std::string course);
    void setPriority(int priority);
    void setDueDate(std::string dueDate);
    void setStatus(std::string status);

    /** @}  */

    /**
     * @brief Muestra en pantalla la informacion de la tarea.
     */
    void display() const;
   
};

#endif

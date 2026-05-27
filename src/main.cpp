#include <iostream>
#include "TaskList.h"
#include "PendingQueue.h"
#include "ActionStack.h"
#include "SearchTable.h"
#include "DependencyGraph.h"

using namespace std;

int main() {
	TaskList taskList;
	ActionStack history;
	PendingQueue pendingQueue;
	SearchTable searchTable;
	DependencyGraph dependencyGraph;

	taskList.loadFromFile("tasks.txt");

	int option;

	// menu principal

	do {
		cout << "**************************************************************************************************" << endl;
		cout << "                                                                                                  " << endl;
		cout << "             ccccc          TTTTTTT         M M    M M                                            " << endl;
		cout << "            c                  T            M  M  M  M                                            " << endl;
		cout << "            c                  T            M   MM   M                                            " << endl;
		cout << "            c                  T            M        M                                            " << endl;
		cout << "             ccccc             T            M        M                                            " << endl;
		cout << "                                                                                                  " << endl;
		cout << "               \n*******Colegial Task Manager*******\n";
		cout << "1. Crear Tarea\n";
		cout << "2. Ensenar todas las tareas\n";
		cout << "3. Buscar tareas por ID\n";
		cout << "4. Eliminar Tarea\n";
		cout << "5. Marcar tarea como completada\n";
		cout << "6. Mostrar historial\n";
		cout << "7. Cola de Tareas pendientes\n";
		cout << "8. Procesar siguiente tarea pendiente\n";
		cout << "9. Mostrar tabla de busqueda\n";
		cout << "10. Añadir tarea dependiente\n";
		cout << "11. Verificar si una tarea puede ser completada\n";
		cout << "12. Mostrar dependencias\n";
		cout << "13. Guardar tarea en archivo\n";
		cout << "14. Cargar tarea existente del archivo\n";
		//cout << "15. Editar tarea\n"; // opciones futuras
		cout << "0. Exit\n";

		cout << "**************************************************************************************************" << endl;

		cout << "Seleccione una opcion: ";
		cin >> option;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ERROR: debe entrar una opcion numerica.\n";
			continue;
		}

		switch (option) {
		case 1: { // crea tarea
			int id, priority;
			string title, description, course, dueDate, status;

			cout << "Inserta el ID de Tarea: ";
			cin >> id;
			
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "ERROR: el ID debe ser un numero.\n";
				break;
			}

			if (id <= 0) {
				cout << "ERROR: el ID debe ser un numero mayor que 0.\n";
				break;
			}
			
			cin.ignore();

			// verifica si el ID existe
			if (taskList.idExists(id)) {
				cout << "El ID ya existe.\n";
				history.push("Se intento crear una tarea con un ID ya existente " + to_string(id));
				break;
			}

			cout << "Inserte el Titulo: ";
			getline(cin, title);

			cout << "Inserte la descripcion: ";
			getline(cin, description);

			cout << "Inserte el curso de la clase: ";
			getline(cin, course);

			do { // validacion
				cout << "Inserte la prioridad (1=Alta, 2=Media, 3=Baja): ";
				cin >> priority;
				
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "ERROR: la prioridad debe ser un numero.\n";
					priority = 0;
					continue;
				}

				if (priority < 1 || priority > 3) {
					cout << "EL numero de prioridad debe ser 1, 2, or 3.\n";
				}

			} while (priority < 1 || priority > 3);

			cin.ignore();

			cout << "Fecha de entrega (dd/mm/yyyy): ";
			getline(cin, dueDate);

			cout << "Inserte estatus de la Tarea (Pendiente, En Progreso, Completada): ";
			getline(cin, status);

			if (title.empty() || description.empty() || course.empty() || dueDate.empty() || status.empty()) {
				cout << "ERROR: ningun campo puede estar vacio.\n";
				history.push("Se intento crear una tarea con informacion vacia.");
				break;
			}

			if (dueDate.length() != 10 || dueDate[2] != '/' || dueDate[5] != '/') {
				cout << "ERROR: la fecha debe tener formato dd/mm/yyyy.\n";
				break;
			}

			if (status != "Pendiente" && status != "pendiente" && status != "PENDIENTE" &&
				status != "En Progreso" && status != "en progreso" && status != "EN PROGRESO" &&
				status != "Completada" && status != "completada" && status != "COMPLETADA") {
				cout << "ERROR: el estatus debe ser Pendiente, En Progreso o Completada.\n";
				break;
			}

			Task newTask(id, title, description, course, priority, dueDate, status);

			taskList.createTask(newTask);

			Task* taskPtr = taskList.searchById(id);

			if (taskPtr != nullptr) {
				searchTable.insert(id, taskPtr);
				history.push("Crea tarea con ID " + to_string(id));

				if (status == "Pendiente" || status == "pendiente" || status == "PENDIENTE") {
					pendingQueue.enqueue(*taskPtr);
					history.push("tarea anadida " + to_string(id) + " to pending queue");
				}
			}

			break;
		}

		case 2: // mostrar todas las tareas
			taskList.showTasks();
			history.push("Se mostraron todas las tareas");
			break;

		case 3: { // buscar tarea por el id
			int id;
			cout << "Inserte el ID de la tarea para buscarla: ";
			cin >> id;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "ERROR: el ID debe ser un numero.\n";
				break;
			}

			if (id <= 0) {
				cout << "ERROR: el ID debe ser mayor que 0.\n";
				break;
			}

			Task* found = searchTable.search(id);

			if (found != nullptr) { // la encontraste
				cout << "\nLa tarea fue encontrada usando la tabla de busqueda:" << endl;
				found->display();
				history.push("Tarea buscada con el ID " + to_string(id));
			}
			else {
				cout << "ERROR: La tarea no fue encontrada." << endl;
				history.push("Se intento buscar la tarea con el ID " + to_string(id));
			}

			break;
		}

		case 4: { // eliminar tareas
			int id;

			cout << "\n--- Tarea Eliminada ---" << endl;
			cout << "Inserta el ID de la tarea para ser eliminada: ";
			cin >> id;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "ERROR: el ID debe ser un numero.\n";
				break;
			}

			if (id <= 0) {
				cout << "ERROR: el ID debe ser mayor que 0.\n";
				break;
			}

			bool removedFromList = taskList.deleteTask(id);

			if (removedFromList) {
				searchTable.remove(id);
				cout << "La tarea fue eliminada con exito." << endl;
				history.push("Se elimino la tarea con ID " + to_string(id));
			}
			else {
				cout << "ERROR: La tarea no fue encontrada." << endl;
				history.push("Se intento eliminar una tarea con ID " + to_string(id));
			}

			break;
		}

		/*	case 5: { // marcar tarea como completada ; case 5 antiguo antes de anadir las validaciones
				int id;
				cout << "Inserte el ID de la tarea para marcar como completada: ";
				cin >> id;

				Task* found = searchTable.search(id);

				if (found != nullptr) {
					found->setStatus("Completada");
					cout << "La Tarea fue marcada como completada." << endl;
					history.push("La Tarea fue marcada " + to_string(id) + " como completada ");
				}
				else {
					cout << "La Tarea no fue encontrada." << endl;
					history.push("Se intento marcar una tarea " + to_string(id) + " como completada ");
				}

				break;
			} */

		case 5: { // marcar tarea como completada
			int id;

			cout << "Inserte el ID de la tarea para marcar como completada: ";
			cin >> id;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "ERROR: el ID debe ser un numero.\n";
				break;
			}

			if (id <= 0) {
				cout << "ERROR: el ID debe ser mayor que 0.\n";
				break;
			}

			Task* found = searchTable.search(id);

			if (found != nullptr) {
				if (dependencyGraph.canCompleteTask(id, taskList)) {
					found->setStatus("Completada");
					cout << "La tarea fue marcada como completada.\n";
					history.push("Tarea Marcada " + to_string(id) + " como completada");
				}
				else {
					cout << "ERROR: La tarea aun no puede ser completada.\n";
					dependencyGraph.showMissingPrerequisites(id, taskList);
					history.push("Se intento completar una tarea " + to_string(id) + " sin pre-requisitos");
				}
			}
			else {
				cout << "AVISO: La tarea no fue encontrada.\n";
				history.push("Se intento marcar tarea " + to_string(id) + " como completada");
			}

			break;
		}
		case 6: // ver historial
			history.display();
			break;

		case 7: // ver cola de tareas pendientes
			pendingQueue.display();
			history.push("La cola de Tareas pendientes fue vizualidada");
			break;

		case 8: // procesar proxima tarea pendiente
			if (pendingQueue.dequeue()) {
				cout << "La tarea pendiente fue procesada." << endl;
				history.push("Se porceso la siguiente tarea pendiente de la cola");
			}
			else {
				cout << "No hay tareas pendiente en la cola." << endl;
				history.push("Se intento procesar tareas pendientes en la cola");
			}

			break;

		case 9: // mostrar tabla hash
			searchTable.displayTable();
			history.push("Se visualizo la Tabla de busqueda");
			break;

		case 10: { // registrar dependencia
			int prerequisiteId, dependentId;

			cout << "Inserte el ID de la tarea de pre-requisito: ";
			cin >> prerequisiteId;

			cout << "Inserte el ID de la tarea dependiente: ";
			cin >> dependentId;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "ERROR: los IDs deben ser numeros.\n";
				break;
			}

			if (prerequisiteId <= 0 || dependentId <= 0) {
				cout << "ERROR: los IDs deben ser mayores que 0.\n";
				break;
			}

			if (prerequisiteId == dependentId) {
				cout << "ERROR: una tarea no puede depender de si misma.\n";
				break;
			}

			if (dependencyGraph.addDependency(prerequisiteId, dependentId, taskList)) {
				history.push("Se anadio depedencia: La tarea " + to_string(dependentId) + " depende de la Tarea " + to_string(prerequisiteId));
			}
			else {
				history.push(" El Intento para anadir una dependencia fue invalido");
			}

			break;
		}

		case 11: { // verificar si una tarea se puede completar
			int id;

			cout << "Inserte el ID de la tarea para verificar si puede ser completada: ";
			cin >> id;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "ERROR: el ID debe ser un numero.\n";
				break;
			}

			if (id <= 0) {
				cout << "ERROR: el ID debe ser mayor que 0.\n";
				break;
			}

			if (!taskList.idExists(id)) {
				cout << "AVISO: La tarea no fue encontrada.\n";
				break;
			}

			if (dependencyGraph.canCompleteTask(id, taskList)) {
				cout << "La tarea " << id << " puede ser completada.\n";
				cout << "Todos los pre-requisitos fueron completados.\n";
			}
			else {
				cout << "La tarea " << id << " no puede ser completada todavia.\n";
				dependencyGraph.showMissingPrerequisites(id, taskList);
			}

			history.push("Los pre-requisitos para una tarea fueron verificados " + to_string(id));

			break;
		}

		case 12: {
			dependencyGraph.displayDependencies();
			history.push("Visualizacion de dependencias entre tareas");
			break;
		}

		case 13:
			taskList.saveToFile("tasks.txt");
			history.push("Se guardaron las tareas en el archivo de texto");
			break;

		case 14:
			taskList.loadFromFile("tasks.txt");
			history.push("Se cargaron las tareas desde el archivo de texto");
			break;

		case 0: // cerrar el programa
			taskList.saveToFile("tasks.txt");
			cout << "Se guardaron los datos correctamente." << endl;
			cout << "Saliendo del programa..." << endl;
			break;

		default:
			cout << "Opcion invalida." << endl;
		}

	} while (option != 0);

	return 0;
}

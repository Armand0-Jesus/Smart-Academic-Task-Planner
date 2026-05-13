#include <iostream>
#include "TaskList.h"
#include "PendingQueue.h"
#include "ActionStack.h"
#include "SearchTable.h"

using namespace std;

int main() {
	TaskList taskList;
	ActionStack history;
	PendingQueue pendingQueue;
	SearchTable searchTable;

	int option;

	do {
		cout << "**************************************************************************************************" << endl;
		cout << "                                                                                                  " << endl;
		cout << "             ccccc          TTTTTTT         M M    M M                                            " << endl;
		cout << "            c                  T            M  M  M  M                                            " << endl;
		cout << "            c                  T            M   MM   M                                            " << endl;
		cout << "            c                  T            M        M                                            " << endl;
		cout << "             ccccc             T            M        M                                            " << endl;
		cout << "                                                                                                  " << endl;
		cout << "**************************************************************************************************" << endl;

		// menu principal del programa

		cout << "\n*******Colegial Task Manager*******\n";
		cout << "1. Crear Tarea\n";
		cout << "2. Ensenar todas las tareas\n";
		cout << "3. Buscar tareas por ID\n";
		cout << "4. Eliminatr Tareas\n";
		cout << "5. Marcar tarea como completada\n";
		cout << "6. Muestra el historial\n";
		cout << "7. Cola de Tareas pendientes\n";
		cout << "8. Procesar siguiente tarea pendiente\n";
		cout << "9. Muestra la tabla de busqueda\n";
		//cout << "10. Editar tarea\n"; // opciones futuras
		//cout << "11. Guardar tarea en archivo\n";
		//cout << "12. Cargar tarea existente del archivo\n";
		cout << "0. Exit\n";

		cout << "Escoge una opcion: ";
		cin >> option;

		switch (option) {
		case 1: { // crea tarea
			int id, priority;
			string title, description, course, dueDate, status;

			cout << "Inserta el ID de Tarea: ";
			cin >> id;
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

				if (priority < 1 || priority > 3) {
					cout << "Numero de prioridad de ser 1, 2, or 3.\n";
				}

			} while (priority < 1 || priority > 3);

			cin.ignore();

			cout << "Inserte fecha de entrega: ";
			getline(cin, dueDate);

			cout << "Inserte estatus: ";
			getline(cin, status);

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
			history.push("Se mostro todas las tareas");
			break;

		case 3: { // buscar tarea por el id
			int id;
			cout << "Inserte el ID de la tarea para buscarla: ";
			cin >> id;


			Task* found = searchTable.search(id);

			if (found != nullptr) { // la encontraste
				cout << "\nLa tarea fue encontrada usando la tabla de busqueda:" << endl;
				found->display();
				history.push("Tarea buscada con el ID " + to_string(id));
			}
			else {
				cout << "La tarea no fue encontrada." << endl;
				history.push("Se intento buscar la tarea con el ID " + to_string(id));
			}

			break;
		}

		case 4: { // eliminar tareas
			int id;

			cout << "\n--- Tarea Eliminada ---" << endl;
			cout << "Inserta el ID de la tarea para ser eliminada: ";
			cin >> id;

			bool removedFromList = taskList.deleteTask(id);

			if (removedFromList) {
				searchTable.remove(id);
				cout << "La tarea fue eliminada con exito." << endl;
				history.push("Se elimino la tarea con ID " + to_string(id));
			}
			else {
				cout << "La tarea no fue encontrada." << endl;
				history.push("Se intento eliminar una tarea con ID " + to_string(id));
			}

			break;
		}

		case 5: { // marcar tarea como completada
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

		case 0: // cerrar el programa
			cout << "Saliendo del programa..." << endl;
			break;

		default:
			cout << "Opcion invalida." << endl;
		}

	} while (option != 0);

	return 0;
}

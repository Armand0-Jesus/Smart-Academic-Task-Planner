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
		cout << "4. Delete Task\n";
		cout << "5. Mark Task as Completed\n";
		cout << "6. Show Action History\n";
		cout << "7. Show Pending Task Queue\n";
		cout << "8. Process Next Pending Task\n";
		cout << "9. Show Search Table\n";
		//cout << "10. Edit Task\n"; // opciones futuras
		//cout << "11. Save Task File\n";
		//cout << "12. Load Existing Task From File\n";
		cout << "0. Exit\n";

		cout << "Choose an option: ";
		cin >> option;

		switch (option) {
		case 1: { // crea tarea
			int id, priority;
			string title, description, course, dueDate, status;

			cout << "Enter task ID: ";
			cin >> id;
			cin.ignore();

			// verifica si el ID existe
			if (taskList.idExists(id)) {
				cout << "ID already exists.\n";
				history.push("Attempted to create task with repeated ID " + to_string(id));
				break;
			}

			cout << "Enter title: ";
			getline(cin, title);

			cout << "Enter description: ";
			getline(cin, description);

			cout << "Enter course: ";
			getline(cin, course);

			do { // validacion
				cout << "Enter priority (1=High, 2=Medium, 3=Low): ";
				cin >> priority;

				if (priority < 1 || priority > 3) {
					cout << "Priority must be 1, 2, or 3.\n";
				}

			} while (priority < 1 || priority > 3);

			cin.ignore();

			cout << "Enter due date: ";
			getline(cin, dueDate);

			cout << "Enter status: ";
			getline(cin, status);

			Task newTask(id, title, description, course, priority, dueDate, status);

			taskList.createTask(newTask);

			Task* taskPtr = taskList.searchById(id);

			if (taskPtr != nullptr) {
				searchTable.insert(id, taskPtr);
				history.push("Created task with ID " + to_string(id));

				if (status == "Pending" || status == "pending" || status == "PENDING") {
					pendingQueue.enqueue(*taskPtr);
					history.push("Added task " + to_string(id) + " to pending queue");
				}
			}

			break;
		}

		case 2: // mostrar todas las tareas
			taskList.showTasks();
			history.push("Showed all tasks");
			break;

		case 3: { // buscar tarea por el id
			int id;
			cout << "Enter task ID to search: ";
			cin >> id;


			Task* found = searchTable.search(id);

			if (found != nullptr) { // la encontraste
				cout << "\nTask found using search table:" << endl;
				found->display();
				history.push("Searched task with ID " + to_string(id));
			}
			else {
				cout << "Task not found." << endl;
				history.push("Attempted to search task with ID " + to_string(id));
			}

			break;
		}

		case 4: { // eliminar tareas
			int id;

			cout << "\n--- DELETE TASK ---" << endl;
			cout << "Enter task ID to delete: ";
			cin >> id;

			bool removedFromList = taskList.deleteTask(id);

			if (removedFromList) {
				searchTable.remove(id);
				cout << "Task deleted successfully." << endl;
				history.push("Deleted task with ID " + to_string(id));
			}
			else {
				cout << "Task not found." << endl;
				history.push("Attempted to delete task with ID " + to_string(id));
			}

			break;
		}

		case 5: { // marcar tarea como completada
			int id;
			cout << "Enter task ID to mark as completed: ";
			cin >> id;

			Task* found = searchTable.search(id);

			if (found != nullptr) {
				found->setStatus("Completed");
				cout << "Task marked as completed." << endl;
				history.push("Marked task " + to_string(id) + " as completed");
			}
			else {
				cout << "Task not found." << endl;
				history.push("Attempted to mark task " + to_string(id) + " as completed");
			}

			break;
		}

		case 6: // ver historial
			history.display();
			break;

		case 7: // ver cola de tareas pendientes
			pendingQueue.display();
			history.push("Viewed pending task queue");
			break;

		case 8: // procesar proxima tarea pendiente
			if (pendingQueue.dequeue()) {
				cout << "Next pending task was processed." << endl;
				history.push("Processed next pending task from queue");
			}
			else {
				cout << "No pending tasks in queue." << endl;
				history.push("Attempted to process pending queue");
			}

			break;

		case 9: // mostrar tabla hash
			searchTable.displayTable();
			history.push("Viewed search table");
			break;

		case 0: // cerrar el programa
			cout << "Exiting program..." << endl;
			break;

		default:
			cout << "Invalid option." << endl;
		}

	} while (option != 0);

	return 0;
}

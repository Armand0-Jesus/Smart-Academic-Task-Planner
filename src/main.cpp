#include <iostream>
#include "TaskList.h"

using namespace std;

int main () {
	TaskList taskList; //crea lista de las tareas
	int option; // la variable de seleccionar el menu

	do { // diseno encabezado prueba
		cout << "****************************************************************************************************" << endl;
		cout << "          ccc            TTTTTT          M M    M M                                                 " << endl;
		cout << "         c                  T            M   MM   M                                                 " << endl;
		cout << "         c                  T            M        M                                                 " << endl;
		cout << "          ccc               T            M        M                                                 " << endl;
		cout << "****************************************************************************************************" << endl;

		// menu 
		cout << "\n*******Colegial Task Manager*******\n";
		cout << "1. Create Task\n";
		cout << "2. Show all tasks\n";
		cout << "3. Search task by ID\n";
		cout << "4. Delete Task\n";
        //cout << "5. Edit Task\n"; (opciones futuras)
        //cout << "6. Save Task File\n";
        //cout << "7. Load Existing Task From File\n";
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

			cout << "Enter title: ";
			getline(cin, title);

			cout << "Enter description: ";
			getline(cin, description);

			cout << "Enter course: ";
			getline(cin, course);

			do { //validacion
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

			Task newTask(id, title, description, course, priority, dueDate, status); // creacion del objeto task 
			taskList.createTask(newTask);
			break;
		}

		case 2: // mostrar todas las opciones
			taskList.showTasks();
			break;

		case 3: { // buscar tarea por el id
			int id;
			cout << "Enter task ID to search: ";
			cin >> id;

			Task* found = taskList.searchById(id); // se busca la tarea en lista 
			if (found != nullptr) { // la encontraste 
				cout << "\nTask found:" << endl;
				found->display();
			} else {
				cout << "Task not found." << endl;
			}
			break;
		}

		case 4: { // eliminar tareas
			int id;
			cout << "Enter task ID to delete: ";
			cin >> id;

			if (taskList.deleteTask(id)) {
				cout << "Task deleted successfully." << endl;
			} else {
				cout << "Task not found." << endl;
			}
			break;
		}

		case 0: // salir o cerrar el programa 
			cout << "Exiting program..." << endl;
			break;

		default:
			cout << "Invalid option." << endl; // seccion invalida
		}

	} while (option != 0);

	return 0; // finalizacion 
}

    return 0;
}*/

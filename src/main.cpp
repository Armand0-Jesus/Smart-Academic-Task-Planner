#include <iostream>
#include "TaskList.h"

using namespace std;

int main () {
	TaskList taskList;
	int option;

	do {
		cout << "****************************************************************************************************" << endl;
		cout << "          ccc            TTTTTT          M M    M M                                                 " << endl;
		cout << "         c                  T            M   MM   M                                                 " << endl;
		cout << "         c                  T            M        M                                                 " << endl;
		cout << "          ccc               T            M        M                                                 " << endl;
		cout << "****************************************************************************************************" << endl;

		cout << "\n*******Colegial Task Manager*******\n";
		cout << "1. Create Task\n";
		cout << "2. Show all tasks\n";
		cout << "3. Search task by ID\n";
		cout << "4. Delete Task\n";
        //cout << "5. Edit Task\n";
        //cout << "6. Save Task File\n";
        //cout << "7. Load Existing Task From File\n";
		cout << "0. Exit\n";

		cout << "Choose an option: ";

		cin >> option;


		switch (option) {
		case 1: {
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

			do {
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
			break;
		}

		case 2:
			taskList.showTasks();
			break;

		case 3: {
			int id;
			cout << "Enter task ID to search: ";
			cin >> id;

			Task* found = taskList.searchById(id);
			if (found != nullptr) {
				cout << "\nTask found:" << endl;
				found->display();
			} else {
				cout << "Task not found." << endl;
			}
			break;
		}

		case 4: {
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

		case 0:
			cout << "Exiting program..." << endl;
			break;

		default:
			cout << "Invalid option." << endl;
		}

	} while (option != 0);

	return 0;
}

/*Como compilar
En terminal:


        switch (option) {
            case 1: {
                int id, priority;
                string title, description, course, dueDate, status;

                cin.ignore();

                cout << "Enter task ID: ";
                cin >> id;
                cin.ignore();

                cout << "Enter title: ";
                getline(cin, title);

                cout << "Enter description: ";
                getline(cin, description);

                cout << "Enter course: ";
                getline(cin, course);

                cout << "Enter priority: ";
                cin >> priority;
                cin.ignore();

                cout << "Enter due date: ";
                getline(cin, dueDate);

                cout << "Enter status: ";
                getline(cin, status);

                Task task(id, title, description, course, priority, dueDate, status);
                taskList.createTask(task);
                break;
            }

            case 2:
                taskList.showTasks();
                break;

            case 3: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;

                Task* found = taskList.searchById(id);
                if (found != nullptr) {
                    found->display();
                } else {
                    cout << "Task not found.\n";
                }
                break;
            }

            case 4: {
                int id;
                cout << "Enter ID to edit: ";
                cin >> id;

                if (taskList.editTask(id)) {
                    cout << "Task edited successfully.\n";
                } else {
                    cout << "Task not found.\n";
                }
                break;
            }

            case 5: {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;

                if (taskList.deleteTask(id)) {
                    cout << "Task deleted successfully.\n";
                } else {
                    cout << "Task not found.\n";
                }
                break;
            }

            case 6:
                taskList.saveToFile("tasks.txt");
                break;

            case 7:
                taskList.loadFromFile("tasks.txt");
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid option.\n";
        }

    } while (option != 0);

    return 0;
}*/
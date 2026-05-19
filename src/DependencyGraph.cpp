#include "DependencyGraph.h"

DependencyGraph::DependencyGraph() {
	taskCount = 0;

	for (int i = 0; i < MAX_TASKS; i++) {
		taskIds[i] = -1;

		for (int j = 0; j < MAX_TASKS; j++) {
			dependencies[i][j] = 0;
		}
	}
}

int DependencyGraph::findTaskIndex(int taskId) const {
	for (int i = 0; i < taskCount; i++) {
		if (taskIds[i] == taskId) {
			return i;
		}
	}

	return -1;
}

void DependencyGraph::addTaskIfNotExists(int taskId) {
	if (findTaskIndex(taskId) != -1) {
		return;
	}

	if (taskCount < MAX_TASKS) {
		taskIds[taskCount] = taskId;
		taskCount++;
	}
}

bool DependencyGraph::hasPath(int startIndex, int targetIndex, bool visited[]) const {
	if (startIndex == targetIndex) {
		return true;
	}

	visited[startIndex] = true;

	for (int i = 0; i < taskCount; i++) {
		if (dependencies[startIndex][i] == 1 && !visited[i]) {
			if (hasPath(i, targetIndex, visited)) {
				return true;
			}
		}
	}

	return false;
}

bool DependencyGraph::createsCycle(int prerequisiteId, int dependentId) const {
    int prerequisiteIndex = findTaskIndex(prerequisiteId);
    int dependentIndex = findTaskIndex(dependentId);

    if (prerequisiteIndex == -1 || dependentIndex == -1) {
        return false;
    }

    bool visited[MAX_TASKS];

    for (int i = 0; i < MAX_TASKS; i++) {
        visited[i] = false;
    }

    return hasPath(dependentIndex, prerequisiteIndex, visited);
}

bool DependencyGraph::addDependency(int prerequisiteId, int dependentId, TaskList& taskList) {

	if (prerequisiteId == dependentId) {
		cout << "La dependencia es invalida. La tarea no puede depender de si misma.\n";
		return false;
	}


	if (!taskList.idExists(prerequisiteId)) {
		cout << "La dependencia es Invalida. La tarea de pre-requisito no existe.\n";
		return false;
	}

	if (!taskList.idExists(dependentId)) {
		cout << "La Dependencia es Invalida. La tarea dependiente no existe.\n";
		return false;
	}


	addTaskIfNotExists(prerequisiteId);
	addTaskIfNotExists(dependentId);

	int prerequisiteIndex = findTaskIndex(prerequisiteId);
	int dependentIndex = findTaskIndex(dependentId);


	if (dependencies[prerequisiteIndex][dependentIndex] == 1) {
		cout << "la Dependencia es invalida. Esta dependencia ya existe.\n";
		return false;
	}


	if (createsCycle(prerequisiteId, dependentId)) {
		cout << "La Dependencia es invalida. Esta dependencia crea un ciclo basico.\n";
		return false;
	}


	dependencies[prerequisiteIndex][dependentIndex] = 1;

	cout << "La Dependencia fue anadida con exito.\n";
	cout << "Tarea " << dependentId << " ahora depende de la Tarea " << prerequisiteId << ".\n";

	return true;
}

bool DependencyGraph::canCompleteTask(int taskId, TaskList& taskList) const {
	int taskIndex = findTaskIndex(taskId);


	if (taskIndex == -1) {
		return true;
	}


	for (int i = 0; i < taskCount; i++) {
		if (dependencies[i][taskIndex] == 1) {
			Task* prerequisiteTask = taskList.searchById(taskIds[i]);

			if (prerequisiteTask == nullptr) {
				return false;
			}

			if (prerequisiteTask->getStatus() != "Completeda") {
				return false;
			}
		}
	}

	return true;
}

void DependencyGraph::showMissingPrerequisites(int taskId, TaskList& taskList) const {
	int taskIndex = findTaskIndex(taskId);

	if (taskIndex == -1) {
		cout << "Esta tarea no tiene pre-requisitos.\n";
		return;
	}

	bool missing = false;

	cout << "Faltan pre-requisitos para esta tarea " << taskId << ":\n";

	for (int i = 0; i < taskCount; i++) {
		if (dependencies[i][taskIndex] == 1) {
			Task* prerequisiteTask = taskList.searchById(taskIds[i]);

			if (prerequisiteTask != nullptr && prerequisiteTask->getStatus() != "Completada") {
				cout << "- Tarea " << taskIds[i] << " todavia no esta completada.\n";
				missing = true;
			}
		}
	}

	if (!missing) {
		cout << "Todos los pre-requisitos fueron completados.\n";
	}
}

void DependencyGraph::displayDependencies() const {
    bool hasDependencies = false;

    cout << "\n--- Dependencias entre tareas ---\n";

    for (int prerequisiteIndex = 0; prerequisiteIndex < taskCount; prerequisiteIndex++) {
        for (int dependentIndex = 0; dependentIndex < taskCount; dependentIndex++) {
            if (dependencies[prerequisiteIndex][dependentIndex] == 1) {
                cout << "Tarea " << taskIds[dependentIndex]
                     << " depende de la tarea "
                     << taskIds[prerequisiteIndex] << ".\n";

                hasDependencies = true;
            }
        }
    }

    if (!hasDependencies) {
        cout << "No hay dependencias registradas.\n";
    }
}


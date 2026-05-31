# Colegial Task Manager


## Table of Contents

1. [About The Project](#about-the-project)
   * [Built With](#built-with)
2. [Installation](#installation)
3. [Usage](#usage)


## About The Project

Colegial Task Manager is a terminal-based academic task planner built in C++. The project helps viabilize the
usage of data structures for real problems by showing how the system implements linked lists, stack, queues,
hash tables and graphs. The full program has over 14 features which all can help for managing and keeping track of your tasks in a efficient manner. 

The main operations of the task planner include:

* Creating academic tasks
* Showing all saved tasks
* Searching tasks by ID
* Editing current tasks
* Deleting tasks
* Marking tasks as completed
* Tracking and visualizing recent actions
* Managing pending tasks 
* Visualizing search tables
* Managing and visualizing task dependencies
* Validating and verifying task operations
* Saving and loading data to txt files

There are also additional features in the full project like unit tests and a data generator that exports reports!

## Built With

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)
![Doxygen](https://img.shields.io/badge/Doxygen-2C4AA8?style=for-the-badge&logo=doxygen&logoColor=white)
![GitHub Actions](https://img.shields.io/badge/GitHub%20Actions-2088FF?style=for-the-badge&logo=githubactions&logoColor=white)

## Installation

To get a hold of the project you can clone the repository: 

```bash
git clone https://github.com/Armand0-Jesus/Smart-Academic-Task-Planner.git
cd Smart-Academic-Task-Planner
```
You can install C++17 or a later version of the language for main running of the program.

## Usage

#### Verifying program correctness and compiling:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -Iinclude -I"include/Colegial Task Manager" -o task_planner
```

#### Running and using the main program with all the options:

```bash
./task_planner
```

#### Generating and viewing the documentation with Doxygen:

```bash
doxygen Doxyfile
open docs/html/index.html
```

#### Running unit tests:

First compile the project by including also test.cpp:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic tests/test.cpp src/Task.cpp src/TaskList.cpp src/PendingQueue.cpp src/ActionStack.cpp src/SearchTable.cpp src/DependencyGraph.cpp -Iinclude -I"include/Colegial Task Manager" -o test_runner
```

Then for running it:

```bash
./test_runner
```

After that you should see if you pass all the tests or not.

#### Using the data generator (A version of Java needs to be installed):

```bash
javac tools/DataGenerator.java
java -cp tools DataGenerator generated-data 25
```
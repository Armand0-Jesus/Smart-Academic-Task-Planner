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
* Deleting tasks
* Marking tasks as completed
* Tracking and visualizing recent actions
* Managing pending tasks 
* Visualizing search tables
* Managing and visualizing task dependencies
* Validating and verifying task operations
* Save and load data to txt files

## Built With

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
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

For verifying program correctness and compiling:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -Iinclude -I"include/Colegial Task Manager" -o task_planner
```

For running and using the main program with all the options:

```bash
./task_planner
```

For generating and viewing the documentation with Doxygen:

```bash
doxygen Doxyfile
open docs/html/index.html
```
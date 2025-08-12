Here’s a ** README.md** for a **To-Do List in C++** 

---

# 📝 To-Do List Application (C++)

A simple **command-line To-Do List** written in C++ that allows users to **add**, **view**, and **delete** tasks.
Perfect for practicing **vectors**, **functions**, and **basic file I/O** (optional) in C++.

---

## ✨ Features

* ➕ **Add** new tasks to your to-do list
* 📋 **View** all tasks with numbering
* ❌ **Delete** a specific task by its number
* 🔄 **Runs until you choose to exit**
* 🖥️ **Simple and clean console interface**

---

## 🗂 Project Structure

```
To-Do-List/
│
├── main.cpp        # Source code
├── README.md       # Documentation
└── LICENSE         # (Optional) License file
```

---

## ⚙️ How It Works

1. The program shows a **menu** with three main options:

   * Add Task
   * View Tasks
   * Delete Task
   * Exit Program
2. The user enters their choice.
3. The program performs the chosen operation:

   * **Add Task:** Prompts for a task description and adds it to a vector.
   * **View Tasks:** Displays all tasks with serial numbers.
   * **Delete Task:** Removes a task based on its number.
4. The menu is shown again until the user chooses to exit.

---

## 📦 Installation & Setup

1. **Clone this repository**

   ```bash
   git clone https://github.com/<your-username>/To-Do-List.git
   cd To-Do-List
   ```

2. **Compile the program**

   ```bash
   g++ main.cpp -o todo
   ```

3. **Run the program**

   ```bash
   ./todo
   ```

---

## 💻 Example Usage

```
====================
    TO-DO LIST APP
====================
1. Add Task
2. View Tasks
3. Delete Task
4. Exit
Enter your choice: 1
Enter the task: Buy groceries
Task added successfully!

====================
    TO-DO LIST APP
====================
1. Add Task
2. View Tasks
3. Delete Task
4. Exit
Enter your choice: 1
Enter the task: Complete C++ project
Task added successfully!

====================
    TO-DO LIST APP
====================
Enter your choice: 2
Your Tasks:
1. Buy groceries
2. Complete C++ project

====================
    TO-DO LIST APP
====================
Enter your choice: 3
Enter the task number to delete: 1
Task deleted successfully!

====================
    TO-DO LIST APP
====================
Enter your choice: 2
Your Tasks:
1. Complete C++ project

====================
    TO-DO LIST APP
====================
Enter your choice: 4
Goodbye!
```

---

## 🛠 Code Example

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addTask(vector<string> &tasks) {
    string task;
    cin.ignore();
    cout << "Enter the task: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
        return;
    }
    cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string> &tasks) {
    int index;
    cout << "Enter the task number to delete: ";
    cin >> index;
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully!\n";
    }
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "\n====================\n";
        cout << "    TO-DO LIST APP\n";
        cout << "====================\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: deleteTask(tasks); break;
            case 4: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
```

---

## 🎯 Learning Outcomes

By building this project, you will learn:

* 📚 **Vectors** to store and manage dynamic lists
* 🔄 **Loops** (`do-while`) for menu-based programs
* 🎛 **Switch-case** statements for multiple options
* 🖥 **String handling** in C++
* 🛠 **Basic CRUD operations** in a console app

---

## 📝 Possible Improvements

You can improve this program by:

* Adding **file saving/loading** so tasks persist after closing the program
* Adding **task completion status** (✅ done / ❌ pending)
* Allowing **task editing** instead of only deleting
* Adding **due dates** for tasks

---


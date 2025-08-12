#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks) {
    std::cout << "Enter task description: ";
    std::string desc;
    std::getline(std::cin, desc);
    tasks.push_back({desc, false});
    std::cout << "Task added.\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks found.\n";
        return;
    }
    std::cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] "
                  << tasks[i].description << "\n";
    }
}

void markCompleted(std::vector<Task>& tasks) {
    viewTasks(tasks);
    std::cout << "Enter task number to mark as completed: ";
    size_t num;
    std::cin >> num;
    std::cin.ignore();
    if (num < 1 || num > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }
    tasks[num - 1].completed = true;
    std::cout << "Task marked as completed.\n";
}

void removeTask(std::vector<Task>& tasks) {
    viewTasks(tasks);
    std::cout << "Enter task number to remove: ";
    size_t num;
    std::cin >> num;
    std::cin.ignore();
    if (num < 1 || num > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + num - 1);
    std::cout << "Task removed.\n";
}

int main() {
    std::vector<Task> tasks;
    int choice;
    while (true) {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: return 0;
            default: std::cout << "Invalid choice.\n";
        }
    }
}
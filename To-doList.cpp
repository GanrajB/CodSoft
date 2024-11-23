#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool isCompleted;

    Task(string description) {
        this->description = description;
        isCompleted = false;
    }

    void markCompleted() {
        isCompleted = true;
    }

    void displayTask() const {
        cout << description << " - " << (isCompleted ? "Completed" : "Pending") << endl;
    }
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        cout << "Task added successfully!" << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available!" << endl;
            return;
        }
        cout << "\nTo-Do List:\n";
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].markCompleted();
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDescription;
    int taskIndex;

    do {
        cout << "\nTo-Do List Manager:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskAsCompleted(taskIndex - 1);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex - 1); 
                break;
            case 5:
                cout << "Thanks for visiting!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

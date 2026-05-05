#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Task {
    string title;
    string subject;
    int priority;
};

struct Action {
    string type;
    Task task;
};

struct ComparePriority {
    bool operator()(Task a, Task b) {
        return a.priority < b.priority;
    }
};

class TaskManager {
private:
    queue<Task> normalTasks;
    priority_queue<Task, vector<Task>, ComparePriority> urgentTasks;
    stack<Action> actionHistory;
    vector<Task> allTasks;

public:
    void addTask() {
        Task t;

        cin.ignore();

        cout << "\nTask title: ";
        getline(cin, t.title);

        cout << "Subject: ";
        getline(cin, t.subject);

        cout << "Priority (1 = normal, 2/3 = urgent): ";
        cin >> t.priority;

        while (cin.fail() || t.priority < 1 || t.priority > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid priority. Enter 1, 2, or 3: ";
            cin >> t.priority;
        }

        if (t.priority == 1) {
            normalTasks.push(t);
            cout << "Queued as a normal task.\n";
        } else {
            urgentTasks.push(t);
            cout << "Queued as an urgent task.\n";
        }

        allTasks.push_back(t);
        actionHistory.push({"add", t});

        cout << "✓ Task added successfully.\n";
    }

    void processTask() {
        Task processed;
        string source;

        if (!urgentTasks.empty()) {
            processed = urgentTasks.top();
            urgentTasks.pop();
            source = "Priority Queue";
        } else if (!normalTasks.empty()) {
            processed = normalTasks.front();
            normalTasks.pop();
            source = "Normal Queue";
        } else {
            cout << "\n× No tasks to process.\n";
            return;
        }

        for (int i = allTasks.size() - 1; i >= 0; i--) {
            if (allTasks[i].title == processed.title &&
                allTasks[i].subject == processed.subject &&
                allTasks[i].priority == processed.priority) {
                allTasks.erase(allTasks.begin() + i);
                break;
            }
        }

        cout << "\n🗲 Processed task: " << processed.title
             << " | Subject: " << processed.subject
             << " | Priority: " << processed.priority
             << " | From: " << source << endl;

        actionHistory.push({"process", processed});
    }

    void undoLastAction() {
        if (actionHistory.empty()) {
            cout << "\nNo actions to undo.\n";
            return;
        }

        Action lastAction = actionHistory.top();
        actionHistory.pop();

        if (lastAction.type == "add") {
            for (int i = allTasks.size() - 1; i >= 0; i--) {
                if (allTasks[i].title == lastAction.task.title &&
                    allTasks[i].subject == lastAction.task.subject &&
                    allTasks[i].priority == lastAction.task.priority) {
                    allTasks.erase(allTasks.begin() + i);
                    break;
                }
            }

            cout << "\n↩ Undo successful: Added task removed.\n";
        } 
        else if (lastAction.type == "process") {
            allTasks.push_back(lastAction.task);

            if (lastAction.task.priority == 1) {
                normalTasks.push(lastAction.task);
            } else {
                urgentTasks.push(lastAction.task);
            }

            cout << "\nUndo successful: Processed task restored.\n";
        }
    }

    void displayAllTasks() {
        if (allTasks.empty()) {
            cout << "\nNo tasks available.\n";
            return;
        }

        cout << "\nAll Tasks:\n";
        for (int i = 0; i < allTasks.size(); i++) {
            cout << i + 1 << ". "
                 << allTasks[i].title << " | "
                 << allTasks[i].subject << " | Priority: "
                 << allTasks[i].priority << endl;
        }
    }

    void displayTasksRecursive(int index) {
        if (index >= allTasks.size()) {
            return;
        }

        cout << index + 1 << ". "
             << allTasks[index].title << " | "
             << allTasks[index].subject << " | Priority: "
             << allTasks[index].priority << endl;

        displayTasksRecursive(index + 1);
    }

    void displayRecursiveMenu() {
        if (allTasks.empty()) {
            cout << "\nNo tasks available.\n";
            return;
        }

        cout << "\nAll Tasks using Recursive Display:\n";
        displayTasksRecursive(0);
    }

    void searchTask() {
        if (allTasks.empty()) {
            cout << "\nNo tasks available.\n";
            return;
        }

        string keyword;
        bool found = false;

        cin.ignore();

        cout << "\nEnter task title to search: ";
        getline(cin, keyword);

        cout << "\nSearch Results:\n";

        for (int i = 0; i < allTasks.size(); i++) {
            if (allTasks[i].title.find(keyword) != string::npos) {
                cout << i + 1 << ". "
                     << allTasks[i].title << " | "
                     << allTasks[i].subject << " | Priority: "
                     << allTasks[i].priority << endl;

                found = true;
            }
        }

        if (!found) {
            cout << "No matching task found.\n";
        }
    }

    void sortTasksByPriority() {
        if (allTasks.empty()) {
            cout << "\nNo tasks available.\n";
            return;
        }

        sort(allTasks.begin(), allTasks.end(), [](Task a, Task b) {
            return a.priority > b.priority;
        });

        cout << "\nTasks sorted by priority successfully.\n";
    }
};

int main() {
    TaskManager manager;
    int choice;

    do {
        cout << "\n╔═════════════════════════════════════╗\n";
        cout << "          ✿ BarelyOnTime ✿            \n";
        cout << "   Academic Task Management System    \n";
        cout << "╚═════════════════════════════════════╝\n";

        cout << "\nChoose an option:\n";
        cout << "  [1] Add Task\n";
        cout << "  [2] Process Task\n";
        cout << "  [3] Undo Last Action\n";
        cout << "  [4] Display All Tasks\n";
        cout << "  [5] Display Recursively\n";
        cout << "  [6] Search Task\n";
        cout << "  [7] Sort by Priority\n";
        cout << "  [8] Exit\n";

        cout << "\n→ Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                manager.addTask();
                break;
            case 2:
                manager.processTask();
                break;
            case 3:
                manager.undoLastAction();
                break;
            case 4:
                manager.displayAllTasks();
                break;
            case 5:
                manager.displayRecursiveMenu();
                break;
            case 6:
                manager.searchTask();
                break;
            case 7:
                manager.sortTasksByPriority();
                break;
            case 8:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
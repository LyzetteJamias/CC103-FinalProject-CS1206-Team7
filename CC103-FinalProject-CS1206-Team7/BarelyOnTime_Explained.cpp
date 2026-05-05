/*
    LIBRARIES USED AND WHY:

    #include <iostream>
    - Used for input and output operations.
    - Allows us to use cin and cout to interact with the user.
    - Essential because our program is a text-based system.

    #include <queue>
    - Used to implement the Queue data structure.
    - We used queue for normal tasks because it follows FIFO
      (First In, First Out).
    - This ensures tasks are processed in the order they were added,
      making it fair and realistic for regular school tasks.

    #include <stack>
    - Used to implement the Stack data structure.
    - We used stack for the undo feature because it follows LIFO
      (Last In, First Out).
    - This means the most recent action is the first one undone,
      which is exactly how undo systems should work.

    #include <vector>
    - Used as a dynamic array to store all tasks.
    - We used vector because it allows easy traversal, searching,
      and sorting of tasks.
    - Unlike queue and stack, vector gives direct access to elements,
      making it ideal for display and search features.

    #include <string>
    - Used to handle text such as task titles and subjects.
    - Allows us to store and manipulate user input easily.

    #include <algorithm>
    - Provides built-in functions like sort().
    - We used this to sort tasks by priority efficiently.
    - It simplifies our code instead of writing our own sorting algorithm.
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    Task represents one academic task in the system.

    Each task has:
    - title: the name of the task
    - subject: the subject/course related to the task
    - priority: used to decide if the task is normal or urgent

    Priority meaning:
    1 = normal task
    2 = urgent task
    3 = very urgent task
*/
struct Task {
    string title;
    string subject;
    int priority;
};

/*
    Action is used for the undo feature.

    We need to remember:
    - what kind of action happened
    - what task was affected

    type can be:
    "add"     = user added a task
    "process" = user processed a task

    This allows the stack to know what action should be undone.
*/
struct Action {
    string type;
    Task task;
};

/*
    ComparePriority tells the priority_queue how to arrange tasks.

    In normal queue, tasks are handled first-come, first-served.
    In priority_queue, the task with the highest priority number should come first.

    Example:
    priority 3 will be processed before priority 2.
*/
struct ComparePriority {
    bool operator()(Task a, Task b) {
        return a.priority < b.priority;
    }
};

/*
    TaskManager contains the main logic of the program.

    This class is used to apply OOP.
    The data structures are private so they cannot be accessed directly outside the class.
    The public functions are used to control how the user interacts with the system.
*/
class TaskManager {
private:
    /*
        Queue is used for normal tasks.

        Queue follows FIFO:
        First In, First Out.

        This means the first normal task added will be the first normal task processed.
    */
    queue<Task> normalTasks;

    /*
        Priority Queue is used for urgent tasks.

        This makes sure higher priority tasks are processed before lower priority tasks.
        This is useful because urgent schoolwork should be handled first.
    */
    priority_queue<Task, vector<Task>, ComparePriority> urgentTasks;

    /*
        Stack is used for undo.

        Stack follows LIFO:
        Last In, First Out.

        This means the most recent action is the first one that can be undone.
    */
    stack<Action> actionHistory;

    /*
        Vector stores all current tasks.

        We use vector because it is easier to display, search, and sort tasks.
        Queue and priority_queue do not allow easy searching or sorting directly.
    */
    vector<Task> allTasks;

public:
    /*
        addTask() allows the user to enter a new task.

        The function asks for:
        - task title
        - subject
        - priority

        If priority is 1, the task goes to normalTasks.
        If priority is 2 or 3, the task goes to urgentTasks.

        The task is also stored in allTasks so it can be displayed, searched, and sorted.
        The action is saved in actionHistory so it can be undone later.
    */
    void addTask() {
        Task t;

        cin.ignore();

        cout << "\nTask title: ";
        getline(cin, t.title);

        cout << "Subject: ";
        getline(cin, t.subject);

        cout << "Priority (1 = normal, 2/3 = urgent): ";
        cin >> t.priority;

        /*
            This while loop is for input validation.

            If the user enters a letter or a number outside 1 to 3,
            the program asks again instead of accepting invalid input.
        */
        while (cin.fail() || t.priority < 1 || t.priority > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid priority. Enter 1, 2, or 3: ";
            cin >> t.priority;
        }

        /*
            This decides where the task should go.

            Normal tasks go to queue.
            Urgent tasks go to priority queue.
        */
        if (t.priority == 1) {
            normalTasks.push(t);
            cout << "Queued as a normal task.\n";
        } else {
            urgentTasks.push(t);
            cout << "Queued as an urgent task.\n";
        }

        allTasks.push_back(t);

        /*
            Save the add action to the stack.
            This makes undo possible.
        */
        actionHistory.push({"add", t});

        cout << "Task added successfully.\n";
    }

    /*
        processTask() handles the next task.

        The system checks urgentTasks first.
        This means urgent tasks are prioritized.

        If there are no urgent tasks, it checks normalTasks.
        If both are empty, there is nothing to process.
    */
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
            cout << "\nNo tasks to process.\n";
            return;
        }

        /*
            Since the task was processed, it should no longer appear
            in the list of current tasks.

            This loop searches for the processed task in allTasks
            and removes it from the vector.
        */
        for (int i = allTasks.size() - 1; i >= 0; i--) {
            if (allTasks[i].title == processed.title &&
                allTasks[i].subject == processed.subject &&
                allTasks[i].priority == processed.priority) {
                allTasks.erase(allTasks.begin() + i);
                break;
            }
        }

        cout << "\nProcessed task: " << processed.title
             << " | Subject: " << processed.subject
             << " | Priority: " << processed.priority
             << " | From: " << source << endl;

        /*
            Save the process action to the stack.
            If the user chooses undo, this task can be restored.
        */
        actionHistory.push({"process", processed});
    }

    /*
        undoLastAction() reverses the most recent action.

        It uses stack because stack follows LIFO.
        The most recent action is on top of the stack.

        If the last action was "add":
        - undo removes that task from allTasks

        If the last action was "process":
        - undo restores the processed task
    */
    void undoLastAction() {
        if (actionHistory.empty()) {
            cout << "\nNo actions to undo.\n";
            return;
        }

        Action lastAction = actionHistory.top();
        actionHistory.pop();

        if (lastAction.type == "add") {
            /*
                Undoing an added task means removing it from allTasks.
            */
            for (int i = allTasks.size() - 1; i >= 0; i--) {
                if (allTasks[i].title == lastAction.task.title &&
                    allTasks[i].subject == lastAction.task.subject &&
                    allTasks[i].priority == lastAction.task.priority) {
                    allTasks.erase(allTasks.begin() + i);
                    break;
                }
            }

            cout << "\nUndo successful: Added task removed.\n";
        } 
        else if (lastAction.type == "process") {
            /*
                Undoing a processed task means putting it back.

                It is added back to allTasks.
                It is also returned to either normalTasks or urgentTasks.
            */
            allTasks.push_back(lastAction.task);

            if (lastAction.task.priority == 1) {
                normalTasks.push(lastAction.task);
            } else {
                urgentTasks.push(lastAction.task);
            }

            cout << "\nUndo successful: Processed task restored.\n";
        }
    }

    /*
        displayAllTasks() shows all current tasks using iteration.

        Iteration means using a loop.
        In this case, we use a for loop to go through allTasks one by one.
    */
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

    /*
        displayTasksRecursive() shows tasks using recursion.

        Recursion means a function calls itself.

        The base case is:
        if index reaches the size of allTasks, the function stops.

        If not yet finished:
        - display the current task
        - call the same function again with index + 1
    */
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

    /*
        displayRecursiveMenu() starts the recursive display.

        We separate this from displayTasksRecursive()
        so the menu only needs to call one simple function.
    */
    void displayRecursiveMenu() {
        if (allTasks.empty()) {
            cout << "\nNo tasks available.\n";
            return;
        }

        cout << "\nAll Tasks using Recursive Display:\n";
        displayTasksRecursive(0);
    }

    /*
        searchTask() allows the user to search for a task title.

        It uses .find() so the user can search using partial words.

        Example:
        If the task is "coding assignment",
        searching "coding" will still find it.
    */
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

    /*
        sortTasksByPriority() sorts all current tasks.

        It uses sort() from the algorithm library.

        The lambda function tells sort() to arrange tasks
        from highest priority to lowest priority.
    */
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

    /*
        The do-while loop keeps showing the menu
        until the user chooses option 8 to exit.

        This is also an example of iteration.
    */
    do {
        cout << "\n======================================\n";
        cout << "            BarelyOnTime              \n";
        cout << "   Academic Task Management System    \n";
        cout << "======================================\n";

        cout << "\nChoose an option:\n";
        cout << "  [1] Add Task\n";
        cout << "  [2] Process Task\n";
        cout << "  [3] Undo Last Action\n";
        cout << "  [4] Display All Tasks\n";
        cout << "  [5] Display Recursively\n";
        cout << "  [6] Search Task\n";
        cout << "  [7] Sort by Priority\n";
        cout << "  [8] Exit\n";

        cout << "\n Enter choice: ";

        /*
            This handles invalid menu input.

            If the user enters letters instead of numbers,
            cin will fail.

            cin.clear() resets the error.
            cin.ignore() removes the invalid input.
            continue goes back to the menu.
        */
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
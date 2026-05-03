#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    Ito yung structure ng isang task.
    Example:
    title = "DSA Assignment"
    subject = "CC103"
    priority = 1 (normal), 2 or 3 (urgent)
*/
struct Task {
    string title;
    string subject;
    int priority;
};

/*
    Ginagamit ito ng priority queue para malaman
    kung alin yung mas mataas na priority.
    Mas mataas na number = mas uunahin.
*/
struct ComparePriority {
    bool operator()(Task a, Task b) {
        return a.priority < b.priority;
    }
};

class TaskManager {
private:
    queue<Task> normalTasks;      
    // EDGAR: dito napupunta yung normal tasks (FIFO)

    priority_queue<Task, vector<Task>, ComparePriority> urgentTasks; 
    // EDGAR: dito napupunta yung urgent tasks (highest priority first)

    stack<string> actionHistory;  
    // LANDER: dito sine-save yung actions for undo

    vector<Task> allTasks;        
    // LANDER: lahat ng tasks nandito para madaling i-display/search/sort

public:
    void addTask() {
       
    cin.ignore();                    

    Task t;                          
    cout << "\n  Task title   : ";
    getline(cin, t.title);

    cout << "  Subject      : ";
    getline(cin, t.subject);

    
    cout << "  Priority (1=normal, 2/3=urgent): ";
    cin >> t.priority;

    
    if (t.priority == 1) {
        normalTasks.push(t);          
        cout << "  Queued as a normal task.\n";
        
    } else {
        
        urgentTasks.push(t);         
        cout << "  Queued as an urgent task.\n";
        
    }

    allTasks.push_back(t);            

    actionHistory.push("Added task: " + t.title);

    cout << "  [OK] Task '" << t.title << "' added.\n";

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
       
        cout << "\n  No tasks to process.\n";
        return;
        
    }

    cout << "\n  [PROCESSED] '" << processed.title
         << "' | " << processed.subject
         << " | Priority: " << processed.priority
         << " | From: " << source << "\n";

    actionHistory.push("Processed task: " + processed.title);
}

    void undoLastAction() {
        /*
            LANDER TO DO:

            Function na ito yung undo feature.

            Steps:
            1. Check kung empty ang actionHistory.
            2. If empty → "No action to undo"
            3. If hindi:
               - ipakita yung last action (top)
               - tanggalin gamit pop()
            4. Mag-display ng message

            Reminder:
            Stack = LIFO (last in, first out)
        */
    }

    void displayAllTasks() {
        /*
            LANDER TO DO:

            Iterative display (loop).

            Steps:
            1. Check kung empty ang allTasks.
            2. If empty → "No tasks available"
            3. If hindi:
               - gumamit ng loop
               - i-display lahat ng tasks:
                 number, title, subject, priority

            Ito yung iterative part.
        */
    }

    void displayTasksRecursive(int index) {
        /*
            LANDER TO DO:

            Recursive display.

            Steps:
            1. Base case:
               if index >= allTasks.size() → stop (return)
            2. I-display yung current task
            3. Tawagin ulit sarili niya (index + 1)

            Example:
            0 → 1 → 2 → hanggang matapos
        */
    }

    void displayRecursiveMenu() {
        /*
            LANDER TO DO:

            Starter ng recursive function.

            Steps:
            1. Check kung empty ang allTasks.
            2. If empty → "No tasks available"
            3. If hindi:
               - mag-display ng title
               - tawagin displayTasksRecursive(0)

            Ito yung proof na may recursion kayo.
        */
    }

    void searchTask() {
        /*
            LANDER TO DO:

            Pang-search ng task.

            Steps:
            1. Humingi ng keyword sa user
            2. Loop through allTasks
            3. If match → i-display
            4. If walang nakita → "No matching task"

            Tip:
            Pwede gumamit ng .find()
        */
    }

    void sortTasksByPriority() {
        /*
            LANDER TO DO:

            Pang-sort ng tasks.

            Steps:
            1. Check kung empty ang allTasks
            2. If empty → "No tasks available"
            3. Gumamit ng sort()
            4. Ayusin from highest to lowest priority
            5. Display success message

            Ito yung sorting requirement niyo.
        */
    }
};

int main() {
    TaskManager manager;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << " BarelyOnTime: Academic Task System\n";
        cout << "====================================\n";
        cout << "1. Add Task\n";
        cout << "2. Process Task\n";
        cout << "3. Undo Last Action\n";
        cout << "4. Display All Tasks\n";
        cout << "5. Display Tasks Recursively\n";
        cout << "6. Search Task\n";
        cout << "7. Sort Tasks by Priority\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addTask(); break;
            case 2: manager.processTask(); break;
            case 3: manager.undoLastAction(); break;
            case 4: manager.displayAllTasks(); break;
            case 5: manager.displayRecursiveMenu(); break;
            case 6: manager.searchTask(); break;
            case 7: manager.sortTasksByPriority(); break;
            case 8: cout << "\nExiting program. Goodbye!\n"; break;
            default: cout << "\nInvalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}

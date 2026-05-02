<h1 align="center"> 🌿•₊✧ BarelyOnTime: Academic Task Management System •₊✧ 💻 </h1>
✦·┈๑⋅⋯ ⋯⋅๑┈·✦✦·┈๑⋅⋯ ⋯⋅๑┈·✦✦·┈๑⋅⋯ ⋯⋅๑┈·✦✦·┈๑⋅⋯ ⋯⋅๑┈·✦✦·┈๑⋅⋯ ⋯⋅๑┈·✦✦·┈๑⋅⋯ ⋯⋅๑┈·✦✦·┈๑⋅⋯ ⋯⋅๑┈·✦✦·┈๑⋅⋯ ⋯⋅๑┈·✦

<h2 align="center"> ⤷ ゛Description ᝰ✍🏻 .ᐟ </h2>

Students often struggle to manage multiple academic tasks with different deadlines and levels of urgency. Because of this, important requirements may be delayed, overlooked, or forgotten. This project aims to solve that problem by creating a system that organizes tasks based on priority and order.

___

## ⤷ ゛Data Structures Used ˎˊ˗

### Stack 📚
A stack data structure is implemented to support the undo functionality of the system. It follows the Last In, First Out (LIFO) principle, which ensures that the most recent action performed by the user is the first to be reversed. This approach is appropriate for undo operations, as it maintains the correct sequence of action reversal.

### Queue ⌛
A queue is used to manage normal academic tasks. It operates based on the First In, First Out (FIFO) principle, ensuring that tasks are processed in the exact order in which they are received. This structure is suitable for handling regular tasks that do not require prioritization.

### Priority Queue 🚀
A priority queue is utilized for handling urgent academic tasks. Unlike a standard queue, this structure allows tasks with higher priority levels to be processed before those with lower priority. This ensures that critical or time-sensitive tasks are addressed promptly, improving the overall efficiency of the system.

___
## Problem Description 🧩🤔
Students Often struggle to manage multiple academic tasks with different deadlines and
levels of urgency. 

Because of this, important requirements may be delayed or forgotten.

This project aims to develop a system that organizes regular and urgent school tasks
efficiently while allowing users to undo recent actions.

___

###  ⤷ ゛Algorithm 💻 ˎˊ˗
The user will see a list of options at the start of the program. When the user adds a task,
the system will ask for the task details and determine whether it is a regular or urgent
task.

Regular tasks will be stored in a queue, while urgent tasks will be stored in a
priority queue. Each action performed by the user will also be saved in a stack so that the
most recent action can be undone if needed.

The program will use iteration in the menu
system, task display, and task processing through loops. It will also use recursion for at
least one feature, such as recursively displaying tasks or counting the remaining tasks in
the system.


## ⚙️ Algorithm Explanation
 
- 🖥️ Program launches with a **menu-driven interface**
- ➕ User adds a task → system routes it:
   - **Regular** → Queue | **Urgent** → Priority Queue
-  💾 Every action is **pushed onto the Stack** for undo support
- ⏭️ **Process Task** dequeues the next task in line
- 🔁 **Undo** pops the most recent action from the Stack
- 🔢 **Recursion** is used for displaying or counting remaining tasks
- 🔄 Menu loop **iterates** until the user exits

___

### ⤷ ゛Stack  📚 •₊✧
- **• What it is**:  A linear data structure that follows the Last-In, First-Out (LIFO) principle — the last element added is the first one to be removed.

- **• Why we used it**:  Perfect for the Undo feature. Since the most recent action should be reversed first, LIFO behavior fits naturally. Every action the user performs is pushed onto the stack, and undoing simply pops the top.
___
### ⤷ ゛ Queue  🚶🚶🚶
- **• What it is**:  A linear data structure that follows the First-In, First-Out (FIFO) principle — the first element added is the first one to be removed.

- **• Why we used it**:  Used to store regular academic tasks (assignments, quizzes, etc.). FIFO ensures tasks are processed in the order they were added, simulating a fair, first-come, first-served workflow.
___
### ⤷ ゛ Priority Queue 🚨⭐ˎˊ˗
- **• What it is**:  A special type of queue where each element has a priority level. Higher-priority elements are dequeued before lower-priority ones, regardless of insertion order.

- **• Why we used it**:  Used to store urgent academic tasks. This allows critical deadlines to be handled before regular ones, ensuring nothing important is missed.
___


## ⤷ ゛  👥 Team Members •₊✧
 
| SR-Code | Name | Role |
|---|---|---|
 25-07796 | **Edgar Mathew H. Corpuz** | 💻 Programmer, Logic Design, Documentation 
 25-06248 | **Lyzette A. Jamias** | 🎨 Programmer, System Design, Documentation 
 25-09661 | **Rein Lander B. Juanites** | 🐛 Programmer, Testing, Debugging 


##  🙏   Acknowledgement .ᐟ
We would like to express our sincere gratitude to our professor and the College of Informatics and Computing Sciences of Batangas State University  Alangilan Campus for the guidance and support throughout this project.

And of course, thank you to caffeine ☕  the true HERO of every late-night coding session.🤔

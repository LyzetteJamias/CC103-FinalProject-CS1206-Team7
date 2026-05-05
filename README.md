<h1 align="center"> 🌿•₊✧ BarelyOnTime: Academic Task Management System •₊✧ 💻 </h1>

<b align="center">
A simple academic task management system designed to help students organize, prioritize, and track their school requirements efficiently.
</b>

___

## ⤷ ゛Description ᝰ✍🏻 .ᐟ

Students often struggle to manage multiple academic tasks with different deadlines and levels of urgency. Because of this, important requirements may be delayed, overlooked, or forgotten. This project aims to solve that problem by creating a system that organizes tasks based on priority and order.

___

## ‧˚꒰📊꒱ Data Structures Used ₊˚⋆

### ⤷ ゛Stack  📚
- <b> What it is: </b>  A linear data structure that follows the Last-In, First-Out (LIFO) principle — the last element added is the first one to be removed.

- <b> Why we used it: </b>  Perfect for the Undo feature. Since the most recent action should be reversed first, LIFO behavior fits naturally. Every action the user performs is pushed onto the stack, and undoing simply pops the top.
___
### ⤷ ゛ Queue  🚶🚶🚶
- <b> What it is: </b>   A linear data structure that follows the First-In, First-Out (FIFO) principle — the first element added is the first one to be removed.

- <b> Why we used it: </b>  Used to store regular academic tasks (assignments, quizzes, etc.). FIFO ensures tasks are processed in the order they were added, simulating a fair, first-come, first-served workflow.
___
### ⤷ ゛ Priority Queue 🚨⭐ˎˊ˗
- <b> What it is: </b>  A special type of queue where each element has a priority level. Higher-priority elements are dequeued before lower-priority ones, regardless of insertion order.

- <b> Why we used it: </b>  Used to store urgent academic tasks. This allows critical deadlines to be handled before regular ones, ensuring nothing important is missed.
___
## ‧˚꒰💻꒱ Algorithm ˎˊ˗
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


## ⤷ ゛Algorithm Explanation ⚙️
 
- 🖥️ Program launches with a **menu-driven interface**
- ➕ User adds a task → system routes it:
   - **Regular** → Queue | **Urgent** → Priority Queue
-  💾 Every action is **pushed onto the Stack** for undo support
- ⏭️ **Process Task** dequeues the next task in line
- 🔁 **Undo** pops the most recent action from the Stack
- 🔢 **Recursion** is used for displaying or counting remaining tasks
- 🔄 Menu loop **iterates** until the user exits

___

## 𐔌 . ⋮ Iterative vs Recursive Comparison .ᐟ ֹ ₊ ꒱
 
BarelyOnTime uses **both** approaches — iteration for the core program flow and recursion as a deliberate feature for task display and counting.
 
### Which is faster?
 
| Feature | Approach | Why |
|---|---|---|
| Menu loop | Iterative | Constant O(1) space, no call overhead |
| Task processing | Iterative | Sequential, predictable, O(n) time O(1) space |
| Display all tasks | Recursive | O(n) time, O(n) space (call stack) |
| Count tasks | Recursive | O(n) time, O(n) space (call stack) |
 
**Iterative is faster** in terms of raw performance. It uses O(1) space since no additional stack frames are created. Recursive calls, while elegant, each add a new frame to the call stack — making it O(n) in space. For typical student task counts (under 100 items), this difference is negligible, but iterative wins on efficiency.
 
### Which is easier to understand?
 
**Recursion is easier to read** for naturally self-similar problems like displaying a list or counting elements — the logic maps almost directly to its mathematical definition:
 
```
countTasks(queue):
  if queue is empty → return 0
  else → return 1 + countTasks(rest of queue)
```
 
**Iteration is easier to trace** step by step when debugging, since you can watch variable values change in a single execution context. For the menu system and queue processing, iterative code is more straightforward and less error-prone.
 
**Summary:** Iterative = faster and safer. Recursive = more elegant and readable for display/count features. BarelyOnTime uses each where it fits best.

---

## ⤷ ゛ Design Decisions 💭
 
###  Using three separate data structures (Stack + Queue + Priority Queue)
 
**Decision:** Instead of using a single list for all tasks, we separated regular tasks, urgent tasks, and the undo history into three distinct structures.
 
**Trade-off:** This adds complexity in managing three structures simultaneously, but it leads to more correct behavior. A single list would require manual sorting every time a task is added; the Priority Queue handles urgency automatically and efficiently.
 
---
## ⤷ ゛👥 Team Members •₊✧
 
| SR-Code | Name | Role |
|---|---|---|
 25-07796 | **Edgar Mathew H. Corpuz** | 💻 Programmer, Logic Design, Documentation 
 25-06248 | **Lyzette A. Jamias** | 🎨 Programmer, System Design, Documentation 
 25-09661 | **Rein Lander B. Juanites** | 🐛 Programmer, Testing, Debugging 


##  💛 Heartfelt Acknowledgement .ᐟ
We would like to express our sincere gratitude to our professor for the guidance, patience, and continuous support throughout the development of this project. The lessons and feedback given in class helped us better understand how to apply data structures beyond theory and into something practical.

This project was not without its challenges. As a group, we experienced different difficulties, including limited access to devices for some members and the struggle of managing time alongside other academic responsibilities. Despite this, we did our best to support one another and find ways to continue working on the project.

Through this experience, we learned not only about programming, but also about teamwork, communication, and responsibility. It taught us the importance of stepping up when needed, being patient with each other, and finding solutions even when resources are limited.

Lastly, we would like to thank ourselves as a team for pushing through the stress, adjustments, and late nights to complete this project.

And of course, a small thank you to caffeine ☕ for helping us stay awake when we needed it most.

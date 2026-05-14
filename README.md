## TaskManager-C
A simple C-based console task manager that lets you add, view, edit, and delete tasks stored in a text file.

## Objective
A small console‑based program to manage daily tasks.  
You can add, view, edit, and delete tasks, all stored in a text file (`myfile.txt`).

## Features
- Add a new task
- View all tasks
- Edit an existing task
- Delete a task
- Clear all tasks (exit option)

## Approach
1. **File Handling:** Tasks are saved in `myfile.txt` so they persist between runs.  
2. **Menu System:** A simple menu lets you choose actions (Add, View, Edit, Delete, Exit).  
3. **Functions:** Each action is handled by its own function (`addtask`, `viewtask`, `editTask`, `deleteTask`, `clearfile`).  
4. **Data Structures:** Tasks are stored in arrays and updated in the file when edited or deleted.

## Results & Insights
- Easy way to keep track of tasks directly from the terminal.  
- File handling ensures tasks are not lost when the program ends.  
- Edit and delete options make it flexible like a mini to‑do list app.  

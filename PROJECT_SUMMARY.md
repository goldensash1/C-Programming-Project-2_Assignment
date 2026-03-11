# C Programming Project 2 - Code Explanation

GitHub Repository:
https://github.com/goldensash1/C-Programming-Project-2_Assignment.git

## Overview
This submission contains three independent C programs. Each one is menu-driven and focuses on core low-level concepts: structures, dynamic memory, pointer traversal, and function pointers.

## 1) Dynamic Student Record Engine
File: student_record_engine.c

### How it works
- A `Student` structure stores `id`, `name`, and `grade`.
- The student list is dynamic: memory grows with `realloc` whenever a new student is added.
- Program features are grouped in function pointers, then called based on the selected menu option.
- Sorting is done with a simple comparison-based method (descending by grade).

### Technical points
- Dynamic memory: `malloc/realloc/free`
- Pointer traversal: iterates through the student array using index/pointer access
- Analysis logic: average, top student, and custom grade stability (variance-style measure)

## 2) Adaptive Text Intelligence Tool
File: text_intelligence_tool.c

### How it works
- The program reads one paragraph from the user.
- It tokenizes text into words and performs analyses through function pointers.
- Word data is kept in a `WordStat` structure array.
- It prints memory addresses of key arrays to show runtime memory allocation clearly.

### Technical points
- Required string operations: `strlen`, `strcmp`, `strcpy` (plus token parsing)
- Pointer-based traversal while scanning characters and words
- Built-in analyses: word count, longest word, most frequent word
- Custom analysis: vowel density in the input text

## 3) Callback-Based Device Monitoring Simulator
File: device_monitoring_simulator.c

### How it works
- Devices are stored in a dynamic array of `Device` structures.
- Each `Device` has a `type` and a `union` reading (temperature, pressure, or voltage).
- A processing function receives a callback and applies it to each device.
- The app simulates 10 random readings and runs monitor functions from the menu.

### Technical points
- Union usage to share memory between multiple reading formats
- Callback pattern: `process_device(device, callback)`
- Custom callback adds critical alert checks beyond normal monitoring

## Conclusion
All programs compile and run correctly. The implementation is intentionally simple but still demonstrates the required C programming concepts in a practical way.

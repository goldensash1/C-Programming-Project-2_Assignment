# C Programming Projects

All three projects have been successfully created and compiled!

## Project 1: Dynamic Student Record Engine
**File:** `project1.c`

### Features:
- ✓ Uses dynamic memory allocation for student records
- ✓ Structures with ID, name, and grade
- ✓ Function pointers for all operations
- ✓ Student ID: 54321
- ✓ Custom analysis: Grade Stability Score (variance-based)

### How to Run:
```bash
./project1
```

### Operations:
1. Add students dynamically
2. Display all students in formatted table
3. Sort students by grade (highest to lowest)
4. Calculate average grade
5. Find top student
6. Grade Stability Analysis (custom function)

---

## Project 2: Adaptive Text Intelligence Tool
**File:** `project2.c`

### Features:
- ✓ Dynamic memory allocation for text storage
- ✓ String function usage (strlen, strcmp, strcpy)
- ✓ Word statistics structure
- ✓ Function pointers for analysis
- ✓ Memory address printing
- ✓ Custom analysis: Vowel Density

### How to Run:
```bash
./project2
```

### Operations:
1. Count words in text
2. Find longest word
3. Find most frequent word
4. Vowel Density Analysis (custom function)

### Example:
- Enter: "The quick brown fox jumps over the lazy dog"
- Vowel Density: Shows percentage of vowels in text

---

## Project 3: Callback-Based Device Monitoring Simulator
**File:** `project3.c`

### Features:
- ✓ Union-based device readings
- ✓ Dynamic memory for device structures
- ✓ Callback functions for monitoring
- ✓ 10 simulated devices (3 types)
- ✓ Custom callback: Alert system
- ✓ Pointer traversal of device array

### How to Run:
```bash
./project3
```

### Device Types:
1. Temperature Sensors (°C)
2. Pressure Sensors (hPa)
3. Voltage Sensors (Volts)

### Callbacks:
- Temperature Monitor - Alerts for high/low temps
- Pressure Monitor - Alerts for abnormal pressure
- Voltage Monitor - Alerts for low battery
- Alert System (custom) - Critical alerts

---

## Compilation

All projects compile without errors:
```bash
gcc -o project1 project1.c
gcc -o project2 project2.c
gcc -o project3 project3.c
```

## Key Concepts Demonstrated

### Project 1:
- Dynamic memory with `malloc()` and `realloc()`
- Structures and pointer traversal
- Function pointers in structs
- Bubble sort algorithm
- Custom analysis function

### Project 2:
- Dynamic text memory allocation
- String functions: `strlen()`, `strcmp()`, `strcpy()`, `strtok()`
- Memory address printing
- Character analysis (vowel counting)
- Pointer-based text traversal

### Project 3:
- Union for different data types
- Callback function implementation
- Dynamic device array allocation
- Pointer callbacks: `process_device()`
- Random number generation

---

## Notes

- All code is simple and readable as requested
- Minimal but effective error handling
- Menu-driven interfaces for easy testing
- Proper memory management (malloc/free)
- Clean pointer usage throughout

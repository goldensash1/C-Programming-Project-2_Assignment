#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_ID 54321

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Function pointers
typedef struct {
    void (*add_student)(Student**, int*);
    void (*display)(Student*, int);
    void (*sort_by_grade)(Student*, int);
    void (*calculate_avg)(Student*, int);
    void (*find_top)(Student*, int);
    void (*grade_stability)(Student*, int);
} Operations;

// Add student
void add_student(Student **students, int *count) {
    *students = realloc(*students, (*count + 1) * sizeof(Student));
    printf("Enter Student ID: ");
    scanf("%d", &(*students)[*count].id);
    printf("Enter Name: ");
    scanf("%s", (*students)[*count].name);
    printf("Enter Grade (0-100): ");
    scanf("%f", &(*students)[*count].grade);
    (*count)++;
    printf("Student added successfully!\n\n");
}

// Display all students
void display(Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n\n");
        return;
    }
    printf("\n%-10s %-20s %-10s\n", "ID", "Name", "Grade");
    printf("================================\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].id, students[i].name, students[i].grade);
    }
    printf("\n");
}

// Sort by grade (descending)
void sort_by_grade(Student *students, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by grade (highest to lowest).\n\n");
}

// Calculate average grade
void calculate_avg(Student *students, int count) {
    if (count == 0) {
        printf("No students available.\n\n");
        return;
    }
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].grade;
    }
    printf("Average Grade: %.2f\n\n", sum / count);
}

// Find top student
void find_top(Student *students, int count) {
    if (count == 0) {
        printf("No students available.\n\n");
        return;
    }
    int top = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].grade > students[top].grade) {
            top = i;
        }
    }
    printf("Top Student: %s (Grade: %.2f)\n\n", students[top].name, students[top].grade);
}

// Custom analysis: Grade stability (variance)
void grade_stability(Student *students, int count) {
    if (count < 2) {
        printf("Need at least 2 students for analysis.\n\n");
        return;
    }
    float avg = 0;
    for (int i = 0; i < count; i++) avg += students[i].grade;
    avg /= count;
    
    float variance = 0;
    for (int i = 0; i < count; i++) {
        variance += (students[i].grade - avg) * (students[i].grade - avg);
    }
    variance /= count;
    
    printf("Grade Variance: %.2f\n", variance);
    printf("Grade Stability Score: %.2f%%\n\n", 100 - (variance / 10));
}

// Menu
void show_menu() {
    printf("\n=== Student Record System ===\n");
    printf("Student ID: %d\n", STUDENT_ID);
    printf("1. Add Student\n");
    printf("2. Display All\n");
    printf("3. Sort by Grade\n");
    printf("4. Calculate Average\n");
    printf("5. Find Top Student\n");
    printf("6. Grade Stability Analysis\n");
    printf("7. Exit\n");
    printf("Choose: ");
}

int main() {
    Student *students = NULL;
    int count = 0;
    int choice;
    
    Operations ops = {add_student, display, sort_by_grade, 
                      calculate_avg, find_top, grade_stability};
    
    while (1) {
        show_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                ops.add_student(&students, &count);
                break;
            case 2:
                ops.display(students, count);
                break;
            case 3:
                ops.sort_by_grade(students, count);
                break;
            case 4:
                ops.calculate_avg(students, count);
                break;
            case 5:
                ops.find_top(students, count);
                break;
            case 6:
                ops.grade_stability(students, count);
                break;
            case 7:
                free(students);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


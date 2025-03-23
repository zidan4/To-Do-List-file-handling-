#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_LENGTH 100
#define FILE_NAME "tasks.txt"

void addTask() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    char task[MAX_TASK_LENGTH];
    printf("Enter task: ");
    getchar(); // Consume newline
    fgets(task, MAX_TASK_LENGTH, stdin);
    fprintf(file, "%s", task);
    fclose(file);
    printf("Task added successfully!\n");
}

void viewTasks() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No tasks found.\n");
        return;
    }
    char task[MAX_TASK_LENGTH];
    printf("\n--- To-Do List ---\n");
    while (fgets(task, MAX_TASK_LENGTH, file)) {
        printf("- %s", task);
    }
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Task\n2. View Tasks\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

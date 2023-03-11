#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct workout {
    char name[50];
    int reps;
    int sets;
    float time;
};

void add_workout(struct workout workouts[], int *num_workouts) {
    printf("\nEnter the name of the workout: ");
    getchar(); // Consume newline character
    fgets(workouts[*num_workouts].name, 50, stdin);
    printf("Enter the number of reps: ");
    scanf("%d", &workouts[*num_workouts].reps);
    printf("Enter the number of sets: ");
    scanf("%d", &workouts[*num_workouts].sets);
    printf("Enter the time taken (in minutes): ");
    scanf("%f", &workouts[*num_workouts].time);
    (*num_workouts)++;
}

void view_workouts(struct workout workouts[], int num_workouts) {
    printf("\nWorkout History:\n");
    printf("%-30s %-10s %-10s %-10s\n", "Workout Name", "Reps", "Sets", "Time (min)");
    for (int i = 0; i < num_workouts; i++) {
        printf("%-30s %-10d %-10d %-10.2f\n", workouts[i].name, workouts[i].reps, workouts[i].sets, workouts[i].time);
    }
}

void export_workouts(struct workout workouts[], int num_workouts) {
    printf("\nEnter the name of the file to export to (including .txt extension): ");
    char filename[50];
    getchar(); // Consume newline character
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    fprintf(file, "%-30s %-10s %-10s %-10s\n", "Workout Name", "Reps", "Sets", "Time (min)");
    for (int i = 0; i < num_workouts; i++) {
        fprintf(file, "%-30s %-10d %-10d %-10.2f\n", workouts[i].name, workouts[i].reps, workouts[i].sets, workouts[i].time);
    }

    fclose(file);
    printf("Workouts exported successfully.\n");
}

int main() {
    struct workout workouts[100];
    int num_workouts = 0;

    int menu_choice = -1;
    while (menu_choice != 4) {
        printf("\nWorkout Tracker Menu:\n");
        printf("1. Add workout\n");
        printf("2. View workouts\n");
        printf("3. Export workouts to file\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                add_workout(workouts, &num_workouts);
                break;
            case 2:
                view_workouts(workouts, num_workouts);
                break;
            case 3:
                export_workouts(workouts, num_workouts);
                break;
            case 4:
                break;
            default:
                printf("Error: Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

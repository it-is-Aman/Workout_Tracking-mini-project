#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int reps;
    int sets;
    float time;
}workout;

                                                                                                   //workouts from case 1 comes as form of array so store in array of struct which is workout[]
void add_workout(workout workouts[], int *num_workouts) {                                          //*num_workouts beacuse it have address of num_workout comming from case 1
    printf("\nEnter the name of the workout (without space) : ");
    // getchar();  // Consume newline character

    //fgets() -> read input from stdin (standard input) and store it in "workouts[*num_workouts].name"
    // fgets(workouts[*num_workouts].name, 30, stdin);                                             //this function will also store the enter key as entered by the user 

    // scanf("%s",&workouts[*num_workouts].name);

    getchar();                                                                                     //The function waits until a character is entered by the user
    gets(workouts[*num_workouts].name);                                                            //store as a string with spaces

    printf("Enter the number of reps: ");
    scanf("%d", &workouts[*num_workouts].reps);
    printf("Enter the number of sets: ");
    scanf("%d", &workouts[*num_workouts].sets);
    printf("Enter the time taken (in minutes): ");
    scanf("%f", &workouts[*num_workouts].time);
    (*num_workouts)++;
}

void view_workouts(workout workouts[], int num_workouts) {
    printf("\nWorkout history:\n");
    printf("%-30s %-10s %-10s %-10s\n", "Workout Name", "Reps", "Sets", "Time (min)");             //when alligned in order, you should seperated word in "" with comma , and write %-10s respectively 
    for (int i = 0; i < num_workouts; i++) {
        printf("%-30s %-10d %-10d %-10.2f\n", workouts[i].name, workouts[i].reps, workouts[i].sets, workouts[i].time);  // %-30s left-align the string value within a field of width 30 characters
    }
}

void export_workouts(workout workouts[], int num_workouts) {
    char file_name[30];

    printf("\nEnter the name of the file to export to (including .txt extension): ");
    getchar();
    gets(file_name);

    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    fprintf(file, "%-30s %-10s %-10s %-10s\n", "Workout Name", "Reps", "Sets", "Time (min)");
    for (int i = 0; i < num_workouts; i++) {
        fprintf(file, "%-30s %-10d %-10d %-10.2f\n", workouts[i].name, workouts[i].reps, workouts[i].sets, workouts[i].time);
    }

    fclose(file);
    printf("Workouts exported successfully with name %s\n", file_name);
}

int main() {
    workout workouts[100];
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
                add_workout(workouts, &num_workouts);                                              //we pass address of num_workouts
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

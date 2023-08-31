# Workout_Tracking-mini-project

The Workout Tracker is a simple console-based program written in C that allows users to track and manage their workout routines. Users can add workout information, view their workout history, and export the workout data to a text file.
## Features

### Add Workout: 
Users can add a new workout to their history by providing details such as the workout name, number of reps, number of sets, and time taken.

### View Workouts:
Users can view their workout history, which includes the workout name, number of reps, number of sets, and time taken for each recorded workout.

### Export Workouts:
Users can export their workout history to a text file. The exported file will include a table with workout details.

## How to Use

### Compile the Code:
Compile the C code using a C compiler of your choice. For example, using GCC:

    gcc -o workout_tracker workout_tracker.c
   

### Run the Program:
Execute the compiled program:

    ./workout_tracker

### Menu Options:
Once the program is running, you will see a menu with the following options:

Add workout: Add a new workout to the history.
View workouts: Display the history of recorded workouts.
Export workouts to file: Save the workout history to a text file.
Quit: Exit the program.

### Adding a Workout:
When selecting the "Add workout" option, you will be prompted to enter details about the workout, including its name, number of reps, number of sets, and time taken.

### Viewing Workouts:
Choosing the "View workouts" option will display a table showing all recorded workouts, including their details.

### Exporting Workouts:
To export the workout history to a text file, choose the "Export workouts to file" option. You'll be asked to enter the name of the file (including the .txt extension) to which the data will be exported.

## Notes

The program supports recording up to 100 workouts.

To navigate the menu, enter the corresponding number for your choice.

When adding a workout, make sure to enter the workout name without spaces.

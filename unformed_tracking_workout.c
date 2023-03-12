#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int reps;
    int sets;
    int time;
}workout;

void add_workout(workout workouts[],int *num){      //workouts from case 1 comes as form of array so store in struct of array
    printf("enter your workout name:");
    getchar();
    gets(workouts[*num].name);
    printf("reps");
    scanf("%d",&workouts[*num].reps);
    printf("sets");
    scanf("%d",&workouts[*num].sets);
    printf("time");
    scanf("%d",&workouts[*num].time);
    (*num)++;
}

void view(workout workouts[],int num){
    printf("history\n");
    printf("%-30s %-10s %-10s %-10s\n","Workout", "name", "Sets", "Reps", "Time");                          //when alligned in order, you should seperated word in "" with comma , and write %-10s respectively 
    for(int i=0;i<num;i++){
        printf("%-30s %-10d %-10d %-10d\n",workouts[i].name,workouts[i].reps,workouts[i].sets,workouts[i].time);
    }
}
void export(workout workouts[],int num){
    char filename[50];
    printf("enter file name in .txt\n");
    getchar();
    gets(filename);
    FILE *file=fopen(filename,"w");
    if(file==NULL){
        printf("failed");
        return;
    }
    
    fprintf(file,"history\n");
    fprintf(file,"%-30s %-10s %-10s %-10s\n","Workout", "name", "Sets", "Reps", "Time");
    for(int i=0;i<num;i++){
        fprintf(file,"%-30s %-10d %-10d %-10d\n",workouts[i].name,workouts[i].reps,workouts[i].sets,workouts[i].time);
    }

    fclose(file);
    printf("exported successfully %s\n",filename);
}

int main(){
    workout workouts[100];
    int num_workout = 0;
    int number=-1;
    while(number!=4){
        printf("enter your choice\n1.add\n2.view\n3.export\n4.exit\n");
        scanf("%d",&number);

        switch (number){
            case 1: add_workout(workouts,&num_workout);
                    break;
            case 2: view(workouts,num_workout);
                    break;
            case 3: export(workouts,num_workout);
                    break;
            case 4: break;
            default:    printf("enter valid number");
        }
    }

    return 0;
}
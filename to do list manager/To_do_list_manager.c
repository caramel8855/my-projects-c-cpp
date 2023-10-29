#include <stdio.h>
#include <string.h>
#define Max_Size 100
struct task{
    char description[100];
    int done; 
};

void addtask (struct task tasks[], int *taskcount , char description[]){
    if(*taskcount<Max_Size){
        strcpy(tasks[*taskcount].description , description);
        tasks[*taskcount].done = 0;
        (*taskcount)++;
        printf("Task added successfully\n");
    } else{
        printf("Task limit reached. You can not add more than 100\n");
    }
}

void markdone(struct task tasks[], int taskcount, int tasknumber){
    if(tasknumber>=1 && tasknumber<taskcount){
        tasks[tasknumber-1].done = 1;
        printf("The task has been marked done\n");
    }
    else{
        printf("please enter a valid task number.\n");
    }

}

void deletetask(struct task tasks[], int *taskcount, int tasknumber){
    if(tasknumber>=1 && tasknumber<*taskcount){
        for(int i  = (tasknumber-1); i<(*taskcount-1); i++){
           strcpy(tasks[i].description, tasks[i+1].description);
            tasks[i].done = tasks[i+1].done;
        }
        (*taskcount)--;
        printf("Task deleted successfully\n");
    }
    else {
        printf("Please enter a valid task number to delete\n");
    }

}

void displaytasks(struct task tasks[], int taskcount){
    printf("Tasks: \n");
    for(int i = 0 ; i < taskcount; i++){
        printf("%d . [%c] %s\n", i+1, tasks[i].done ? 'X' : ' ' , tasks[i].description);
    }

}

int main (){
    struct task tasks[Max_Size];
    int taskcount = 0;
    char description[100];
    int choice;
    int tasknumber;

    do{
    printf("------------------\n");
    printf("To-Do List Manager\n");
    printf("------------------\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Done\n");
        printf("3. Delete Task\n");
        printf("4. Display Tasks\n");
        printf("0. Exit\n");
        printf("What do you want to do ?:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
            printf("Enter task description :\n");
            getchar(); //comsume the new line char by scanf
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0' ; //removed the trailing new line by fgets
            addtask(tasks,&taskcount, description);
            break;

            case 2:
            printf("Input the task number to mark: \n");
            scanf("%d", &tasknumber);
            markdone(tasks, taskcount, tasknumber);
            break;

            case 3:
            printf("Enter the task number you want to delete\n");
            scanf("%d", &tasknumber);
            deletetask(tasks, &taskcount, tasknumber);
            break; 

            case 4:
            displaytasks(tasks, taskcount);
            break;

            case 0:
            printf("programme Exit successfully\n");
            break;

            default :
            printf("Enter a valid number\n");

        }
    } while (choice!= 0);

    return 0;
}

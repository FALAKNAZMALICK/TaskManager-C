#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void addtask(void) {
	int i=0;
    char task[50][20];
    FILE *fptr;
    fptr = fopen("myfile.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter task title: ");
    fflush(stdin); 
	
    fgets(task[i], sizeof(task), stdin);

    fputs(task[i], fptr);
    i++;
    fclose(fptr);
    printf("\nTask added successfully!\n");
}
void viewtask(void)
{
	int i=0;
	char task[50][20];
	FILE *fptr;
	fptr=fopen("myfile.txt","r");
	if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }
	printf("\n\t\t TASKS\n");
    while (fgets(task[i], sizeof(task), fptr)) {
        printf("%d. %s\n",i+1, task[i]);  // Print each task
   		i++;
    }
    
	//fputs(task,fptr);
	fclose(fptr);
	
}

void clearfile(void) {
    FILE *fptr;
    fptr = fopen("myfile.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file to clear.\n");
        return;
    }
    fclose(fptr);
}

void deleteTask(void) {
    int i = 0, taskIndex;
    char tasks[50][20];
    FILE *fptr;

    
    fptr = fopen("myfile.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    
    while (fgets(tasks[i], sizeof(tasks[i]), fptr)) {
        tasks[i][strcspn(tasks[i], "\n")] = '\0'; 
        i++;
    }
    int taskCount = i; 
    fclose(fptr);

    
    printf("\n\t\t TASKS\n");
    for (i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }

   
    printf("Enter the task number to delete: ");
    scanf("%d", &taskIndex);

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    
    for (i = taskIndex - 1; i < taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    taskCount--; 

    
    fptr = fopen("myfile.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for (i = 0; i < taskCount; i++) {
        fprintf(fptr, "%s\n", tasks[i]);
    }
    fclose(fptr);
    printf("Task deleted successfully!\n");
}



typedef struct {
    char title[20];
    char status[15];
} Task;

void editTask(void) {
    int i = 0, taskIndex;
    Task tasks[50];
    FILE *fptr;
    
   
    fptr = fopen("myfile.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }


    while (fscanf(fptr, "%[^,],%s\n", tasks[i].title, tasks[i].status) != EOF) {
        i++;
        if (i >= 50) { 
            break;
        }
    }
    int taskCount = i; 
    fclose(fptr);

    
    printf("\n\t\t TASKS\n");
    for (i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].title, tasks[i].status);
    }

  
    printf("Enter the task number to edit: ");
    scanf("%d", &taskIndex);
    getchar(); 

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    
    
    printf("Enter new task title: ");
    fgets(tasks[taskIndex - 1].title, 20, stdin);
    tasks[taskIndex - 1].title[strcspn(tasks[taskIndex - 1].title, "\n")] = '\0'; // Remove trailing newline character

 
    fptr = fopen("myfile.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }
    

    for (i = 0; i < taskCount; i++) {
        fprintf(fptr, "%s,%s\n", tasks[i].title, tasks[i].status);
    }
    fclose(fptr);
    printf("Task edited successfully!\n");
}

int main(void)
{
	int choice;
	do{
	printf("\n\t\t MENU\n");
	printf("1.ADD A NEW TASK\n");
	printf("2.VIEW ALL TASKS\n");
	printf("3.EXIT \n");
	printf("4.EDIT TASK\n");
	printf("5.DELETE TASK\n");
	printf("\n enter your choice\n:");
	scanf("%d",&choice);
	getchar();
	switch(choice)
	{
		case 1:
			addtask();
			break;
		case 2:
			viewtask();
			break;
		case 3:
			clearfile();
			printf("\n exiting program");	
			break;
		case 4:
			editTask();
			break;
		case 5:
			deleteTask();
			break;
		default:
			printf("\ninvalid choice.Try again\t");
	}
	}while(choice!=3);
	
	return 0;		
			
	}

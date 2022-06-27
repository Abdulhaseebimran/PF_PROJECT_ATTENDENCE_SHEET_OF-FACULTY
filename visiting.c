# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <string.h>


struct Faculty
{
    char name [50];
    char CheckAddRec [30];
    char checkViewRec[30];
    char department [50], program[20], month[20], course[30];
    char semester [30] ,section [30];
    char lecture[20][60], date[15][10], timein[13][10], timeout[13][10], remarks[13][16];
    float duration [20];
    int count;

} Faculty;

void mainFunction();
void mainFunction () {
    printf("WELCOME TO VISITING FACULTY ATTENDENCE SHEET SPRING 2022");
    printf("click any key to continue !");
    getch();

    mainFunction();
}

void menuFunction ();

void menuFunction () {
    int Choice;
    
    //clrscr(); 
    printf("Menu\n");
    printf("Enter a specific key to perform a task\n\n");
    printf("1. Add Lecture Records\n\n");
    printf("2. View Lecture Records\n\n");
    printf("3. Exit\n\n");
    printf("Enter your Choice = ");
    scanf("%d", &Choice);
    switch (Choice)
    {

    case 1:
        addRecords();
        break;

    case 2:
        viewRecords();
        break;

    case 3:
        exit(0);
        break;

    default:
        printf("Please Enter a right key!");
        break;
    }
    mainFunction();
}

void addReocrds () {
    char yn = 'y';
    char choice1, choice2, select;
    FILE *fp;
    int i, j;

    fp = fopen("records.txt", "ab+");
    if (fp == NULL)
    {
        printf("Error file does not open!");
        exit(0);
    }
    fflush(stdin);

    while (yn == 'y' || yn == 'Y')
    {
        Faculty.count = 0;
        printf("\t\tTeacher Attendence sheet spring 2022\n");
        fflush(stdin);
        printf("Enter Your name : ");
        gets(Faculty.name);
}
back:
     printf("Select Your Status : \n");
        printf("a.> Internal\nb.> External\nEnter Your choice : ");
        fflush(stdin);
        choice2 = getchar();
        if (choice1 == 'a' || choice1 == 'A')
        {
            strcpy(Faculty.checkViewRec, "Internal");
            printf("%s", Faculty.checkViewRec);
        }
        else if (choice2 == 'b' || choice2 == 'B')
        {
            strcpy(Faculty.checkViewRec, "External");
            printf("%s", Faculty.checkViewRec);
        }
        else
        {
            printf("Invalid Statement \n try again\n");
            goto back;
        }
        back2:
         printf("Select Your Status : \n");
        printf("a.> Visitor\nb.> Regular\nEnter Your choice : ");
        fflush(stdin);
        choice2 = getchar();
        if (choice2 == 'a' || choice2 == 'A')
        {
            strcpy(Faculty.CheckAddRec, "Visitor");
            printf("%s", Faculty.CheckAddRec);
        }
        else if (choice2 == 'b' || choice2 == 'B')
        {
            strcpy(Faculty.CheckAddRec, "Regular");
            printf("%s", Faculty.CheckAddRec);
        }
        else
        {
            printf("Invalid Statement \n try again\n");
            goto back2;
        }
}
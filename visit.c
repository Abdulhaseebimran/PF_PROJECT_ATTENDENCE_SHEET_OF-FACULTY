#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// Structure Start
struct Faculty
{
    char name[20];
    char grade[20];
    char statusVR[12];
    char statusIE[10];
    // get data from here
    char department[20], program[10], month[15], course[30];
    char semester, section;
    int class;
    // add lecture details
    char lecture[13][80], date[13][11], timein[13][10], timeout[13][10], remarks[13][15];
    float duration[13];
    // billing
    float salary, total, tax;
    int count;
} faculty;

// Structure end

// my function prototype
void menu();
void add();
void view();

void main()
{

    //     clrscr();
    // gotoxy(15, 8);
    printf("Welcome to visiting faculty internal external management system\n");
    // gotoxy(19, 5);
    printf("Press any key to continue .");
    getch();
    menu();
}

void menu()
{
    int choice;
    // clrscr();
    printf("Menu\n");
    printf("Enter a specific key to perform a task\n\n");
    printf("1. Add Lecture Records\n");
    printf("2. View Lecture Records\n");
    printf("3. Exit\n\n");
    printf("Enter your Choice : ");
    scanf("%d", &choice);
    switch (choice)
    {

    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        exit(0);
        break;

    default:
        printf("Please Enter a right key!");
        break;
    }
}

// function defination

void add()
{

    char yn = 'y';
    char choice1, choice2, choice3, select;
    FILE *fp;
    int i, j;

    fp = fopen("records.txt", "ab+");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(0);
    }
    fflush(stdin);

    while (yn == 'y' || yn == 'Y')
    {
        faculty.count = 0;
        printf("\t\tTeacher Data Registration\n");
        fflush(stdin);
        printf("Enter Your name : ");
        gets(faculty.name);

    back:
        printf("Select Your Grade : \n");
        printf("a.> Professor\nb.> AssisstantProfessor\nc.> Lecturer\nd.> Assisstant Lecturer\nEnter Your choice : ");
        fflush(stdin);
        choice1 = getchar();
        if (choice1 == 'a' || choice1 == 'A')
        {
            strcpy(faculty.grade, "Professor");
            printf("%s", faculty.grade);
        }
        else if (choice1 == 'b' || choice1 == 'B')
        {
            strcpy(faculty.grade, "Assisstant Professor");
            printf("%s", faculty.grade);
        }
        else if (choice1 == 'c' || choice1 == 'C')
        {
            strcpy(faculty.grade, "Lecturer");
            printf("%s", faculty.grade);
        }
        else if (choice1 == 'd' || choice1 == 'D')
        {
            strcpy(faculty.grade, "Assisstant Lecturer");
            printf("%s", faculty.grade);
        }
        else
        {
            printf("Invalid Statement ! \n try Again\n");
            goto back;
        }

    backch2:
        printf("Select Your Status : \n");
        printf("a.> Internal\nb.> External\nEnter Your choice : ");
        fflush(stdin);
        choice2 = getchar();
        if (choice2 == 'a' || choice2 == 'A')
        {
            strcpy(faculty.statusIE, "Internal");
            printf("%s", faculty.statusIE);
        }
        else if (choice2 == 'b' || choice2 == 'B')
        {
            strcpy(faculty.statusIE, "External");
            printf("%s", faculty.statusIE);
        }
        else
        {
            printf("Invalid Statement \n try again\n");
            goto backch2;
        }

    backch3:
        printf("Select Your Status : \n");
        printf("a.> Visitor\nb.> Regular\nEnter Your choice : ");
        fflush(stdin);
        choice3 = getchar();
        if (choice3 == 'a' || choice3 == 'A')
        {
            strcpy(faculty.statusVR, "Visitor");
            printf("%s", faculty.statusVR);
        }
        else if (choice3 == 'b' || choice3 == 'B')
        {
            strcpy(faculty.statusVR, "Regular");
            printf("%s", faculty.statusVR);
        }
        else
        {
            printf("Invalid Statement \n try again\n");
            goto backch3;
        }

        fflush(stdin);
        printf("Enter Department : ");
        gets(faculty.department);
        printf("Enter program : ");
        gets(faculty.program);
        fflush(stdin);
        printf("Enter Month : ");
        gets(faculty.month);
        fflush(stdin);

        printf("Enter Course : ");
        gets(faculty.course);

        printf("Enter Class No: ");
        fflush(stdin);
        scanf("%d", &faculty.class);
        printf("Enter Section : ");
        fflush(stdin);
        faculty.section = getchar();
        printf("Enter Semester : ");
        fflush(stdin);
        faculty.semester = getchar();
        getch();

        // lecture added here
        for (i = 0; i < 3; i++)
        {
            fflush(stdin);
            printf("Insert Lectures %d Details \n", i + 1);
            printf("Enter lecture %d topics : ", i + 1);
            gets(faculty.lecture[i]);
            printf("Enter date (dd-mm-yyyy) : ");
            gets(faculty.date[i]);
            printf("Enter Time in (hh : mm am/pm) : ");
            gets(faculty.timein[i]);
            printf("Enter Time out (hh : mm am/pm) : ");
            gets(faculty.timeout[i]);
            printf("Enter total Duration : ");
            fflush(stdin);
            scanf("%.2f ", faculty.duration[i]);
            fflush(stdin);
        back4:
            printf("Chose Remarks : \na) Present\nb) Absent\nc) Makeup \n");
            printf("Select : ");
            select = getchar();
            if (select == 'a' || select == 'A')
            {
                strcpy(faculty.remarks[i], "Present");
                faculty.count = faculty.count + 1;
            }
            else if (select == 'b' || select == 'B')
            {
                strcpy(faculty.remarks[i], "Absent");
            }
            else if (select == 'c' || select == 'C')
            {
                strcpy(faculty.remarks[i], "MakeUp");
                faculty.count = faculty.count + 1;
            }
            else
            {
                goto back4;
            }
        }
        printf("Bill Generate\nTotal no of present is %d\n", faculty.count);
        // printf("total count %d\n", count);
        fflush(stdin);
        if (choice1 == 'a')
        {
            faculty.salary = faculty.count * 3000;
            printf("%.2f\n", faculty.salary);
            faculty.tax = (faculty.salary * 15.0) / 100.0;
            printf("%.2f\n", faculty.tax);
            faculty.total = (faculty.salary - faculty.tax);
            printf("Total Salary %.2f\n", faculty.total);
        }
        else if (choice1 == 'b')
        {
            faculty.salary = faculty.count * 2500;
            printf("%.2f\n", faculty.salary);
            faculty.tax = (faculty.salary * 15.0) / 100.0;
            printf("%.2f\n", faculty.tax);
            faculty.total = (faculty.salary - faculty.tax);
            printf("Total Salary %.2f\n", faculty.total);
        }
        else if (choice1 == 'c')
        {
            faculty.salary = faculty.count * 2000;
            printf("%.2f\n", faculty.salary);
            faculty.tax = (faculty.salary * 15.0) / 100.0;
            printf("%.2f\n", faculty.tax);
            faculty.total = (faculty.salary - faculty.tax);
            printf("Total Salary %.2f\n", faculty.total);
        }
        else if (choice1 == 'd')
        {
            faculty.salary = faculty.count * 1500;
            printf("%.2f\n", faculty.salary);
            faculty.tax = (faculty.salary * 15.0) / 100.0;
            printf("%.2f\n", faculty.tax);
            faculty.total = (faculty.salary - faculty.tax);
            printf("Total Salary %.2f\n", faculty.total);
        }

        fwrite(&faculty, sizeof(faculty), 1, fp);
        printf("Teacher lecture records added successful..\n");

        printf("Do you want to add another registration (y/n) : ");
        fflush(stdin);
        yn = getchar();
    }

    fclose(fp);
    printf("Press any key to go for main menu : ");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    char sname[20], smonth[15];
    // clrscr();
    printf("Which data you want to view \n");
    printf("Enter Name for search : ");
    fflush(stdin);
    gets(sname);

    fp = fopen("records.txt", "rb+");
    if (fp == NULL)
    {
        printf("Error! File Not Read");
        exit(0);
    }
    
    while (fread(&faculty, sizeof(faculty), 1, fp) == 1)
    {
        if (strcmp(sname, faculty.name) == 0)
        {
            printf("Which month data you want to view : ");
            fflush(stdin);
            gets(smonth);
            fflush(stdin);
            if (strcmp(smonth, faculty.month) == 0)
            {
                printf("Name : %s\n", faculty.name);
                printf("Grade : %s\n", faculty.grade);
                printf("Internal or External : %s\n", faculty.statusVR);
                printf("Visitor or Regular : %s\n", faculty.statusVR);
                printf("Visitor or Regular : %s\n", faculty.statusVR);
                printf("Department : %s\n", faculty.department);
                printf("Program : %s\n", faculty.program);
                printf("Class : %s\n", faculty.class);
                printf("Semester : %s\n", faculty.semester);
                printf("Section : %s\n", faculty.section);
                printf("Course: %s\n", faculty.course);
                printf("month: %s\n", faculty.month);
            }
        }
    }
    printf("Bill View Successfuly");
    fclose(fp);
    getch();
    menu();
}
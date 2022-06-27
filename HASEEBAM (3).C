#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
void gotoxy(int ,int );
void teachers();
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct faculty
{
    char name[20];
    char department[10];
    int month ;
    char course[20];
    char program[20];
    char semester[20];
};
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
	cleardevice();
	setcolor(BLUE);
	settextstyle(7,0,3);
	outtextxy(260,20,"WELCOME");
	settextstyle(7,0,3);
	outtextxy(300,60,"TO");
	settextstyle(7,0,3); //(style,direction 0 for v 1 for h,text size)
	outtextxy(55,110,"SINDH MADRESSATUL ISLAM UNIVERSITY");
	settextstyle(7,0,3);
	outtextxy(270,170,"KARACHI");
	settextstyle(7,0,3);
	outtextxy(55,240,"VISITING FACULTY MANAGEMENT SYSTEM");
	delay(1000);
	cleardevice();
	gotoxy(15,8);
	printf("VISITING TEACHERS AND FACULTY ATEENDENCE SHEET");
	gotoxy(19,15);
	printf("Press any key to continue.");
	getch();
	menu();
	closegraph();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("SINDH MADRESSATUL ISLAM UNIVERSITY");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Modify Record.");
    gotoxy(10,11);
    printf("5 : Delete.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
	add();
	break;

    case 2:
	view();
	break;

    case 3:
	search();
	break;

    case 4:
	modify();
	break;

    case 5:
	deleterec();
	break;

    case 6:
	exit(1);
	break;

    default:
	gotoxy(10,17);
	printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct faculty flt;
    char another ='y';
    clrscr();

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
	gotoxy(10,5);
	printf("Error opening file");
	exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
	gotoxy(10,3);
	printf("<--:ADD RECORD:-->");
	gotoxy(10,5);
	printf("Enter details of course.");
	gotoxy(10,7);
	printf("Enter Name : ");
//        gets(std.name);///???
	gets(flt.name);
	gotoxy(10,8);
	printf("Enter Department : ");
	gets(flt.department);
	gotoxy(10,9);
	printf("Enter Month : ");
	scanf("%d",&flt.month);
	fflush(stdin);
	gotoxy(10,10);
	printf("Enter Course : ");
//        gets(std.course);///???
	gets(flt.course);
	gotoxy(10,11);
	printf("Enter Program : ");
	gets(flt.program);
	gotoxy(10,12);
	printf("Enter Semester : ");
	gets(flt.semester);
	fwrite(&flt,sizeof(flt),1,fp);
	gotoxy(10,15);
	printf("Want to add of another record? Then press 'y' else 'n'.");
	fflush(stdin);
//        another = getch();///???
	another = getch();
	clrscr();
	fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct faculty flt;
    clrscr();
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No   TEACHERS     DEPARTMENT   MONTH  COURSE      PROGRAM   SEMESTER");
    gotoxy(10,6);
    printf("----------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
	gotoxy(10,8);
	printf("Error opening file.");
	exit(1);
    }
    j=8;
    while(fread(&flt,sizeof(flt),1,fp) == 1){
	gotoxy(10,j);
	printf("%-7d%-22s%-12s%-9d%-12s%-12s",i,flt.name,flt.department,flt.month,flt.course,flt.program,flt.semester);
	i++;
	j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct faculty flt;
    char fltname[20];
    clrscr();
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of Teachers : ");
    fflush(stdin);
    gets(fltname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
	gotoxy(10,6);
	printf("Error opening file");
	exit(1);
    }
    while(fread(&flt,sizeof(flt),1,fp ) == 1){
	if(strcmp(fltname,flt.name) == 0){
	    gotoxy(10,8);
	    printf("Name : %s",flt.name);
	    gotoxy(10,9);
	    printf("DEPARTMENT : %s",flt.department);
	    gotoxy(10,10);
	    printf("MONTH : %d",flt.month);
	    gotoxy(10,11);
	    printf("Course : %s",flt.course);
	    gotoxy(10,12);
	    printf("PROGRAM : %s",flt.program);
	    gotoxy(10,13);
	    printf("SEMESTER : %s",flt.semester);
	}
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    char fltname[20];
    FILE *fp;
    struct faculty flt;
    clrscr();
    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of teachers to modify: ");
    fflush(stdin);
    gets(fltname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
	gotoxy(10,6);
	printf("Error opening file");
	exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&flt,sizeof(flt),1,fp) == 1)
    {
	if(strcmp(fltname,flt.name) == 0){
	    gotoxy(10,7);
	    printf("Enter name: ");
	    gets(flt.name);
	    gotoxy(10,8);
	    printf("Enter Department : ");
	    gets(flt.department);
	    gotoxy(10,9);
	    printf("Enter month : ");
	    scanf("%d",&flt.month);
	    gotoxy(10,10);
	    printf("Enter Course : ");
	    fflush(stdin);
	    gets(flt.course);
	    gotoxy(10,11);
	    printf("Enter Program : ");
	    fflush(stdin);
	    gets(flt.program);
	    gotoxy(10,12);
	    printf("Enter Semester : ");
	    fflush(stdin);
	    gets(flt.semester);
	    fseek(fp ,-sizeof(flt),SEEK_CUR);
	    fwrite(&flt,sizeof(flt),1,fp);
	    break;
	}
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct faculty flt;
    clrscr();
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of teachers to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
	gotoxy(10,6);
	printf("Error opening file");
	exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
	gotoxy(10,6);
	printf("Error opening file");
	exit(1);
    }
    while(fread(&flt,sizeof(flt),1,fp) == 1){
	if(strcmp(stname,flt.name)!=0)
	    fwrite(&flt,sizeof(flt),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}



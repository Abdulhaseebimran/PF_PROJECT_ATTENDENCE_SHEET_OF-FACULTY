#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm,a,b,c;//,lec[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
initgraph(&gd,&gm,"C\\TURBOC3\\BGI");
cleardevice();
settextstyle(7,0,3);
outtextxy(260,20,"WELCOME");
settextstyle(7,0,3);
outtextxy(300,60,"TO");
settextstyle(4,0,4); //(style,direction 0 for v 1 for h,text size)
outtextxy(80,110,"Sindh Madressatul Islam University");
settextstyle(4,0,4);
outtextxy(280,170,"Karachi");
settextstyle(7,0,3);
outtextxy(1,240,"VISITING FACULTY ATTENCDENCE SHEET SPRING");
settextstyle(7,0,3);
outtextxy(290,290,"2022");
delay(5000);
cleardevice();
settextstyle(7,0,3);
outtextxy(10,100,"Visiting Faculty Attendence Sheet Spring 2022");
gotoxy(1,15);
printf("Select Number For Faculty Attendence");
gotoxy(1,17);
printf("1-Internal");
gotoxy(1,19);
printf("2-External");
gotoxy(1,21);
scanf("%d",&a);
cleardevice();
switch(a)
{
case 1:
settextstyle(7,0,3);
outtextxy(10,30,"Visiting Faculty Attendence Sheet Spring 2022");
gotoxy(1,8);
printf("Select Number For Faculty Attendence(Internal)");
gotoxy(1,10);
printf("1-Morning\n2-Evening");
gotoxy(1,12);
scanf("%d",&b);
switch(b)
{
case 1:
settextstyle(7,0,3);
outtextxy(10,30,"Visiting Faculty Attendence Sheet Spring 2022");
gotoxy(1,8);
printf("Select Number For Faculty Attendence(Internal)");
gotoxy(1,10);
printf("1-Mr Ameen Khowaja");
gotoxy(1,11);
printf("2-Ms Samreen Javaid");
case 2:
gotoxy(1,12);
printf("3-Mr Naeem Akhtar Samoon");
gotoxy(1,13);
printf("4-Mr Khalid Nawaz");
gotoxy(1,14);
printf("5-Mr Asif Awan");
}
break;
case 2:
settextstyle(7,0,3);
outtextxy(10,30,"Visiting Faculty Attendence Sheet Spring 2022");
gotoxy(1,8);
printf("Select Number For Faculty Attendence(External)");
gotoxy(1,10);
printf("1-Morning\n2-Evening");
gotoxy(1,12);
scanf("%d",&c);
switch(c)
{
case 1:
settextstyle(7,0,3);
outtextxy(10,30,"Visiting Faculty Attendence Sheet Spring 2022");
gotoxy(1,8);
printf("Select Number For Faculty Attendence(Internal)");
gotoxy(1,10);
printf("1-Mr Ameen Khowaja");
gotoxy(1,11);
printf("2-Ms Samreen Javaid");
case 2:
gotoxy(1,12);
printf("3-Mr Naeem Akhtar Samoon");
gotoxy(1,13);
printf("4-Mr Khalid Nawaz");
gotoxy(1,14);
printf("5-Mr Asif Awan");
}
break;
}
/*rectangle(1,100,639,352);
line(1,140,639,140);     //1 h
line(42,100,42,352);     //0-1 v  S.no.
line(205,100,205,352);   //1-2 v  Topic
line(240,100,240,352);   //2-3 v  Date
line(310,100,310,352);   //3-4 v  Time in
line(390,100,390,352);   //4-5 v  Time out
line(445,100,445,352);   //5-6 v  Total Hours taught
line(515,100,515,352);   //6-7 v  Teacher sign and Remarks
gotoxy(1,2);
printf("Name:Mr Ameen Khowaja");
gotoxy(40,2);
printf("Month:April");
gotoxy(1,3);
printf("Department:CS");
gotoxy(40,3);
printf("Semester:1-C");
gotoxy(1,4);
printf("Program:BSCS");
gotoxy(40,4);
printf("Course:Programming Fundamentals");
gotoxy(1,5);
printf("Date:1/3/2022");
gotoxy(2,8);
printf("S.No");
gotoxy(13,8);
printf("Topic");
gotoxy(27,8);
printf("Date");
gotoxy(32,8);
printf("Time-In");
gotoxy(41,8);
printf("Time-Out");
gotoxy(51,8);
printf("hours");
gotoxy(59,8);
printf("sign");
gotoxy(69,8);
printf("Remarks");
//lec
gotoxy(2,10);
printf("%d",lec[0]);
gotoxy(2,11);
printf("%d",lec[1]);
gotoxy(2,12);
printf("%d",lec[2]);
gotoxy(2,13);
printf("%d",lec[3]);
gotoxy(2,14);
printf("%d",lec[4]);
gotoxy(2,15);
printf("%d",lec[5]);
gotoxy(2,16);
printf("%d",lec[6]);
gotoxy(2,17);
printf("%d",lec[7]);
gotoxy(2,18);
printf("%d",lec[8]);
gotoxy(2,19);
printf("%d",lec[9]);
gotoxy(2,20);
printf("%d",lec[10]);
gotoxy(2,21);
printf("%d",lec[11]);
gotoxy(2,22);
printf("%d",lec[12]);
date
gotoxy(22,8);
scanf("%d",&m);
gotoxy(22,9);
scanf("%d",&n);
gotoxy(22,10);
scanf("%d",&o);
gotoxy(22,11);
scanf("%d",&d);
gotoxy(22,12);
scanf("%d",&e);
gotoxy(22,13);
scanf("%d",&f);
gotoxy(22,14);
scanf("%d",&g);
gotoxy(22,15);
scanf("%d",&h);
gotoxy(22,16);
scanf("%d",&i);
gotoxy(22,17);
scanf("%d",&j);
//time
gotoxy(42,8);
scanf("%d",&m);
gotoxy(42,9);
scanf("%d",&n);
gotoxy(42,10);
scanf("%d",&o);
gotoxy(42,11);
scanf("%d",&d);
gotoxy(42,12);
scanf("%d",&e);
gotoxy(42,13);
scanf("%d",&f);
gotoxy(42,14);
scanf("%d",&g);
gotoxy(42,15);
scanf("%d",&h);
gotoxy(42,16);
scanf("%d",&i);
gotoxy(42,17);
scanf("%d",&j);
//topics
gotoxy(38,8);
scanf("%d",&m);
gotoxy(38,9);
scanf("%d",&n);
gotoxy(38,10);
scanf("%d",&o);
gotoxy(38,11);
scanf("%d",&d);
gotoxy(38,12);
scanf("%d",&e);
gotoxy(38,13);
scanf("%d",&f);
gotoxy(38,14);
scanf("%d",&g);
gotoxy(38,15);
scanf("%d",&h);
gotoxy(38,16);
scanf("%d",&i);
gotoxy(38,17);
scanf("%d",&j);
gotoxy(38,8);
//hrs
scanf("%d",&m);
gotoxy(66,9);
scanf("%d",&n);
gotoxy(66,10);
scanf("%d",&o);
gotoxy(66,11);
scanf("%d",&d);
gotoxy(66,12);
scanf("%d",&e);
gotoxy(66,13);
scanf("%d",&f);
gotoxy(66,14);
scanf("%d",&g);
gotoxy(66,15);
scanf("%d",&h);
gotoxy(66,16);
scanf("%d",&i);
gotoxy(66,17);
scanf("%d",&j);
//sign
gotoxy(73,8);
scanf("%d",&m);
gotoxy(73,9);
scanf("%d",&n);
gotoxy(73,10);
scanf("%d",&o);
gotoxy(73,11);
scanf("%d",&d);
gotoxy(73,12);
scanf("%d",&e);
gotoxy(73,13);
scanf("%d",&f);
gotoxy(73,14);
scanf("%d",&g);
gotoxy(73,15);
scanf("%d",&h);
gotoxy(73,16);
scanf("%d",&i);
gotoxy(73,17);
scanf("%d",&j); */
getch();
closegraph();
}
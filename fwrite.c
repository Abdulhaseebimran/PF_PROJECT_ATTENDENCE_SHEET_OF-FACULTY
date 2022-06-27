#include <stdio.h>
struct std
{
    int id;
    float marks;
    char name[20];
};

int main()
{
    struct std s;
    char yn;
    FILE *fp = NULL;
    printf("Enter Your Records..");
    fp = fopen("demo.txt", "wb+");
    if (fp == NULL)
    {
        printf("OOps! some error occured");
    }
    fflush(stdin);
    while (yn == 'y')
    {
        /* code */
        fflush(stdin);
        printf("enter your Id : ");
        scanf("%d", &s.id);
        printf("enter your Marks : ");
        scanf("%f", &s.marks);
        printf("enter your name : %s");
        fflush(stdin);
        gets(s.name);
        fflush(stdin);

        fwrite(&s, sizeof(s), 1, fp);
        printf("do you want to add another records : (Y\n) ");
        fflush(stdin);

        scanf("%c", &yn);
    }
    fclose(fp);
    printf("Data Write Successfully.");
    return 0;
}

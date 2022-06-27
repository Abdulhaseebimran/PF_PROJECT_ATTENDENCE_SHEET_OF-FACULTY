#include <stdio.h>
#include<conio.h>
struct std
{
    int id;
    float marks;
    char name[20];
};

int main()
{
    struct std s;
    FILE *fp = NULL;
    printf("Check Your Records..");
    fp = fopen("demo.txt", "rb");

    fread(&s, sizeof(s), 1, fp);
    printf("your Id is %d\n", s.id);
    printf("your Id is %.2f\n", s.marks);
    printf("your Id is %s\n", s.name);
    fclose(fp);
    printf("Data Read Successfully.");
    return 0;
}

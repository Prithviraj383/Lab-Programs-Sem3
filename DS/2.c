#include<stdio.h>
#include<stdlib.h>
struct Student
{
        char name[50];
        int reg_no;
        float marks[3];
        float average_marks;
};
void readstudent(struct Student *s, int n)
{
        for(int i =0;i<n;i++)
        {
                printf("Emter details of student %d \n",(i+1));
                printf("Name: ");
                scanf("%s",s[i].name);
                printf("Register Number: ");
                scanf("%d", &s[i].reg_no);
                printf("Enter  marks of 3 tests: ");
                for(int j=0;j<3;j++)
                        scanf("%f",&s[i].marks[j]);
        }
}
void calcavg(struct Student *s, int n)
{
        for(int i=0;i<n;i++)
        {
                float a=s[i].marks[0],b=s[i].marks[1],c=s[i].marks[2];
                float min=a;
                if(b<min)
                        min=b;
                if(c<min)
                        min=c;
                s[i].average_marks=(a+b+c-min)/2;
        }
}
void display(struct Student *s, int n)
{
        printf("\nName \t Reg no. \t Avg \n");
        for(int i=0;i<n;i++)
                printf("%s \t %d \t %.2f\n",s[i].name,s[i].reg_no,s[i].average_marks);
}
int main()
{
        int n,ch;
        struct Student s[10];
        printf("Enter number of students: ");
        scanf("%d",&n);
        loop:
        printf("\n1.Read Info\n2. Calculate Average\n3.Display Info\n4.Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1: readstudent(s,n);
                                        goto loop;
                case 2: calcavg(s,n);
                                        printf("Average Calculated. \n");
                                        goto loop;
                case 3: display(s,n);
                                        goto loop;
                case 4: break;
                default: printf("Invalid Coice !!!!!!");
        }
        return 0;
}
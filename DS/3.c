#include <stdio.h>

typedef struct
{
        int hour;
        int minute;
        int second;
} Time;

void read(Time *t);
void display(Time *t);
void update(Time *t);
Time add(Time *t1, Time *t2);
void normalize(Time *t);

int main()
{
        Time t1, t2, t3;
        int choice;
        while (1)
        {
                printf("\n...Time Operations Menu...\n");
                printf("1. Read Time \n2. Display Time\n3.Update Time (increment by 1 second)\n4. Add two times\n5. Exit\n Enter your choice: ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                        read(&t1);
                        break;
                case 2:
                        display(&t1);
                        break;
                case 3:
                        update(&t1);
                        printf("After updating by 1 second:");
                        display(&t1);
                        break;
                case 4:
                        printf("Enter First Time:");
                        read(&t1);
                        printf("Enter Second Time: ");
                        read(&t2);
                        t3 = add(&t1, &t2);
                        printf("Sum of the two times: ");
                        display(&t3);
                        break;
                case 5:
                        printf("Program terminated");
                        return 0;
                default:
                        printf("Tnvalid choice\n");
                }
        }
        return 0;
}

void read(Time *t)
{
        printf("Enter the hour(0-23): ");
        scanf("%d", &t->hour);
        printf("Enter minute (0-59): ");
        scanf("%d", &t->minute);
        printf("Enter second (0-59): ");
        scanf("%d", &t->second);
        normalize(t);
}

void display(Time *t)
{
        printf("Time = %02d:%02d:%02d\n", t->hour, t->minute, t->second);
}

void update(Time *t)
{
        t->second++;
        if (t->second == 60)
        {
                t->second = 0;
                t->minute++;
        }
        if (t->minute == 60)
        {
                t->minute = 0;
                t->hour++;
        }
        if (t->hour == 24)
                t->hour = 0;
}

Time add(Time *t1, Time *t2)
{
        Time result;
        result.hour = t1->hour + t2->hour;
        result.minute = t1->minute + t2->minute;
        result.second = t1->second + t2->second;
        normalize(&result);
        return result;
}

void normalize(Time *t)
{
        if (t->second >= 60)
        {
                t->minute += t->second / 60;
                t->second %= 60;
        }
        if (t->minute >= 60)
        {
                t->hour += t->minute / 60;
                t->minute %= 60;
        }
        if (t->hour >= 24)
                t->hour %= 24;
}
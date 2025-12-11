#include <stdio.h>

int main()
{

    int x = 10;
    int *p3 = &x;
    int **p2 = &p3;
    int ***p1 = &p2;

    printf("Address held by p3 is %lu and the vlaue of x is %d\n", p3, *p3);
    printf("Address held by p2 is %lu and the vlaue of x is %d\n", p2, **p2);
    printf("Address held by p1 is %lu and the vlaue of x is %d\n", p3, ***p1);
    return 0;
}
#include <stdio.h>

int main(){

        int *p, n;
        printf("Enter the size of the array A: ");
        scanf("%d", &n);

        int a[n];
        p = a;
        printf("Enter %d elements with a space: ", n);
        for(int i=0;i<n;++i) scanf("%d", (p+i));

        //TO DISPLAY THE ELEMENTS
        printf("The elements of the array A are\n");
        for(int i=0;i<n;++i) printf("%d ", *(p+i));
        printf("\n");
        //DISPLAY IN REVERSE ORDER
        printf("Elements in reverse order are\n");
        for(int i=n-1;i>=0;--i) printf("%d ", *(p+i));
        printf("\n");
        return 0;
}
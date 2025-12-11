#include <stdio.h>

void Read(int  *p, int size){
        for(int i=0;i<size;++i) scanf("%d", (p+i));
}

void Display(int *p, int size){
        for(int i=0;i<size;++i) printf("%d ", *(p+i));
}

void rev(int *p, int size){
        int i=0, j = size - 1;
        while(i<j){
                int temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
                i++;
                j--;
        }
}

int main(){

        int *p, n;
        printf("Enter the size of the array A: ");
        scanf("%d", &n);

        int a[n];
        p = a;
        printf("Enter the elements of the array\n");
        Read(p, n);

        printf("Elements before reversing\n");
        Display(p, n);
        printf("\n");

        printf("After reversing\n");
        rev(p, n);
        Display(p, n);

        printf("\n");
        return 0;
}
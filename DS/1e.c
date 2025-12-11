#include <stdio.h>
void Strcat(char *ps1, char *ps2)
{
        while (*ps1 != '\0')
        {
                ps1++;
        }
        while (*ps2 != '\0')
        {
                *ps1 = *ps2;
                ps1++;
                ps2++;
        }
        *ps1 = '\0';
}
int main()
{
        char str1[100], str2[100];
        char *ps1 = str1;
        char *ps2 = str2;
        printf("Enter the first string: ");
        scanf("%s", ps1);
        printf("Enter the second string: ");
        scanf("%s", ps2);
        Strcat(ps1, ps2);
        printf("\n Concatenated string is : %s \n", ps1);
        return 0;
}
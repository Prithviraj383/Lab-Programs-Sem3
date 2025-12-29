#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define Max 100

char stack[Max];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    return stack[top--];
}
int precedence(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}
void infixToPostfix(char infix[], char postfix[])
{
    char ch, x;
    int i = 0, j = 0;
    while ((ch = infix[i++]) != '\0')
    {
        if (isalnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')')
            while ((x = pop()) != '(')
                postfix[j++] = x;
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int evalPostfix(char postfix[])
{
    int stack2[Max];
    int top2 = -1, i;
    char ch;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
            stack2[++top2] = ch - '0';
        else
        {
            int b = stack2[top2--];
            int a = stack2[top2--];
            switch (ch)
            {
            case '+':
                stack2[++top2] = a + b;
                break;
            case '-':
                stack2[++top2] = a - b;
                break;
            case '*':
                stack2[++top2] = a * b;
                break;
            case '/':
                stack2[++top2] = a / b;
                break;
            }
        }
    }
    return stack2[top2];
}

int main()
{
    int choice;
    char infix[Max], postfix[Max];
    while (1)
    {
        printf("\n---MENU (Infix -> Postfix)---\n");
        printf("1.Convert Infix to Postfix\n2.Evaluate Postfix Expression\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Infix Expression: ");
            scanf("%s", infix);
            infixToPostfix(infix, postfix);
            printf("Postfix Expression: %s\n", postfix);
            break;
        case 2:
            printf("Enter Postfix Expression (single digits only): ");
            scanf("%s", postfix);
            printf("Result = %d \n", evalPostfix(postfix));
            break;
        case 3:
            return 0;
        default:
            printf("Invalid Choice ! Try again\n");
        }
    }
    return 0;
}
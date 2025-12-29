#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    if (top == MAX - 1)
        return;
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void reverse(char str[])
{
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
}

/* Swap '(' ↔ ')' while scanning */
void swapBrackets(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0')
    {

        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '(')
        {
            push(infix[i]);
        }

        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }

        else
        { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }

        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int istack[MAX];
int itop = -1;

void ipush(int v)
{
    if (itop < MAX - 1)
        istack[++itop] = v;
}

int ipop()
{
    if (itop == -1)
        return 0;
    return istack[itop--];
}

/* compute integer power (a^b), b >= 0 */
int int_pow(int a, int b)
{
    int res = 1;
    for (int i = 0; i < b; ++i)
        res *= a;
    return res;
}

/* Evaluate a prefix expression (single-character operands: digits only).
   Returns 1 on success and stores result in *result, otherwise returns 0. */
int evalPrefix(const char prefix[], int *result)
{
    itop = -1; /* reset integer stack */
    int n = strlen(prefix);

    /* scan from right to left */
    for (int i = n - 1; i >= 0; --i)
    {
        char c = prefix[i];

        if (isdigit((unsigned char)c))
        {
            ipush(c - '0'); /* single-digit number */
        }
        else if (isalpha((unsigned char)c))
        {
            /* cannot evaluate variables */
            fprintf(stderr, "Evaluation error: variable '%c' has no value\n", c);
            return 0;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
        {
            if (itop < 1)
            {
                fprintf(stderr, "Evaluation error: invalid prefix expression\n");
                return 0;
            }
            int a = ipop();
            int b = ipop();
            long r = 0;
            switch (c)
            {
            case '+':
                r = (long)a + b;
                break;
            case '-':
                r = (long)a - b;
                break;
            case '*':
                r = (long)a * b;
                break;
            case '/':
                if (b == 0)
                {
                    fprintf(stderr, "Evaluation error: division by zero\n");
                    return 0;
                }
                r = a / b;
                break;
            case '%':
                if (b == 0)
                {
                    fprintf(stderr, "Evaluation error: modulo by zero\n");
                    return 0;
                }
                r = a % b;
                break;
            case '^':
                r = int_pow(a, b);
                break;
            }
            ipush((int)r);
        }
        else
        {
            /* ignore other characters (if any) */
        }
    }

    if (itop != 0)
    {
        fprintf(stderr, "Evaluation error: leftover items on stack\n");
        return 0;
    }
    *result = ipop();
    return *result;
}

int main()
{
    char infix[MAX], prefix[MAX], temp[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    strcpy(temp, infix);

    reverse(temp);
    swapBrackets(temp);

    top = -1;
    infixToPostfix(temp, postfix);

    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix: %s\n", prefix);

    int res = 0;
    int ans = evalPrefix(prefix, &res);
    printf("%d", ans);

    return 0;
}
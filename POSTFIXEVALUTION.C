#include<stdio.h>
#include<ctype.h>
char stack[100];
int top = -1;
void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{

    return stack[top--];
}
int main()
{
    char postfix[100];
    int i;
    int a , b , result;
    printf("enter the postfix expression:");
    scanf("%s", postfix);
    for (i = 0; postfix[i] != '\0';i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - 0);
        }
        else
        {

            b = pop();
            a = pop();
            switch (postfix[i])
            {
            case '+':
                result = a+b;
                break;
            case '-':
                result = a-b;
                break;
            case '*':
                result = a*b;
                break;
            case '/':
                result = a/b;
                break;
            default :
                printf("invalid expression");
                return 0;
            }
            push(result);
        }

    }
    result = pop();
    printf("result = %d\n", result);
    return 0;
}

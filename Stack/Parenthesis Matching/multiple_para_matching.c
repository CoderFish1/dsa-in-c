#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};
int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *sp, char val)
{
    if (isFull(sp))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = val;
        printf("Pushed %c to the stack.\n", val);
    }
}
int pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        char val = sp->arr[sp->top];
        sp->top--;
        printf("Popped %c to the stack.\n", val);
        return val;
    }
}
int match(char a, char b)
{
    if (a == '{' && b == '}' || a == '(' && b == ')' || a == '[' && b == ']')
    {
        return 1;
    }
}

int paranthesisMatch(char *exp)
{
    struct stack *s = (struct stack *)malloc(s->size * sizeof(struct stack));
    s->top = -1;
    s->size = 5;
    s->arr = (char *)malloc(sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                char popped_ch = pop(s);
                if (!match(popped_ch, exp[i]))
                {
                    return 0;
                }
            }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    char *exp = "{[a+(b*c)]";
    int p = paranthesisMatch(exp);
    if (p == 1)
    {
        printf("Expression Balanced!\n");
    }
    else
    {
        printf("Expression Unbalanced!\n");
    }
    return 0;
}
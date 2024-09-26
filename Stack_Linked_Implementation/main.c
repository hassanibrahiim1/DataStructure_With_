#include "stack.h"
#include <stdio.h>

void printentry (StackEntry e)
{
    printf("%d\n", e);
}

int main()
{
    Stack s ;
    InitStack(&s);
    push(10, &s);
    push(12, &s);
    push(14, &s);
    push(16, &s);
    push(18, &s);
    push(20, &s);
    push(22, &s);

    printf("Our Stack Size = %d and Here is its Elements:\n",Stacksize(&s));
    TraverseStack(&s, printentry);

    printf("\n****************************************************\n");

    printf("Now we will pop last 3 elements : \n");
    for (int i = 0; i < 3; i++)
    {
        printf("pop(%d)\n", pop(&s));
    }
    printf("\n****************************************************\n");
    printf("Now Our Stack Size = %d and Here is TOP Element:\n",Stacksize(&s));
    printf("%d\n", StackTop(&s));
    printf("Here is ALL Elements: \n");
    TraverseStack(&s, printentry);
    printf("\n****************************************************\n");
    push(24, &s);
    printf("our stack size after push(24) = %d and its element :\n ",Stacksize(&s));
    TraverseStack(&s, printentry);
    printf("\n****************************************************\n");
    printf("Now We will clear our Stack\n");
    CLearStack(&s);
    printf("Stack size now = %d", Stacksize(&s));
    printf("\n****************************************************\n");


}
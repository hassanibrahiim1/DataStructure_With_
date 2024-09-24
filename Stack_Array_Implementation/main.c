#include<stdio.h>
#include "stack.h"

void PrintElement(StackEntry e)
{
    /*Here We Used "%d" because we know that DataType of StackEntry is INT*/
    printf("%d\t", e);
}
void (*pf)(int) = PrintElement ;

int main()
{
	int temp;
    Stack s;
    InitStack(&s);
    while(1)
    {	
        if(!IsStackFull(&s)){
	printf("Please Enter Element to Push in Stack :\t");
	scanf("%d", &temp);	
	push(temp, &s);
        }
        else
        {
        	printf("Sorry Stack is FULL\n");
        	break ;
        }
    }
    printf("Our Stack contains : \n");
    TraverseStack(&s, pf);
    
    int element = pop(&s);
    printf("Last Element has popped = %d \n",element);
	printf("\nNow Our Stack contains : \n");
    TraverseStack(&s, pf);
    
    return 0;
}

#include "stack.h"

void InitStack(Stack *ps)
{
    ps->top = 0 ;
}
void push(StackEntry e, Stack *ps) 
{
    ps->arr[(ps->top)++] = e;
}

StackEntry pop(Stack *ps)
{
    return ps->arr[--ps->top];
}
int IsStackEmpty(Stack *ps)
{
    return ( ps->top <= 0 ) ;
}
int IsStackFull(Stack *ps)
{
    return ( ps->top >= MAXSTACK);
}
StackEntry StackTop(Stack *ps)
{
    return ps->arr[ps->top -1 ];
}
int Stacksize(Stack *ps)
{
    /*Returns How Many Stored Elements in Stack*/
    return ps->top;
}
void CLearStack(Stack *ps)
{
    ps->top = 0 ;
}
void TraverseStack(Stack *ps, void (*pf)(StackEntry))
{
    for(int i = 0 ; i < ps->top ; i++)
    {
        pf(ps->arr[i]);
    }
}

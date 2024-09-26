#include "stack.h"
#include<stdlib.h>

void InitStack(Stack *ps){
    ps->top = NULL;
    ps->size = 0;
}
int IsStackFull (Stack *ps){
    return 0;
}
void push (StackEntry e, Stack* ps)
{
    StackNode *pn = (StackNode*) malloc(sizeof(StackNode));
    pn-> next = ps->top;
    ps->top = pn;
    pn->entry = e;
    ps->size++;
}
int IsStackEmpty (Stack *ps){
    return !(ps->top);
}
StackEntry pop (Stack* ps){
    StackNode *pn = ps -> top;
    StackEntry e = pn->entry;
    ps->top = pn -> next;
    free(pn);
    ps->size -- ;
    return e;
}
StackEntry StackTop (Stack *ps) /*Just return the value of top element without popping it*/
{
    return ps->top->entry;
} 
void CLearStack(Stack *ps)
{
    StackNode *pn ;
    while (ps->top) {
        pn = ps -> top;
        ps->top = pn->next;
        free(pn);
    }
    ps->size = 0;
}
void TraverseStack(Stack *ps, void(*pf)(StackEntry))
{
    StackNode *pn = ps->top ;
    while (pn) {
    pf(pn->entry);
    pn = pn->next;
    }
}
int Stacksize (Stack *ps)
{
    return ps->size;
}
#ifndef CCEDCB59_0C20_4FE0_8073_438B931B0960
#define CCEDCB59_0C20_4FE0_8073_438B931B0960
/********************** Please Define Your StackEntry DataType and Stack Max size *******************/
//#define MAXSTACK 10
typedef int StackEntry ;
/****************************************************************************************************/

typedef struct stacknode{
    StackEntry entry;
    struct stacknode * next;
}StackNode;

typedef struct stack{
    StackNode * top;
    int size ;
} Stack;

void InitStack(Stack *ps);
void push (StackEntry e, Stack* ps);
StackEntry pop (Stack* ps);
int IsStackEmpty (Stack *ps);
int IsStackFull (Stack *ps);
StackEntry StackTop (Stack *ps); /*Just return the value of top element without popping it*/
int Stacksize (Stack *ps);
void CLearStack(Stack *ps);
void TraverseStack(Stack *ps, void(*pf)(StackEntry));

#endif /* CCEDCB59_0C20_4FE0_8073_438B931B0960 */

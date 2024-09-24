#ifndef DFC9D3B4_826F_40E1_B65E_E77D4C39CF06
#define DFC9D3B4_826F_40E1_B65E_E77D4C39CF06

/********************** Please Define Your StackEntry DataType and Stack Max size *******************/
#define MAXSTACK 10
typedef int StackEntry ;
/****************************************************************************************************/


typedef struct stack{
    int arr[MAXSTACK];
    StackEntry top ;
} Stack;

void InitStack(Stack *ps);
void push (StackEntry e, Stack* ps);
StackEntry pop (Stack* ps);
int IsStackEmpty (Stack *ps);
int IsStackFull (Stack *ps);
StackEntry StackTop (Stack *ps);
int Stacksize (Stack *ps);
void CLearStack(Stack *ps);
void TraverseStack(Stack *ps, void(*pf)(StackEntry));

#endif /* DFC9D3B4_826F_40E1_B65E_E77D4C39CF06 */

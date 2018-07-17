
/*Create binary search tree and implement Preorder, Inorder, Postorder and deletion recursively*/
#include<stdio.h>
#include<stdlib.h>
#define N NULL//using macro to define N as NULL throughout the program
typedef struct BST//defining structure
{
    int d;
    struct BST *l,*r;
}tree;//defining data type
tree* gn(int data)//get node function to get the node and place the desired value
{
    tree *x=(tree*)malloc(sizeof(tree));//allocating memory for node
    x->d=data;//placing data in node
    return x;//returning node by allocating memory
}
void insert(tree **root,int z)//definition of insert function
{
    if(*root==N)//null checking
    {
        *root=gn(z);//calling get node function and placing the value at proper position
        (*root)->l=(*root)->r=N;//putting null in its left and right child
    }
    else if((*root)->d > z)//if data is less than root data then we are calling the same function with its left child node
        insert(&((*root)->l),z);
    else if((*root)->d < z)//if data is greater than root data then we are calling the same function with its right child node
        insert(&((*root)->r),z);
}
typedef struct st//defining structure for stack
{
    tree **a;
    int size,tos;
}stack;
void init(stack *s,int n)//initial fill the stack
{
    s->a=(tree **)malloc(n*(sizeof(tree)));//allocating memory dynamically
    s->tos=-1;
    s->size=n;
}
int isempty(const stack *s)//checking empty
{
    if(s->tos==-1)
        return 1;
    else
        return 0;
}
int isfull(const stack *s)//checking full
{
    if(s->tos==s->size-1)
        return 1;
    else
        return 0;
}
void push(stack *s,tree *z)//inserting the elements
{
    if(isfull(s))
        return;
    else
    {
        s->tos++;
        s->a[s->tos]=z;
    }
}
tree* pop(stack *s)//popping the element
{
    tree *z;
    if(isempty(s))
        return;
    else
    {
        z=s->a[s->tos];
        s->tos--;
        return z;
    }
}
tree *peek(stack *s)//looking for the top most element
{
    if(!isempty(s))
       return;
    else
        return(s->a[s->tos]);
}
void preorder(tree *root)
{
    stack s;
    init(&s,10);
    while(root != N)
    {
        printf(" %d",root->d);
        if(root->r!=N)
            push(&s,root->r);
        if(root->l != N)
            root=root->l;
        else
            root=pop(&s);
    }
}
void inorder(tree *root)
{
    stack s;
    init(&s,10);
    while(1)
    {
        while(root!=N)
        {
            push(&s,root);
            root=root->l;
        }
        if(!isempty(&s))
        {
            root=pop(&s);
            printf(" %d",root->d);
            root=root->r;
        }
        else
            break;
    }
}
void postorder(tree *root)
{
    stack s,t;
    init(&s,10);
    init(&t,10);
    tree *left,*right,*f;
    left->d=1;
    left->l=left->r=N;
    right->d=2;
    right->l=right->r=N;
    do
    {
        while(root!=N)
        {
            push(&s,root);
            push(&t,left);
            root=root->l;
        }
        if(!isempty(&s))
        {
            f=pop(&t);
            if(f==left)
            {
                push(&t,right);
                root=(peek(&s))->r;
            }
            else
            {
                root=pop(&s);
                printf(" d",root->d);
                root=N;
            }
        }
    }while(!isempty(&s));
}
int main()
{
    int choice,data;//variable declaration of int type
    char ch;//variable declaration of char type
    tree *root=N,*t=N;//declaration oinit(&s,10);f root in tree
    printf("Enter your data to create binary search tree.. and 0 to terminate the tree\n");
    while(1)//infinite while loop
    {
        fflush(stdin);
        scanf("%d",&data);
        if(data!=0)
            insert(&root,data);//calling insert function
        else
            break;
    }
    printf("inorder traversal : ");
    inorder(root);
    printf("\n");
    printf("postorder traversal : ");
    postorder(root);
    printf("\n");
    printf("preorder traversal : ");
    preorder(root);

   return 0;
}

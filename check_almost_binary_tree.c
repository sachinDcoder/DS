#include<stdio.h>
#include<stdlib.h>
#define N NULL
typedef struct tr
{
    int data;
    struct tr *r,*l;
}tree;
typedef struct Queue
{
    tree *d;
    struct Queue *n;
}node;
tree *gn_tree(int z)
{
    tree *x=(tree*)malloc(sizeof(tree));
    x->data=z;
    return x;
}
node* gn_node(tree *z)
{
    node *x=(node*)malloc(sizeof(node));
    x->d=z;
    return x;
}
void enqueue(node **r,tree *z)
{
    node *t=gn_node(z);
    if(*r==N)
    {
        t->n=t;
    }
    else
    {
        t->n=(*r)->n;
        (*r)->n=t;
    }
    *r=t;
}
tree* dequeue(node **r)
{
    tree *z=(*r)->n->d;
    if(*r==N)
        return N;
    else
    {
        node *t=(*r)->n;
        if((*r)->n==*r)
            *r=N;
        else
            (*r)->n=t->n;
        free(t);
    }
    return z;
}
int isempty(node *r)
{
    if(r==N)
        return 1;
    else
        return 0;
}
int checkAlmostCompBinaryTree(tree *root)
{
    if(root==N)
        return;
    node *r=N;
    enqueue(&r,root);
    int nullF=0;
    while(!isempty(r))
    {
        tree *temp=dequeue(&r);
        if(nullF==1&&(temp->l!=N||temp->r!=N)) return 0;
        if(temp->l==N && temp->r!=N)
            return 0;
        if(temp->l==N||temp->r==N) nullF=1;
        if(temp->l!=N)
            enqueue(&r,temp->l);
        if(temp->r!=N)
            enqueue(&r,temp->r);
    }
    return 1;
}
void insert(tree **root,int z)
{
    if(*root==N)
    {
        tree *t=gn_tree(z);
        t->l=N;
        t->r=N;
        *root=t;
    }
    else if(z<(*root)->data)
        insert(&((*root)->l),z);
    else if(z>(*root)->data)
        insert(&((*root)->r),z);
}
void levelorder(tree *root)
{
    if(root==N)
        return;
    node *r=N;
    enqueue(&r,root);
    while(!isempty(r))
    {
        tree *temp=dequeue(&r);
        printf("%4d",temp->data);
        if(temp->l!=N)
            enqueue(&r,temp->l);
        if(temp->r!=N)
            enqueue(&r,temp->r);
    }
}
void inorder(tree *root)
{
    if(root==N)
        return;
    else
    {
        inorder(root->l);
        printf("%4d",root->data);
        inorder(root->r);
    }
}
int main()
{
    int data;
    tree *root=N;
    printf("Insert your data.. 0 to terminate : \n");
    do
    {
        scanf("%d",&data);
        if(data==0)
            break;
        insert(&root,data);
    }while(1);
    printf("\nlevel order : ");
    levelorder(root);
    printf("\ninorder : ");
    inorder(root);
    if(checkAlmostCompBinaryTree(root))
        printf("\nYes");
    else
        printf("\nNo");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct BSTNode
{
    int data;
    struct BSTNode *left,*right;
};
void insert(struct BSTNode *root,int data)
{
    struct BSTNode *n=malloc(sizeof(struct BSTNode));
    struct BSTNode *par;
    n->left=NULL;
    n->data=data;
    n->right=NULL;
    if(root==NULL)
        root=n;
    else
    {
        par=root;
        while(par!=NULL)
        {
            if(par->data>data)
            {
                if(par->left==NULL)
                    par->left=n;
                par=par->left;
            }
            else if(par->data<data)
            {
                if(par->right==NULL)
                    par->right=n;
                par=par->right;
            }
        }
    }
}
/*void perOrder(struct BSTNode *root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}*/
int main()
{
    int data,i;
    struct BSTNode *root=NULL;
    for(i=0;i<4;i++)
    {
        printf("enter a data :");
        scanf("%d",&data);
        insert(root,data);
    }
    /*perOrder(root);*/
    return 0;
}









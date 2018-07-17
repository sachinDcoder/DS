#include<stdio.h>
#include<stdlib.h>
struct ArrayQueue
{
    int front,rear;
    int capacity;
    int *array;
};
struct ArrayQueue* createQueue(int capacity)
{
    struct ArrayQueue *Q;
    Q=(struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));
    if(Q==NULL)
        return NULL;
    Q->capacity=capacity;
    Q->front=Q->rear=-1;
    Q->array=(int *)malloc(Q->capacity*sizeof(int));
    if(Q->array==NULL)
        return NULL;
    return Q;
}
int emptyQueue(struct ArrayQueue *Q)
{
    return(Q->front==-1);
}
int fullQueue(struct ArrayQueue *Q)
{
    return((Q->rear+1)%Q->capacity==Q->front);
}
int QueueSize(struct ArrayQueue *Q)
{
    return((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}
void enQueue(struct ArrayQueue *Q,int data)
{
    if(fullQueue(Q))
        printf("Overflow");
    else
    {
        Q->rear=(Q->rear+1)%Q->capacity;
        Q->array[Q->rear]=data;
        if(Q->front==-1)
            Q->front=Q->rear;
    }
}
int deQueue(struct ArrayQueue *Q)
{
    int data=-1;
    if(emptyQueue(Q))
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        data=Q->array[Q->front];
        if(Q->front==Q->rear)
            Q->front=Q->rear=-1;
        else
            Q->front=(Q->front+1)%Q->capacity;
    }
    return data;
}
void deleteQueue(struct ArrayQueue *Q)
{
    if(Q)
    {
        if(Q->array)
        {
            free(Q->array);
        }
        free(Q);
    }
}
void viewQueue(struct ArrayQueue *Q)
{
    int i;
    printf("\n");
    for(i=Q->front;i<=Q->rear;i++)
        printf("%d\t",Q->array[i]);
}
int main()
{
    int choice,cap,data;
    printf("1. create Queue(a queue is required before any other operation to be done on the queue\n");
    printf("2. insert an element in the queue Queue\n");
    printf("3. delete an element from the Queue\n");
    printf("4. delete the whole Queue\n");
    printf("5. view Queue\n");
    printf("6. exit\n");
    while(1)
    {
        printf("\nEnter your choice : ");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the capacity of the Queue : ");
                scanf("%d",&cap);
                if(createQueue(cap)!=NULL)
                     printf("\nQueue has been created successfully");
                break;
            case 2:
                printf("\nEnter the data to be inserted : ");
                scanf("%d",&data);
                enQueue(createQueue(cap),data);
                break;
            case 3:
                deQueue(createQueue(cap));
                break;
            case 4:
                deleteQueue(createQueue(cap));
                break;
            case 5:
                viewQueue(createQueue(cap));
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}

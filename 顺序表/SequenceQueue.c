#include"SequenceQueue.h"
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    Queue queue;
    init(&queue);

    insert(&queue,2);
    insert(&queue,5);
    insert(&queue,1);
    insert(&queue,6);
    insert(&queue,8);
    show(&queue);

    returnHead(&queue);
    return 0;
}

void init(PointQueue queue)
{
    queue->front=0;
    queue->rear=0;
    queue->front=queue->rear;
}

void insert(PointQueue queue,int value)
{
    if (isFull(queue))
    {
        printf("Queue is Full\n");
        exit(-1);
    }

    queue->queueArr[queue->rear]=value;
    queue->rear=queue->rear+1;
    
}

void out(PointQueue queue,int value)
{
    if (isEmpty(queue))
    {
            printf("Queue is Empty\n");
            exit(-1);
    }

    value=queue->queueArr[queue->front];
    queue->front=(queue->front+1);
    printf("删除的元素是:%d\n",value);
}

void returnHead(PointQueue queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        exit(-1);
    }

    int value=queue->queueArr[queue->front];
    printf("队头元素是:%d\n",value);
    
}

void show(PointQueue queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        exit(-1);
    }

    while (queue->front<queue->rear)
    {
        printf("%d ",queue->queueArr[queue->front]);
        queue->front++;
    }
    printf("\n");
}

bool isFull(PointQueue queue)
{
    if (queue->rear==Max)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool isEmpty(PointQueue queue)
{
    if (queue->front==queue->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
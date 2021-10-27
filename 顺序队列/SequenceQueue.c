#include"SequenceQueue.h"
#include<stdio.h>
#include<stdlib.h>

/*
    队列
        只允许在一端插入数据操作，在另一端进行删除数据操作的特殊线性表，
        进行插入操作的一端称为队尾（入队），进行删除操作的一端称为队头（出队），
        队列具有先进先出（FIFO）的特性。
    --------------------------------------------------------------------------------
    队列的基本操作
        入队，在队尾（rear）添加元素
        出队，将队头（front）删除
        读取队列，输出队头元素
    --------------------------------------------------------------------------------
*/
int main(void)
{
    Queue queue;
    init(&queue);
    insert(&queue,2);
    insert(&queue,5);
    insert(&queue,1);
    insert(&queue,6);
    insert(&queue,8);
    // show(&queue);

    returnHead(&queue);
    return 0;
}

void init(PointQueue queue)
{
    queue->front=0;//初始化队头元素
    queue->rear=0;//初始化队尾元素
    queue->front=queue->rear;//队头等于队尾时，队列为空
}

void insert(PointQueue queue,int value)
{
    if (isFull(queue))//使用数组为base的队列存在着元素溢出情况，需要判断队列是否为满才能进行入队操作
    {
        printf("Queue is Full\n");
        exit(-1);
    }

    queue->queueArr[queue->rear]=value;//将第一个元素插入队尾
    queue->rear=queue->rear+1;//队尾+1继续插入下一个元素
    //队尾本质就是队头，只是描述不同，方便操作
}

void out(PointQueue queue,int value)
{
    if (isEmpty(queue))//队列判空
    {
            printf("Queue is Empty\n");
            exit(-1);
    }

    value=queue->queueArr[queue->front];//临时变量保存出队元素
    queue->front=(queue->front+1);//队头+1进行出队，将下标移动至下一位元素
    printf("删除的元素是:%d\n",value);
}

void returnHead(PointQueue queue)
{
    if (isEmpty(queue))//队列判空
    {
        printf("Queue is Empty\n");
        exit(-1);
    }

    int value=queue->queueArr[queue->front];//输出队头元素，front=0，下标为0
    printf("队头元素是:%d\n",value);
    
}

void show(PointQueue queue)
{
    if (isEmpty(queue))//队列判空
    {
        printf("Queue is Empty\n");
        exit(-1);
    }

    while (queue->front<queue->rear)//如果队头等于队尾时
    {
        printf("%d ",queue->queueArr[queue->front]);//输出队列头元素，front=0等价于queueArr[0]
        queue->front++;//队列头+1，移向下一个元素
    }
    printf("\n");
}

bool isFull(PointQueue queue)
{
    if (queue->rear==Max)
    {
        //当队头等于队列最大长度时，队列为满
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
        //当队头等于队尾时，队列为空
        return true;
    }
    else
    {
        return false;
    }
}
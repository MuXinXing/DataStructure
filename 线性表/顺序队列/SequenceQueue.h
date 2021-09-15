#pragma
#ifndef SEQUENCEQUEUE_H
#define SEQUENCEQUEUE_H
#include<stdbool.h>

#define Max 20
typedef struct Queue
{
    int queueArr[Max];
    int front;//队头
    int rear;//队尾
}* PointQueue,Queue;

void init(PointQueue queue);//初始化队列
void insert(PointQueue queue,int value);//插入、入队
void out(PointQueue queue,int value);//删除、出队
void returnHead(PointQueue queue);//返回队头元素
void show(PointQueue queue);//显示队列
bool isEmpty(PointQueue queue);//判断队列是否为空
bool isFull(PointQueue queue);//判断队列是否为满

#endif //SEQUENCEQUEUE_H
#pragma
#ifndef SEQUENCEQUEUE_H
#define SEQUENCEQUEUE_H
#include<stdbool.h>

#define Max 20
typedef struct Queue
{
    int queueArr[Max];
    int front;
    int rear;
}* PointQueue,Queue;

void init(PointQueue queue);
void insert(PointQueue queue,int value);
void out(PointQueue queue,int value);
void returnHead(PointQueue queue);
void show(PointQueue queue);
bool isEmpty(PointQueue queue);
bool isFull(PointQueue queue);

#endif //SEQUENCEQUEUE_H
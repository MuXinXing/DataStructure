#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main(void)
{
    PointNode pointHead;

    return 0;
}

PointNode init()
{
    PointNode pointHead = (PointNode)malloc(sizeof(Node));
    if (pointHead == NULL)
    {
        exit(-1);
        printf("pointHead malloc failed\n");
    }

    pointHead->data = 0;
    pointHead->prior = pointHead;
    pointHead->next = NULL;
    
    return pointHead;
}

PointNode insert(PointNode pointHead,int value)
{
    PointNode pointNew = (PointNode)malloc(sizeof(Node));
    PointNode pointTail = pointHead->next;
    if (pointNew == NULL)
    {
        exit(-1);
        printf("pointNew malloc failed\n");
    }

    
    pointNew->data = value;
    pointHead->next = pointNew;

    pointNew->prior = pointHead->next;
    pointNew->next = pointTail->next;
}

void deleted(PointNode pointHead)
{

}

void show(PointNode pointHead)
{
    PointNode p=pointHead->next;
    while (p != NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}

bool isEmpty(PointNode pointHead)
{
   
}


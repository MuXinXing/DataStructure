#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main(void)
{
    PointNode pointHead;

    return 0;
}

void init(int len)
{
    int i=0;
    int value;
    PointNode pointNode = (PointNode)malloc(sizeof(Node));
    PointNode pointNew = (PointNode)malloc(sizeof(Node));
    PointNode pointTail = pointNode;
    if (pointNode == NULL)
    {
        printf("malloc filed!\n");
        exit(-1);
    }
    pointNode->prior=NULL;
    pointNode->next=NULL;
    
    printf("请输入链表长度:\n");
    scanf("%d",&len);
    for ( i = 1; i < len; i++)
    {
        printf("请输入第%d个元素:\n",len);
        scanf("%d",&value);
        pointNode->data=value;
        pointNode->next=pointNew;
        pointTail=pointNew;
        pointNode->next->prior=pointNode->next;
        len++;
    }
}

PointNode insert(PointNode pointNode,int position,int value)
{
    
}

void deleted(PointNode pointNode)
{

}

void show(PointNode pointNode)
{

}

bool isEmpty(PointNode pointNode)
{
   
}


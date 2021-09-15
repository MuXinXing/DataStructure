#ifndef LIST_H
#define LIST_H
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node* prior;
    struct Node* next;
}*PointNode,Node;

void init(int len);
PointNode insert(PointNode pointNode,int position,int value);
void deleted(PointNode pointNode);
void show(PointNode pointNode);
bool isEmpty(PointNode pointNode);

#endif //LIST_H
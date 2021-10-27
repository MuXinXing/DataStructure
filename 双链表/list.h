#ifndef LIST_H
#define LIST_H
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node* prior;
    struct Node* next;
}*PointNode,Node;

PointNode init();
PointNode insert(PointNode pointHead,int value);
void deleted(PointNode pointHead);
void show(PointNode pointHead);
bool isEmpty(PointNode pointHead);

#endif //LIST_H
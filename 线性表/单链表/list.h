#pragma once
#ifndef LIST_H
#define LIST_H
typedef struct Node {
	int data;//数据区
	struct Node* next;//指针域
}*PointNode,Node;
//*PointNode相当于定义了一个Node类型的指针，Node相当于定义了一个Node类型的变量

PointNode create(int len);
void delete(PointNode pointHead, int position);
void insert(PointNode pointHead, int position, int value);
void showList(PointNode pointHead);
void isEmpty(PointNode pointHead);
int length(PointNode pointHode);
void sort(PointNode pointHead);
#endif // !LIST_H
//除需要操作的链表的返回值为PointNode，其他操作函数返回值随意，方便操作即可
#pragma
#ifndef STACK_H
#define SATCK_H
#include<stdbool.h>
typedef struct Node
{
	//链表操作结构体，提供栈操作
	int data;//数据域
	struct Node* next;//指针域
}Node, * PointNode;

typedef struct Stack
{
	PointNode Bottom;//栈尾
	PointNode Top;//栈顶
}Stack, * PointStack;

void init(PointStack pointStack);//初始化栈操作
void push(PointStack pointStack, int value);//入栈操作
void show(PointStack pointStack);//显示栈元素
void clear(PointStack pointStack);//清空栈
bool pop(PointStack pointStack);//出栈操作
bool isEmpty(PointStack pointStack);//判断栈是否为空
#endif // STACK_H

#pragma
#ifndef STACK_H
#define SATCK_H
#include<stdbool.h>
typedef struct Node
{
	//��������ṹ�壬�ṩջ����
	int data;//������
	struct Node* next;//ָ����
}Node, * PointNode;

typedef struct Stack
{
	PointNode Bottom;//ջβ
	PointNode Top;//ջ��
}Stack, * PointStack;

void init(PointStack pointStack);//��ʼ��ջ����
void push(PointStack pointStack, int value);//��ջ����
void show(PointStack pointStack);//��ʾջԪ��
void clear(PointStack pointStack);//���ջ
bool pop(PointStack pointStack);//��ջ����
bool isEmpty(PointStack pointStack);//�ж�ջ�Ƿ�Ϊ��
#endif // STACK_H

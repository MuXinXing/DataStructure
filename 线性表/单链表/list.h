#pragma once
#ifndef LIST_H
#define LIST_H
typedef struct Node {
	int data;//������
	struct Node* next;//ָ����
}*PointNode,Node;
//*PointNode�൱�ڶ�����һ��Node���͵�ָ�룬Node�൱�ڶ�����һ��Node���͵ı���

PointNode create(int len);
void delete(PointNode pointHead, int position);
void insert(PointNode pointHead, int position, int value);
void showList(PointNode pointHead);
void isEmpty(PointNode pointHead);
int length(PointNode pointHode);
void sort(PointNode pointHead);
#endif // !LIST_H
//����Ҫ����������ķ���ֵΪPointNode������������������ֵ���⣬�����������
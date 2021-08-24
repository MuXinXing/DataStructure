#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include<stdbool.h>
struct Array
{
	int* pointBase;//����Ԫ�ص�ַָ�룬ָ���һ��Ԫ�ص�ַ
	int len;//���鳤��
	int count;//������ЧԪ�ظ���
};

void init(struct Array *pointArr,int len);//��ʼ���������
bool append(struct Array* pointArr,int value);//����������Ԫ��
bool insert(struct Array* pointArr,int position,int value);//����Ԫ�ز���
int delete(struct Array* pointArr, int position);//����Ԫ��ɾ��
int get(struct Array* pointArr,int position);//��ȡ����Ԫ��
bool isEmpty(struct Array* pointArr);//�ж������Ƿ�Ϊ��
bool isFull(struct Array* pointArr);//�ж������Ƿ�Ϊ��
void sort(struct Array* pointArr);//�������������
void show(struct Array* pointArr);//��ʾ��������Ԫ��
void inversion(struct Array* pointArray);//������Ԫ�ؽ��з�ת
#endif // !ARRAY_H
/*
	���ں�������ֵ������ֵ�������ã�����淶�ͷ���ʹ�ü���
*/
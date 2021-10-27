#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include<stdbool.h>
struct Array
{
	int* pointBase;//数组元素地址指针，指向第一个元素地址
	int len;//数组长度
	int count;//数组有效元素个数
};

void init(struct Array *pointArr,int len);//初始化数组操作
bool append(struct Array* pointArr,int value);//给数组增加元素
bool insert(struct Array* pointArr,int position,int value);//数组元素插入
int delete(struct Array* pointArr, int position);//数组元素删除
int get(struct Array* pointArr,int position);//获取数组元素
bool isEmpty(struct Array* pointArr);//判断数组是否为空
bool isFull(struct Array* pointArr);//判断数组是否为满
void sort(struct Array* pointArr);//对数组进行排序
void show(struct Array* pointArr);//显示所有数组元素
void inversion(struct Array* pointArray);//对数组元素进行反转
#endif // !ARRAY_H
/*
	关于函数返回值：返回值任意设置，满足规范和方便使用即可
*/
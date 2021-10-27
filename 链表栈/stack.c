#pragma warning(disable:4996)
#pragma warning(disable:6011)
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
/*
	栈是限制插入删除只能在一个位置上的表，这个插入删除的位置是表尾，即栈顶。
	栈的基本操作有Push(进栈)插入操作,Pop(出栈)删除操作，且不能对空栈进行进栈出栈操作。
	栈元素是先进后出后进先出的表(LIFO表)。
	栈是一个表，任何能创建表的方法都能创建栈，可以是指针也可以是数组，链表栈没有大小限制。
*/
int main(void)
{
	Stack stack;
	init(&stack);
	push(&stack, 1);
	push(&stack, 3);
	push(&stack, 5);
	push(&stack, 7);
	show(&stack);

	pop(&stack);
	pop(&stack);
	pop(&stack);
	pop(&stack);
	show(&stack);

	clear(&stack);
	push(&stack, 3);
	push(&stack, 2);
	push(&stack, 1);
	show(&stack);
}

void init(PointStack pointStack)
{
	pointStack->Top = (PointNode)malloc(sizeof(Node));
	//给栈顶初始化内存
	if (pointStack->Top == NULL)
	{
		//判断栈顶内存是否分配成功
		printf("malloc faile\n");
		exit(-1);
	}
	else
	{
		pointStack->Bottom = pointStack->Top;
		//将栈尾指向栈顶，设置空栈
		pointStack->Top->next = NULL;
		//将栈的第一个元素Top->next置空，防止指针乱跑
		//Top作为头指针是没有元素存放的
	}
}

void push(PointStack pointStack,int value)
{
	PointNode pointNew = (PointNode)malloc(sizeof(Node));
	//给新节点分配内存空间，存放value的值
	pointNew->data = value;
	//将value存入数据域
	pointNew->next = pointStack->Top;
	//将新节点的下一个有效元素指向栈顶
	pointStack->Top = pointNew;
	//将value赋给栈顶
}

void show(PointStack pointStack)
{
	PointNode p = pointStack->Top;
	//设置临时指针p指向栈顶
	while (p != pointStack->Bottom)
	{
		//判断是否是栈尾,!=不是就是是，是就是不是
		printf("%d ", p->data);
		//打印数据域
		p = p->next;
		//继续指向栈的下一个节点
	}
	printf("\n");
}

bool pop(PointStack pointStack)
{
	if (isEmpty(pointStack))
	{
		return false;
	}
	else
	{
		PointNode p = pointStack->Top;
		//临时指针指向栈顶
		pointStack->Top = p->next;
		//将栈顶指针指向栈顶的下一个有效元素
		free(p);
		//释放p->next当前指向的地址，表示出栈
		p = NULL;
		//将指针置空
		return true;
	}
}

bool isEmpty(PointStack pointStack)
{
	if (pointStack->Top == pointStack->Bottom)
	{
		//判断栈顶是否指向栈底，如果是则为空表
		return true;
	}
	else
	{
		return false;
	}
}

void clear(PointStack pointStack)
{
	if (isEmpty(pointStack))
	{
		exit(-1);
	}
	else
	{
		PointNode p = pointStack->Top;
		//临时指针，指向栈顶
		/*PointNode q = NULL;*/

		while (p != pointStack->Bottom)
		{
			//判断是否为空栈
			p->next = NULL;
			//将栈的下一个有效元素置空，直到Top == Bottom
			free(p);
			p = NULL;
		}

		//while (p != pointStack->Bottom)
		//{
		//	q = p->next;
		//	free(p);
		//	p = q;
		//}
	}
}
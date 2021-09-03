#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6273)
#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main(void)
{
	PointNode pointHead = NULL;

	pointHead = create(5);
	showList(pointHead);

	printf("长度为:%d", length(pointHead));
	printf("\n");

	delete(pointHead, 2);
	insert(pointHead, 4, 20);
	sort(pointHead);
	isEmpty(pointHead);
	return 0;
}

PointNode create(int len)
{
	int i = 0;
	int value = 0;
	PointNode pointHead = (PointNode)malloc(sizeof(Node));
	//给头节点分配内存
	PointNode pointTail;
	//尾节点
	if (pointHead == NULL)
	{
		//判断内存是否分配成功
		printf("Malloc faile..、\n");
		exit(-1);
	}
	pointTail = pointHead;
	//将尾节点指向头节点,即只有一个节点并且始终指向尾节点，
	pointTail->next = NULL;
	//清空pointTail指针域
	for ( i = 0; i < len; i++)
	{
		printf("请输入第%d元素:", i + 1);
		scanf("%d", &value);

		PointNode pointNew = (PointNode)malloc(sizeof(Node));
		//给新节点分配内存，用与存放传入的value值，for每次都给pointNew分配内存，使其唯一
		if (pointNew == NULL)
		{
			//判断新节点内存是否分配成功
			printf("Malloc faile..、\n");
			exit(-1);
		}
		pointNew->data = value;
		//将值赋给新节点中的数据区
		pointTail->next = pointNew;
		//将存放有值的新节点赋给尾节点的下一个节点，相当于将值赋给的pointHead头节点的下一个节点，因为链表的头节点不存放数据
		pointNew->next = NULL;
		//将新节点赋值给尾节点后，置空新节点的指针域，防止野指针
		pointTail = pointNew;
		//将尾节点指向新节点,完成数据存放，使pointNew始终指向pointTail
	}
	return pointHead;
	//关于返回值，所有操作都是基于创建好的链表，所以要将创建完成的链表返回
}

void delete(PointNode pointHead,int position)
{
	int i = 0;
	PointNode p = pointHead;

	while (i < position - 1 && pointHead->next != NULL)
	{
		//判断和寻找要删除的节点的前面的节点是否存在，链表与数组的元素下标都是从0开始
		p = p->next;
		//p->next循环i次寻找节点
		i++;
	}

	if (i > position - 1 || p->next == NULL)
	{
		//判断位置是否合法
		exit(-1);
	}
		
	PointNode q = p->next;
	//创建q节点指向p->next要删除的节点
	int* pointValue = q->data;
	//临时保存被删除的节点中的数据

	p->next = q->next;
	//p直接指向p下一个节点的下一个节点，忽略中间的节点q
 	free(q);
	//将q释放，删除节点
	q = NULL;

	printf("删除的节点是:%d，元素是:%d，结果是:", position, pointValue);
	showList(pointHead);
}

void insert(PointNode pointHead, int position, int value)
{
	int i = 0;
	PointNode p = pointHead;

	while (p != NULL && i < position-1)
	{
		//判断和寻找要插入的节点的前面的节点是否存在，链表与数组的元素下标都是从0开始
		p = p->next;
		//p->next循环i次寻找节点
		i++;
	}

	if (i > position-1 || p == NULL)
	{
		//判断position是否越界
		printf("插入失败，位置有误\n");
		exit(-1);
	}

	PointNode pointNew = (PointNode)malloc(sizeof(Node));
	//创建一个新节点
	if (pointNew == NULL)
	{
		printf("内存分配失败\n");
		exit(-1);
	}

	pointNew->data = value;
	//将值存放至新节点的数据区
	PointNode q = p->next;
	//设置一个p节点的后一个节点
	p->next = pointNew;
	//将p节点的后一个节点指向新节点
	pointNew->next = q;
	//在将新节点的后一个节点变为q，这样形成了p->pNew->q形式，将新节点插入p与q之间

	printf("插入的节点是:%d，元素是:%d，结果是:", position, value);
	showList(pointHead);
}

void showList(PointNode pointHead)
{
	PointNode p = pointHead->next;
	//临时指针，使p指向pointHead头节点的下一个节点，即链表的存放数据区
	while (p != NULL)
	{
		printf("%d ", p->data);
		//访问数据域
		p = p->next;
		//p继续指向p->next的下一个节点
	}
	printf("\n");
}

void isEmpty(PointNode pointHead)
{
	if (pointHead->next == NULL)
	{
		//判断链表的有效数据是否为空
		printf("链表为空\n");
	}
	else
	{
		printf("链表存在\n");
	}
	
}

int length(PointNode pointHead)
{
	int len = 0;
	PointNode p = pointHead->next;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

void sort(PointNode pointHead)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	PointNode p, q;
	int len = length(pointHead);
	for ( i = 0,p=pointHead->next; i < len-1; i++,p=p->next)//p=pointHead->next等价于i=0,遍历链表中第一个元素，p->next等价于i++
	{
		for (j = i+1, q=p->next; j<len;j++,q=q->next)//q=q->next相当于j=j+1,冒泡排序中的后一个元素，q=q->next相当于j++
		{
			if (p->data > q->data)//前一个节点中的数据是否小于后一个节点中的数据
			{
				temp = p->data;//前一个节点中的数据临时存放
				p->data = q->data;//前后节点数据交换
				q->data = temp;//将后一个节点数据换成前一个节点
			}
		}
	}
	printf("排序结果是:");
	showList(pointHead);
}
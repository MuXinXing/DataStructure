#pragma warning(disable:4996)
#pragma warning(disable:6011)
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
/*
	ջ�����Ʋ���ɾ��ֻ����һ��λ���ϵı��������ɾ����λ���Ǳ�β����ջ����
	ջ�Ļ���������Push(��ջ)�������,Pop(��ջ)ɾ���������Ҳ��ܶԿ�ջ���н�ջ��ջ������
	ջԪ�����Ƚ��������ȳ��ı�(LIFO��)��
	ջ��һ�����κ��ܴ�����ķ������ܴ���ջ��������ָ��Ҳ���������飬����ջû�д�С���ơ�
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
	//��ջ����ʼ���ڴ�
	if (pointStack->Top == NULL)
	{
		//�ж�ջ���ڴ��Ƿ����ɹ�
		printf("malloc faile\n");
		exit(-1);
	}
	else
	{
		pointStack->Bottom = pointStack->Top;
		//��ջβָ��ջ�������ÿ�ջ
		pointStack->Top->next = NULL;
		//��ջ�ĵ�һ��Ԫ��Top->next�ÿգ���ָֹ������
		//Top��Ϊͷָ����û��Ԫ�ش�ŵ�
	}
}

void push(PointStack pointStack,int value)
{
	PointNode pointNew = (PointNode)malloc(sizeof(Node));
	//���½ڵ�����ڴ�ռ䣬���value��ֵ
	pointNew->data = value;
	//��value����������
	pointNew->next = pointStack->Top;
	//���½ڵ����һ����ЧԪ��ָ��ջ��
	pointStack->Top = pointNew;
	//��value����ջ��
}

void show(PointStack pointStack)
{
	PointNode p = pointStack->Top;
	//������ʱָ��pָ��ջ��
	while (p != pointStack->Bottom)
	{
		//�ж��Ƿ���ջβ,!=���Ǿ����ǣ��Ǿ��ǲ���
		printf("%d ", p->data);
		//��ӡ������
		p = p->next;
		//����ָ��ջ����һ���ڵ�
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
		//��ʱָ��ָ��ջ��
		pointStack->Top = p->next;
		//��ջ��ָ��ָ��ջ������һ����ЧԪ��
		free(p);
		//�ͷ�p->next��ǰָ��ĵ�ַ����ʾ��ջ
		p = NULL;
		//��ָ���ÿ�
		return true;
	}
}

bool isEmpty(PointStack pointStack)
{
	if (pointStack->Top == pointStack->Bottom)
	{
		//�ж�ջ���Ƿ�ָ��ջ�ף��������Ϊ�ձ�
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
		//��ʱָ�룬ָ��ջ��
		/*PointNode q = NULL;*/

		while (p != pointStack->Bottom)
		{
			//�ж��Ƿ�Ϊ��ջ
			p->next = NULL;
			//��ջ����һ����ЧԪ���ÿգ�ֱ��Top == Bottom
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
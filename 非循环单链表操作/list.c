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

	printf("����Ϊ:%d", length(pointHead));
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
	//��ͷ�ڵ�����ڴ�
	PointNode pointTail;
	//β�ڵ�
	if (pointHead == NULL)
	{
		//�ж��ڴ��Ƿ����ɹ�
		printf("Malloc faile..��\n");
		exit(-1);
	}
	pointTail = pointHead;
	//��β�ڵ�ָ��ͷ�ڵ�,��ֻ��һ���ڵ㲢��ʼ��ָ��β�ڵ㣬
	pointTail->next = NULL;
	//���pointTailָ����
	for ( i = 0; i < len; i++)
	{
		printf("�������%dԪ��:", i + 1);
		scanf("%d", &value);

		PointNode pointNew = (PointNode)malloc(sizeof(Node));
		//���½ڵ�����ڴ棬�����Ŵ����valueֵ��forÿ�ζ���pointNew�����ڴ棬ʹ��Ψһ
		if (pointNew == NULL)
		{
			//�ж��½ڵ��ڴ��Ƿ����ɹ�
			printf("Malloc faile..��\n");
			exit(-1);
		}
		pointNew->data = value;
		//��ֵ�����½ڵ��е�������
		pointTail->next = pointNew;
		//�������ֵ���½ڵ㸳��β�ڵ����һ���ڵ㣬�൱�ڽ�ֵ������pointHeadͷ�ڵ����һ���ڵ㣬��Ϊ�����ͷ�ڵ㲻�������
		pointNew->next = NULL;
		//���½ڵ㸳ֵ��β�ڵ���ÿ��½ڵ��ָ���򣬷�ֹҰָ��
		pointTail = pointNew;
		//��β�ڵ�ָ���½ڵ�,������ݴ�ţ�ʹpointNewʼ��ָ��pointTail
	}
	return pointHead;
	//���ڷ���ֵ�����в������ǻ��ڴ����õ���������Ҫ��������ɵ�������
}

void delete(PointNode pointHead,int position)
{
	int i = 0;
	PointNode p = pointHead;

	while (i < position - 1 && pointHead->next != NULL)
	{
		//�жϺ�Ѱ��Ҫɾ���Ľڵ��ǰ��Ľڵ��Ƿ���ڣ������������Ԫ���±궼�Ǵ�0��ʼ
		p = p->next;
		//p->nextѭ��i��Ѱ�ҽڵ�
		i++;
	}

	if (i > position - 1 || p->next == NULL)
	{
		//�ж�λ���Ƿ�Ϸ�
		exit(-1);
	}
		
	PointNode q = p->next;
	//����q�ڵ�ָ��p->nextҪɾ���Ľڵ�
	int* pointValue = q->data;
	//��ʱ���汻ɾ���Ľڵ��е�����

	p->next = q->next;
	//pֱ��ָ��p��һ���ڵ����һ���ڵ㣬�����м�Ľڵ�q
 	free(q);
	//��q�ͷţ�ɾ���ڵ�
	q = NULL;

	printf("ɾ���Ľڵ���:%d��Ԫ����:%d�������:", position, pointValue);
	showList(pointHead);
}

void insert(PointNode pointHead, int position, int value)
{
	int i = 0;
	PointNode p = pointHead;

	while (p != NULL && i < position-1)
	{
		//�жϺ�Ѱ��Ҫ����Ľڵ��ǰ��Ľڵ��Ƿ���ڣ������������Ԫ���±궼�Ǵ�0��ʼ
		p = p->next;
		//p->nextѭ��i��Ѱ�ҽڵ�
		i++;
	}

	if (i > position-1 || p == NULL)
	{
		//�ж�position�Ƿ�Խ��
		printf("����ʧ�ܣ�λ������\n");
		exit(-1);
	}

	PointNode pointNew = (PointNode)malloc(sizeof(Node));
	//����һ���½ڵ�
	if (pointNew == NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit(-1);
	}

	pointNew->data = value;
	//��ֵ������½ڵ��������
	PointNode q = p->next;
	//����һ��p�ڵ�ĺ�һ���ڵ�
	p->next = pointNew;
	//��p�ڵ�ĺ�һ���ڵ�ָ���½ڵ�
	pointNew->next = q;
	//�ڽ��½ڵ�ĺ�һ���ڵ��Ϊq�������γ���p->pNew->q��ʽ�����½ڵ����p��q֮��

	printf("����Ľڵ���:%d��Ԫ����:%d�������:", position, value);
	showList(pointHead);
}

void showList(PointNode pointHead)
{
	PointNode p = pointHead->next;
	//��ʱָ�룬ʹpָ��pointHeadͷ�ڵ����һ���ڵ㣬������Ĵ��������
	while (p != NULL)
	{
		printf("%d ", p->data);
		//����������
		p = p->next;
		//p����ָ��p->next����һ���ڵ�
	}
	printf("\n");
}

void isEmpty(PointNode pointHead)
{
	if (pointHead->next == NULL)
	{
		//�ж��������Ч�����Ƿ�Ϊ��
		printf("����Ϊ��\n");
	}
	else
	{
		printf("�������\n");
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
	for ( i = 0,p=pointHead->next; i < len-1; i++,p=p->next)//p=pointHead->next�ȼ���i=0,���������е�һ��Ԫ�أ�p->next�ȼ���i++
	{
		for (j = i+1, q=p->next; j<len;j++,q=q->next)//q=q->next�൱��j=j+1,ð�������еĺ�һ��Ԫ�أ�q=q->next�൱��j++
		{
			if (p->data > q->data)//ǰһ���ڵ��е������Ƿ�С�ں�һ���ڵ��е�����
			{
				temp = p->data;//ǰһ���ڵ��е�������ʱ���
				p->data = q->data;//ǰ��ڵ����ݽ���
				q->data = temp;//����һ���ڵ����ݻ���ǰһ���ڵ�
			}
		}
	}
	printf("��������:");
	showList(pointHead);
}
#include"array.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main(void)
{
	struct Array array;

	init(&array, 10);
	append(&array, 8);
	append(&array, 4);
	append(&array, 9);
	append(&array, 43);
	append(&array, 12);
	append(&array, 22);
	append(&array, 61);
	append(&array, 16);
	append(&array, 51);

	//inversion(&array);
	//sort(&array);
	printf("ɾ����ֵ��:%d\n", delete(&array, 2));
	show(&array);
}

void init(struct Array* pointArr,int len)//��ʼ������
{
	pointArr->pointBase = (int*)malloc(sizeof(int) * len);//������Ԫ��ָ���ʼ���������ڴ�ռ䣬ָ��ָ���һ��Ԫ�ص�ַ
	if (pointArr->pointBase == NULL) {//�ж�ָ���Ƿ�Ϊ��
		printf("�ڴ����ʧ��\n");
		exit(-1);
	}
	else
	{
		pointArr->len = len;//���ݴ����len����len��ʼ��
		pointArr->count = 0;//��������Ч�����ÿ�
	}
}

bool append(struct Array* pointArr,int value)//���Ԫ��
{
	if (isFull(pointArr))//�ж������Ƿ���
	{
		return false;
	}
	else
	{
		pointArr->pointBase[pointArr->count] = value;//count=0����0��ʼ��ӵ�һ��Ԫ��
		(pointArr->count)++;//count+1����һ����Чֵ
		return true;
	}
}

bool insert(struct Array* pointArr, int position, int value)//�������
{
	if (isFull(pointArr))//�ж������Ƿ���
	{
		return false;
	}
	if (position<1||position>(pointArr->count))//�жϲ���ĵط��Ƿ�����򲻴��ڣ�position����С��1���ܴ���count��Ч����
	{
		return false;
	}
	//for (int i=pointArr->count-1;i>=position-1;i--)//ʹ��i=count-1��ΪpointBase[]��ʵ�±꣬��0��ʼ������Ҫ-1
	//{
	//	pointArr->pointBase[i + 1] = pointArr->pointBase[i];
	//	pointArr->pointBase[i];
	//}
	pointArr->pointBase[position - 1] = value;
	//pointBase[5]ʱʵ��λ��Ӧ��ΪpointBase[5-1],������Ҫ��position-1��ΪpointBase����ʵ�±꣬pointBase��0��ʼ����
	return true;
}

int delete(struct Array* pointArr, int position)//ɾ������
{
	if (isEmpty(pointArr))//�п�
	{
		return false;
	}
	if (position<1||position>(pointArr->count))//���±��Ƿ�Ϸ�
	{
		return false;
	}

	/**pointValue = pointArr->pointBase[position - 1];*/
	int* pointValue = pointArr->pointBase[position - 1];
	//��ǰ�洢��Ҫɾ����ֵ������Ҫɾ�������е�һ��Ԫ��8������Ҫ����position=1�������position-1��Ϊ�����±�0����ΪԪ��8���±�
	for (int i = position; i < pointArr->count; i++)
	{
		pointArr->pointBase[i - 1] = pointArr->pointBase[i];//��Ԫ�������ƶ����滻����ɾ����Ԫ��
	}
	pointArr->count--;//��Ч����-1
	return pointValue;//������ǰ�洢�ı�ɾ��ֵ
}

int get(struct Array* pointArr, int position)//��ȡԪ�ز���
{
	return pointArr->pointBase[position-1];
}

bool isEmpty(struct Array* pointArr)//�ж������Ƿ�Ϊ�ղ���
{
	if (pointArr->count == 0)//�ж�count��Ч�����Ƿ�Ϊ0����������Ϊ��
		return true;
	else
		return false;
}

bool isFull(struct Array* pointArr)//�ж������Ƿ�������
{
	if (pointArr->count == pointArr->len)//�ж�count��Ч�����Ƿ�������鳤��len������Ϊ��
		return true;
	else
		return false;
}

void show(struct Array* pointArr)//�����������
{
	if (isEmpty(pointArr))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		for (int i = 0; i < pointArr->count; i++)//�������飬i<count��Ч��������i��Ϊ�±��ṩ��pointBaseʹ��
		{
			printf("%d\n", pointArr->pointBase[i]);
		}
	}
	printf("���鳤��Ϊ %d\n", pointArr->len);
	printf("�������Ч����Ϊ %d\n", pointArr->count);
}

void inversion(struct Array* pointArray)//����Ԫ�ط�ת����
{
	int i = 0;//�������Ԫ��
	int j = pointArray->count - 1;//jʹ��cout��Ч����-1����±꣬���е���,�൱�������ұߵ�Ԫ��
	int temp;

	while (i < j)
	{
		temp = pointArray->pointBase[i];//��i�±�ı�������temp�������Ԫ���ݴ�
		pointArray->pointBase[i] = pointArray->pointBase[j];//��j�±��Ԫ�ش��i�±꣬����Ԫ�ؽ���
		pointArray->pointBase[j] = temp;//���ұ�Ԫ�ر�Ϊ���Ԫ��
		i++;//���±��Լ�
		j--;//���±��Լ�
	}
}

void sort(struct Array* pointArr)//����Ԫ���������
{
	for (int i = 0; i < pointArr->count; i++)//ð������׸����ǰһ��Ԫ�����һ��Ԫ�ش�С����
	{
		for (int j = i + 1; j < pointArr->count; j++)
		{
			if (pointArr->pointBase[i]>pointArr->pointBase[j])
			{
				int temp = pointArr->pointBase[i];
				pointArr->pointBase[i] = pointArr->pointBase[j];
				pointArr->pointBase[j] = temp;
			}
		}
	}
}

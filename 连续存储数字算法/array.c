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
	printf("删除的值是:%d\n", delete(&array, 2));
	show(&array);
}

void init(struct Array* pointArr,int len)//初始化数组
{
	pointArr->pointBase = (int*)malloc(sizeof(int) * len);//将数组元素指针初始化，分配内存空间，指针指向第一个元素地址
	if (pointArr->pointBase == NULL) {//判断指针是否为空
		printf("内存分配失败\n");
		exit(-1);
	}
	else
	{
		pointArr->len = len;//根据传入的len进行len初始化
		pointArr->count = 0;//将数组有效个数置空
	}
}

bool append(struct Array* pointArr,int value)//添加元素
{
	if (isFull(pointArr))//判断数组是否满
	{
		return false;
	}
	else
	{
		pointArr->pointBase[pointArr->count] = value;//count=0，从0开始添加第一个元素
		(pointArr->count)++;//count+1，加一个有效值
		return true;
	}
}

bool insert(struct Array* pointArr, int position, int value)//插入操作
{
	if (isFull(pointArr))//判断数组是否满
	{
		return false;
	}
	if (position<1||position>(pointArr->count))//判断插入的地方是否溢出或不存在，position不能小于1或不能大于count有效个数
	{
		return false;
	}
	//for (int i=pointArr->count-1;i>=position-1;i--)//使用i=count-1作为pointBase[]真实下标，从0开始，所以要-1
	//{
	//	pointArr->pointBase[i + 1] = pointArr->pointBase[i];
	//	pointArr->pointBase[i];
	//}
	pointArr->pointBase[position - 1] = value;
	//pointBase[5]时实际位置应该为pointBase[5-1],所以需要将position-1作为pointBase的真实下标，pointBase从0开始计算
	return true;
}

int delete(struct Array* pointArr, int position)//删除操作
{
	if (isEmpty(pointArr))//判空
	{
		return false;
	}
	if (position<1||position>(pointArr->count))//判下标是否合法
	{
		return false;
	}

	/**pointValue = pointArr->pointBase[position - 1];*/
	int* pointValue = pointArr->pointBase[position - 1];
	//提前存储需要删除的值，如需要删除数组中第一个元素8，就需要传入position=1，随后令position-1变为数组下标0，即为元素8的下标
	for (int i = position; i < pointArr->count; i++)
	{
		pointArr->pointBase[i - 1] = pointArr->pointBase[i];//将元素向左移动，替换掉被删除的元素
	}
	pointArr->count--;//有效个数-1
	return pointValue;//返回提前存储的被删除值
}

int get(struct Array* pointArr, int position)//获取元素操作
{
	return pointArr->pointBase[position-1];
}

bool isEmpty(struct Array* pointArr)//判断数组是否为空操作
{
	if (pointArr->count == 0)//判断count有效个数是否为0，是则数组为空
		return true;
	else
		return false;
}

bool isFull(struct Array* pointArr)//判断数组是否满操作
{
	if (pointArr->count == pointArr->len)//判断count有效个数是否等于数组长度len，是则为满
		return true;
	else
		return false;
}

void show(struct Array* pointArr)//遍历输出操作
{
	if (isEmpty(pointArr))
	{
		printf("数组为空\n");
	}
	else
	{
		for (int i = 0; i < pointArr->count; i++)//遍历数组，i<count有效个数，将i变为下标提供给pointBase使用
		{
			printf("%d\n", pointArr->pointBase[i]);
		}
	}
	printf("数组长度为 %d\n", pointArr->len);
	printf("数组的有效个数为 %d\n", pointArr->count);
}

void inversion(struct Array* pointArray)//数组元素反转操作
{
	int i = 0;//数组左边元素
	int j = pointArray->count - 1;//j使用cout有效个数-1替代下标，进行倒序,相当于数组右边的元素
	int temp;

	while (i < j)
	{
		temp = pointArray->pointBase[i];//将i下标的变量存入temp，将左边元素暂存
		pointArray->pointBase[i] = pointArray->pointBase[j];//将j下标的元素存给i下标，进行元素交换
		pointArray->pointBase[j] = temp;//将右边元素变为左边元素
		i++;//左下标自加
		j--;//右下标自减
	}
}

void sort(struct Array* pointArr)//数组元素排序操作
{
	for (int i = 0; i < pointArr->count; i++)//冒泡排序不赘述，前一个元素与后一个元素大小交换
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

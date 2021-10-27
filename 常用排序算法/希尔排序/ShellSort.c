#include<stdio.h>

int main(void)
{
    int arr[10]={41,52,24,63,21,6,3,1,7,5};
    ShellSort(arr,10);
    show(arr,10);
}

void ShellSort(int arr[],int len)
{
    int gap = len/2;
    while (1 <= gap)
    {
        for (int i = gap; i < len; i++)
        {
           int j = 0;
           int temp = arr[i];
           for ( j = i - gap; j >= 0 && temp < arr[j]; j=j-gap)
           {
               arr[j+gap] = temp;
           }
        }
        gap = gap/2;
    }
}

void show(int arr[], int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
}
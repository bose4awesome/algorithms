//Selection Sort 
#include<stdio.h>
#define n 10
int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int bubble_sort(int a[n],int len)
{
	int i,j;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(a[j]>a[j+1])	
				swap(&a[j],&a[j+1]);
		}
	}
}
void print(int a[n],int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d\t",a[i]);
}
int main()
{
	int a[n]={10,67,78,10,95,23,17,52,11,0};
	print(a,n);
	printf("\n");
	bubble_sort(a,n);
	print(a,n);
}

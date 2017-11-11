#include<stdio.h>
#define n 10
int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(int a[n],int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d\t",a[i]);
}
void selection_sort(int a[n],int len)
{
	int i,j,min;
	for(i=0;i<len-1;i++)
	{
		min=i;
		for(j=i+1;j<len;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		swap(&a[i],&a[min]);
	}
}
int main()
{
	int a[n]={10,67,78,10,95,23,17,52,11,0};
	print(a,n);
	printf("\n");
	selection_sort(a,n);
	print(a,n);
}

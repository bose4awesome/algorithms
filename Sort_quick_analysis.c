#include<stdio.h>
int length;
//Quick Sort Technique[Analysis->By Soumodipta Bose]
void swap(int *a,int *b)//used to swap to values
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void array_state(int a[],int n)
{int i;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
int partition(int a[],int p,int r)
{
	int x=a[r];
	int i=p-1;
	int j;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<x)
		{
			i++;
			swap(&a[i],&a[j]);
		}
		array_state(a,length);
	}
	swap(&a[i+1],&a[r]);
	array_state(a,length);
	printf("\n------------------------------------------------------------------------------------");
	return i+1;
}
void quicksort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
int main(void)
{
	int a[]={9.4,7,2,1,0,3,6,12,56,3,8};
	length=sizeof(a)/sizeof(a[0]);
	printf("Original array->");
	array_state(a,length);
	printf("\n----------------------------------------------------------------------------------");
	quicksort(a,0,length-1);
	printf("\nAfter Sorting:");
	array_state(a,length);
	return 0;
}

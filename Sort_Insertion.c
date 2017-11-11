//Insertion Sort Algorithm -> S. Bose
#include<stdio.h>
#define n 100
void print_array(int a[n],int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void insertion_sort(int a[n],int length)
{
	int i,j,key;
	for(i=1;i<length;i++)
	{
		key=a[i];
		j=i-1;
		while(j>0 &&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
int main()
{
	int a[n],length,i;
	printf("Enter length and array\n");
	scanf("%d",&length);
	for(i=0;i<length;i++)
		scanf("%d",&a[i]);
	insertion_sort(a,length);
	print_array(a,length);
	return 0;
}

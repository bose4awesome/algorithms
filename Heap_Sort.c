#include<stdio.h>
#define N 100
int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void maxheapify(int a[N],int n,int i)
{
	int l=2*i,r=2*i+1,largest;
	if(l<=n&&a[l]>a[i])
		largest=l;
	else 
		largest=i;
	if(r<=n&&a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		swap(&a[i],&a[largest]);
		maxheapify(a,n,largest);
	}
}
void buildmaxheap(int a[N],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
		maxheapify(a,n,i);
}
void heap_sort(int a[N],int n)
{
	int i;
	buildmaxheap(a,n);
	for(i=n;i>=2;i--)
	{
		swap(&a[i],&a[1]);
		n--;
		maxheapify(a,n,1);
	}
}
print(int a[N],int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	
}
int main()
{
	int i,n,a[N];
	printf("Enter length of array:\n");
	scanf("%d",&n);
	printf("Enter array:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	print(a,n);
	heap_sort(a,n);
	print(a,n);
	return 0;
}


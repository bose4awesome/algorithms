#include<stdio.h>
#include<limits.h>
print(int arr[],int len)
{
	int i;
	for(i=0;i<len;i++)
		printf(" %d ",arr[i]);
	printf("\n");
}
//-------------------------------------
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void bubblesort(int a[],int n)
{
	int i,j,swapped;
	for(i=0;i<n-1;i++)
	{
		swapped=0;
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				swapped=1;
			}
		if(!swapped)
			break;
	}
}
//--------------------------------------
void selection_sort(int a[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min])
				min=j;
		swap(&a[i],&a[min]);
	}
}
//---------------------------------------
void insertion_sort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		j=i-1;
		key=a[i];
		while(i>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
//---------------------------------------
void merge(int a[],int p,int q,int r)
{
	int i,j,k,m=q-p+1,n=r-q;
	int a1[m],a2[n];
	for(i=0;i<m;i++)
		a1[i]=a[i+p];
	for(i=0;i<n;i++)
		a2[i]=a[q+i+1];
	a1[m]=INT_MAX;
	a2[n]=INT_MAX;
	i=0,j=0;
	for(k=p;k<=r;k++)
	{
		if(a1[i]<a2[j])
		{
			a[k]=a1[i++];			
		}
		else
		{
			a[k]=a2[j++];
		}
	}	
}
int merge_sort(int a[],int p,int r)
{
	int mid;
	if(p<r)
	{
		mid=(p+r)/2;
		merge_sort(a,p,mid);
		merge_sort(a,mid+1,r);
		merge(a,p,mid,r);
	}
}
//---------------------------------------
int partition(int a[],int p,int r)
{
	int i,j;
	i=p-1;
	for(j=p;j<r;j++)
		if(a[j]<=a[r])
		{
			++i;
			swap(&a[i],&a[j]);
		}
	swap(&a[r],&a[++i]);
	return i;
}
void quick_sort(int a[],int p,int r)
{
	int pivot;
	if(p<r)
	{
		pivot=partition(a,p,r);
		quick_sort(a,p,pivot-1);
		quick_sort(a,pivot+1,r);
	}
}
//---------------------------------------
int main()
{
	int arr[]={12,89,23,78,8,92,34,65,31,71};
	int length=sizeof(arr)/sizeof(int);
	print(arr,length);
	quick_sort(arr,0,length-1);//put sorting algo here <-
	print(arr,length);
}

#include<stdio.h>
#include<limits.h>
#define n 100
void merge(int a[n],int p,int q,int r)
{
	int n1,n2,i,j,k;
	int l[n],m[n];
	n1=q-p+1;
	n2=r-q;
	for(i=0;i<n1;i++)
		l[i]=a[p+i];
	for(i=0;i<n2;i++)
		m[i]=a[q+i+1];
	l[n1]=INT_MAX;
	m[n2]=INT_MAX;
	i=0;j=0;
	for(k=p;k<=r;k++)
	{
		if(l[i]<m[j])
		{
			a[k]=l[i];
			i++;
		}
		else
		{
			a[k]=m[j];
			j++;
		}
	}
}
void merge_sort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}
int main()
{
	int a[n],i,len;
	printf("Enter length->\n");
	scanf("%d",&len);
	printf("Enter Array to be sorted->\n");
	for(i=0;i<len;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,len-1);
	printf("<mergesort>\n");
	for(i=0;i<len;i++)
		printf("%d\t",a[i]);
	return 0;
}

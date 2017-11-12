//Fractional Knapsack -using Greedy Algorithm [S. Bose]
#include<stdio.h>
#define n 5
int cmp(int p1,int w1,int p2,int w2)
{
	double x=(double)p1/w1;
	double y=(double)p2/w2;
	return x<y;
}
int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=*a;
}
int bubble_sort(int a[n],int b[n])
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(cmp(a[j],b[j],a[j+1],b[j+1]))
			{
				swap(&b[j],&b[j+1]);	
				swap(&a[j],&a[j+1]);
			}
		}
	}
}
double knapsack_fract(int p[],int w[],int max)
{
	double profit=0.0;
	int i;
	bubble_sort(p,w);
	for(i=0;i<n;i++)
	{
		if(max>0&&w[i]<max)
		{
			max-=w[i];
			profit+=p[i];
		}
		else
			break;
	}
	if(max>0)
		profit+=(double)(p[i]/w[i])*max;
		return profit;
}
int main()
{
	int p[n]={10,20,30,40,50};
	int w[n]={1,2,3,4,5};
	int m=10;
	printf("Max. Profit= %f",knapsack_fract(p,w,m));
}

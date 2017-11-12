//All pair shortest path[Floyd Warshall]-> S. Bose
// using two matrices [original floyd]
#include<stdio.h>
#define n 100
void printsol(int sol[n][n],int v)
{
	int i,j;
	printf("Shortest distances of all pairs[Floyd Warshall]:\n\t");
	for(i=0;i<v;i++)
		printf("%d\t",i);
	printf("\n------------------------------------\n");
	for(i=0;i<v;i++)
	{
		printf("%d|\t",i);
		for(j=0;j<v;j++)
			printf("%d\t",sol[i][j]);
		printf("\n");
	}
}
int floyd_warshall(int cost[n][n],int v)
{
	int i,j,k;
	int d1[n][n],d2[n][n];
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
		{
			d1[i][j]=d2[i][j]=cost[i][j];
		}
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(d1[i][k]+d1[k][j]<d1[i][j])
					d2[i][j]=d1[i][k]+d1[k][j];
			}
		}
		for(i=0;i<v;i++)
			for(j=0;j<v;j++)
				d1[i][j]=d2[i][j];
	}
	printsol(d1,v);
}
int main()
{
	int a[n][n],v,i,j;
	printf("Enter no. of vertices: \n");
	scanf("%d",&v);
	printf("Enter the adjacency cost matrix of graph:\n");
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			scanf("%d",&a[i][j]);
	floyd_warshall(a,v);
	return 0;
}

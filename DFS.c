#include<stdio.h>
#define n 10
void dfs_rec(int graph[n][n],int visited[n],int v,int start)
{
	int i;
	visited[start]=1;
	printf(" %d ",start);
	for(i=0;i<v;i++)
		if(!visited[i] && graph[start][i])
		{
			printf("->");
			dfs_rec(graph,visited,v,i);
		}
}
int main()
{
	int a[n][n],v,visited[n],i,j,start;
	printf("Enter the no. of vertices:\n");
	scanf("%d",&v);
	printf("Enter the cost matrix:\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			scanf("%d",&a[i][j]);
	visited[i]=0;
	}
	printf("Enter starting vertex:\n");
	scanf("%d",&start);
	dfs_rec(a,visited,v,start);
	return 0;
}

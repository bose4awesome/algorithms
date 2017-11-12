#include<stdio.h>
#define n 100
int stack[n],top=-1;
int push(int ele)
{
	stack[++top]=ele;
}
int pop()
{
	return stack[top--];
}
void dfs_iter(int graph[n][n],int visited[n],int x,int start)
{
	int u,v;
	push(start);
	visited[start]=1;
	printf("%d ",start);
	while(top!=-1)
	{
		u=pop();
		if(!visited[u])
		{
			visited[u]=1;
			printf("-> %d ",u);
		}
		for(v=0;v<x;v++)
			if(!visited[v] && graph[u][v])
				push(v);
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
	dfs_iter(a,visited,v,start);
	return 0;
}

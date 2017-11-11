#include<stdio.h>
#define n 100
int queue[n],front=-1,rear=-1;
void enqueue(int ele)
{
	if(rear==-1)
		front=0;
	queue[++rear]=ele;
}
int dequeue()
{
	return queue[front++];
}
int empty()
{
	if(front>rear||front==-1)
		return 1;
	return 0;
}
void bfs(int graph[n][n],int visited[n],int x,int start)
{
	int u,v;
	printf("%d ",start);
	visited[start]=1;
	enqueue(start);
	while(!empty())
	{
		u=dequeue();
		if(!visited[u])
		{
			visited[u]=1;
			printf("->  %d",u);
		}
		for(v=0;v<x;v++)
			if(!visited[v]&&graph[u][v])
				enqueue(v);
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
	bfs(a,visited,v,start);
	return 0;
}

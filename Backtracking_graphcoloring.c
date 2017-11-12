//graph_coloring v2
#include<stdio.h>
#define N 100
static int k=0;
void printsol(int color[N],int v)
{
	int i;
	printf("sol.:%d\n",++k);
	for(i=0;i<v;i++)
		printf("%d :\t%d\n",i,color[i]);
}
int issafe(int graph[N][N],int color[N],int n,int c,int v)
{
	int i;
	for(i=0;i<v;i++)
	{
		if(graph[v][i]&&color[i]==c)
			return 0;
	}
	return 1;
}
int graphsol(int graph[N][N],int color[N],int n,int m,int v)
{
	int i;
	if(v>=n)
	{
		printsol(color,n);
		return 1;
	}
	for(i=1;i<=m;i++)
	{
		if(issafe(graph,color,n,i,v))
		{
			color[v]=i;
			graphsol(graph,color,n,m,v+1);
			color[v]=0;
		}
	}
	return 0;
}
int main()
{
	int graph[N][N];
	int color[N];
	int n,i,j,m;
	printf("Enter no. of vertices:\n");
	scanf("%d",&n);
	printf("Enter cost matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&graph[i][j]);
		color[i]=0;
	}
	printf("Enter no. of colors:");
	scanf("%d",&m);
	graphsol(graph,color,n,m,0);
	if(!k)
		printf("No Solution exists !");
	
}

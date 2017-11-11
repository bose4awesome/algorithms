//[Back-Tracking]Graph Coloring  with m colors-> S. Bose
#include<stdio.h>
#define n 4
int issafe(int graph[n][n],int color[n],int v,int c)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(graph[v][i]&&c==color[i])
			return 0;
	}
	return 1;
}
int printsol(int color[n])
{
	int i;
	printf("Colors for graph:\n");
	for(i=0;i<n;i++)
		printf("%d : %d\n",i,color[i]);
}
// color[]-> contains all the colors to be assigned
//m->total no. of colors available
//v-> current vertex[starting is 0]
int graphsol(int graph[n][n],int color[n],int m,int v)
{
	int i;
	if(v>=n)
		return 1;
	for(i=1;i<=m;i++)//i will denote the current color
	{
		if(issafe(graph,color,v,i))//tests whether adjacent nodes have same color
		{
			color[v]=i;//if not then assigns color to node
			if(graphsol(graph,color,m,v+1))
			{
				return 1;
			}
			color[v]=0;
		}
	}
	return 0;
}
//just a driver function initializes and gets the result
int graphcoloring(int graph[n][n],int m)
{
	int i;
	int color[n];
	for(i=0;i<n;i++)
		color[i]=0;
	if(graphsol(graph,color,m,0))
	{
		printsol(color);
		return 1;	
	}
	else
	{
		printf("Solution does not exist");
		return 0;
	}
}
int main()
{
	int graph[n][n]={{0, 1, 1, 1},{1, 0, 1, 0},{1, 1, 0, 1},{1, 0, 1, 0}};
	int m=3;
	graphcoloring(graph,m);
	return 0;
}

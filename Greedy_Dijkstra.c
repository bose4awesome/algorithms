//Dijkstra's Algorithm -> S. Bose
#include<stdio.h>
#include<limits.h>
#define n 9
int min_vertex(int sd[n],int visited[n])
{
	int i,min=INT_MAX,x;
	for(i=0;i<n;i++)
	{
		if(!visited[i] && sd[i]<min)
		{
			min=sd[i];
			x=i;
		}
	}
	return x;
}
void print_sd(int sd[n],int s)
{
	int i;
	printf("Dijkstra Shortest distances\n----------------------\n");
	for(i=0;i<n;i++)
	{
		if(i!=s)
			printf("%d -> %d = %d\n",s,i,sd[i]);
	}
}
void dijkstra(int cost[n][n],int s)
{	//sd->Shortest Distance
	int sd[n],visited[n],i,u,v;
	for(i=0;i<n;i++)
	{
		sd[i]=INT_MAX;
		visited[i]=0;
	}
	sd[s]=0;
	for(i=1;i<n;i++)
	{
		u=min_vertex(sd,visited);
		visited[u]=1;
		for(v=0;v<n;v++)
		{
			if(cost[u][v]&& cost[u][v]+sd[u]<sd[v])
			{
				sd[v]=sd[u]+cost[u][v];
			}
		}
	}
	print_sd(sd,s);
}
int main()
{
	int a[n][n]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(a,0);
	return 0;
}

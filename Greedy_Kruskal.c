// Kruskals Algorithm [MST]-> S. Bose
#include<stdio.h>
#include<limits.h>
#define n 5
//Implementation of disjoint sets ->
//-----------------------------------------------------------
int find_set(int parent[n],int i)//Finds whether a particular vertex i belongs to a tree ie. a particular disjoint set
{
	while(parent[i])
		i=parent[i];
	return i;//if it doesnt belong to any set which means it is not in any Spanning tree
}
int union_set(int parent[n],int u,int v)// joins two sets to form a larger set-> collates two Spanning trees
{
	if(u!=v)
	{
		parent[v]=u;//joins u of tree1 and v of tree 2 via a new edge (u,v)
		return 1;
	}
	return 0;
}
//------------------------------------------------------------
void Kruskal_mst(int cost[n][n])
{
	int parent[n];
	int i,j,x,u,v,a,b,min;
	//Initialization part
	for(i=0;i<n;i++)
	{
		parent[i]=0;
		for(j=0;j<n;j++)
			if(cost[i][j]==0)
				cost[i][j]=INT_MAX;
	}
	for(x=1;x<n;x++)
	{
		min=INT_MAX;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(cost[i][j]<min)//Finds the minimum edge(u,v) to be used to build the mst
				{
					min=cost[i][j];
					u=a=i;
					v=b=j;	
				}	
			}
		}
		u=find_set(parent,u);
		v=find_set(parent,v);
		if(union_set(parent,u,v))
		{
			printf("edge (%d,%d) =%d\n",a,b,min);
		}
		cost[a][b]=cost[b][a]=INT_MAX;
	}
}
int main()
{
	int a[n][n]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
	Kruskal_mst(a);
	return 0;
}

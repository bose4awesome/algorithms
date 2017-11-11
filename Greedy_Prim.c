// Prims Algorithm -> S. bose.
/* Prim should have been applied with min heap but since it is complicated to utilize min heap ,
so we are going to virtualize the min heap with equivalent functions and replacements*/
#include<stdio.h>
#include<limits.h>
#define n 5
int find_minkey(int key[],int valid[])
{
	int i,min,min_index;
	min=INT_MAX;
	for(i=0;i<n;i++)
	{
		if(valid[i]==0 && key[i]<min)
		{
			min=key[i];
			min_index=i;	
		}
	}
	return min_index;
}
void print_mst(int parent[n],int key[n])
{
	int i;
	printf("Edge  Weight\n");
	printf("-----------------------------\n");
	for(i=1;i<n;i++)
	{
		printf("%d - %d %d\n",parent[i],i,key[i]);
	}
}
void Prim_MST(int cost[n][n])
{
	int i;
	/*
	key[n]->for storing all the key values, parent[n]-> for storing the parent of each vertex,
	valid[n]->if =1 vertex present in MST else not 
	*/
	int key[n],parent[n],valid[n],u,v;
	//Initialize all the keys as infinite and set all vertices to unvisited.
	for(i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		valid[i]=0;
	}
	key[0]=0;//starting vertex should be set
	parent[0]=-1;//starting vertex doesnt have any parent
	for(i=0;i<n-1;i++)
	{
		u=find_minkey(key,valid);//Extract-Min-Heap equivalent function: This will find the vertex with minimum key value.
		valid[u]=1;//Sets the vertex as visited.
		for(v=0;v<n;v++)
		{
			if(cost[u][v] && valid[i]==0 && cost[u][v]<key[v])//if it finds a better edge weight then the key value will be updated.
			{
				key[v]=cost[u][v];
				parent[v]=u;//the parent vertex  is set that is the edge to which it is attached 
			}
		}
	}
	print_mst(parent,key);// prints each vertex along with its parent
}
int main()
{
	int a[n][n]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
	Prim_MST(a);
	return 0;
}

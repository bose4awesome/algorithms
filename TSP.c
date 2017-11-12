// C program to solve Traveling Salesman Problem
// using Branch and Bound.
#include<stdio.h>
#include<string.h>
#include<limits.h>
#define N 4
 
// final_path[] stores the final solution ie, the
// path of the salesman.
int final_path[N+1];
 
// visited[] keeps track of the already visited nodes
// in a particular path
int visited[N];
 
// Stores the final minimum weight of shortest tour.
int final_res = INT_MAX;
 
// Function to copy temporary solution to
// the final solution
void copyToFinal(int curr_path[])
{
	int i;
    for (i=0; i<N; i++)
        final_path[i] = curr_path[i];
    final_path[N] = curr_path[0];
}
 
// Function to find the minimum edge cost
// having an end at the vertex i
int firstMin(int adj[N][N], int i)
{
    int min = INT_MAX,k;
    for (k=0; k<N; k++)
        if (adj[i][k]<min && i != k)
            min = adj[i][k];
    return min;
}
 
// function to find the second minimum edge cost
// having an end at the vertex i
int secondMin(int adj[N][N], int i)
{
    int first = INT_MAX, second = INT_MAX,j;
    for (j=0; j<N; j++)
    {
        if (i == j)
            continue;
 
        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second &&
                 adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}
 
// function that takes as arguments:
// curr_bound -> lower bound of the root node
// curr_weight-> stores the weight of the path so far
// level-> current level while moving in the search
//         space tree
// curr_path[] -> where the solution is being stored which
//                would later be copied to final_path[]
void TSPRec(int adj[N][N], int curr_bound, int curr_weight,
            int level, int curr_path[])
{
	int curr_res,i,j,temp;
    // base case is when we have reached level N which
    // means we have covered all the nodes once
    if (level==N)
    {
        // check if there is an edge from last vertex in
        // path back to the first vertex
        if (adj[curr_path[level-1]][curr_path[0]] != 0)
        {
            // curr_res has the total weight of the
            // solution we got
            curr_res = curr_weight +
                    adj[curr_path[level-1]][curr_path[0]];
 
            // Update final result and final path if
            // current result is better.
            if (curr_res < final_res)
            {
                copyToFinal(curr_path);
                final_res = curr_res;
            }
        }
        return;
    }
 
    // for any other level iterate for all vertices to
    // build the search space tree recursively
    for (i=0; i<N; i++)
    {
        // Consider next vertex if it is not same (diagonal
        // entry in adjacency matrix and not visited
        // already)
        if (adj[curr_path[level-1]][i] != 0 &&
            visited[i] == 0)
        {
            temp = curr_bound;
            curr_weight += adj[curr_path[level-1]][i];
 
            // different computation of curr_bound for
            // level 2 from the other levels
            if (level==1)
              curr_bound -= ((firstMin(adj, curr_path[level-1]) +
                             firstMin(adj, i))/2);
            else
              curr_bound -= ((secondMin(adj, curr_path[level-1]) +
                             firstMin(adj, i))/2);
 
            // curr_bound + curr_weight is the actual lower bound
            // for the node that we have arrived on
            // If current lower bound < final_res, we need to explore
            // the node further
            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited[i] = 0;
 
                // call TSPRec for the next level
                TSPRec(adj, curr_bound, curr_weight, level+1,
                       curr_path);
            }
 
            // Else we have to prune the node by resetting
            // all changes to curr_weight and curr_bound
            curr_weight -= adj[curr_path[level-1]][i];
            curr_bound = temp;
 
            // Also reset the visited array
            memset(visited, 0, sizeof(visited));
            for (j=0; j<=level-1; j++)
                visited[curr_path[j]] = 1;
        }
    }
}
 
// This function sets up final_path[] 
void TSP(int adj[N][N])
{
    int curr_path[N+1],i;
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(curr_path));
    for (i=0; i<N; i++)
        curr_bound += (firstMin(adj, i)+secondMin(adj, i));
    curr_bound = (curr_bound&1)?curr_bound/2+1:curr_bound/2;
 
    // We start at vertex 1 so the first vertex
    // in curr_path[] is 0
    visited[0] = 1;
    curr_path[0] = 0;
 
    // Call to TSPRec for curr_weight equal to
    // 0 and level 1
    TSPRec(adj, curr_bound, 0, 1, curr_path);
}
 
// Driver code
int main()
{
	int i,cost[N][N],j;
    //Adjacency matrix for the given graph
    printf("Enter the cost matrix:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&cost[i][j]);
	}
    TSP(cost);
    printf("Minimum cost : %d\n", final_res);
    printf("Path Taken : ");
    for (i=0; i<=N; i++)
        printf("%d ", final_path[i]);
    return 0;
}

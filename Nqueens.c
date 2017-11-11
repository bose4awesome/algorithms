//N-queen Problem ->S. Bose
#include<stdio.h>
#define n 4
int issafe(int board[n][n],int row,int col)
{
	int i,j;
	for(i=0;i<n;i++)
		if(board[row][i])
			return 0;
	for(i=row,j=col;i>=0&&j>=0;i--,j--)
		if(board[i][j])
			return 0;
	for(i=row,j=col;i<n&&j>=0;i++,j--)
		if(board[i][j])
			return 0;
	return 1;
}
int nqueensol(int board[n][n],int col)
{
	int i;
	if(col>=n)
		return 1;
	for(i=0;i<n;i++)
	{
		if(issafe(board,i,col))
		{
			board[i][col]=1;
			if(nqueensol(board,col+1))
			{
				return 1;
			}
			board[i][col]=0;
		}
	}
	return 0;
}
void printsol(int board[n][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("-----------------\n");
		for(j=0;j<n;j++)
		{
			if(board[i][j]==1)
				printf("| Q ");
			else
				printf("|   ");
		}
		printf("|\n");
	}
	printf("-----------------\n");
}
int main()
{
	int i,j;
	int board[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			board[i][j]=0;
	if(!nqueensol(board,0))
		printf("Solution doesnt exist\n");
	else
		printsol(board);		
	return 0;
}

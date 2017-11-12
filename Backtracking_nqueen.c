#include<stdio.h>
#define N 100
static int k=0;
void printsol(int board[N][N],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		printf("----");
	for(i=0;i<n;i++)
	{
		printf("\n|");
		for(j=0;j<n;j++)
		{
			if(board[i][j])
				printf(" Q |");
			else
				printf("   |");
		}
		printf("\n ");
		for(j=0;j<n;j++)
		printf("----");
	}
}
int issafe(int board[N][N],int row,int col,int n)
{
	int i,j;
	for(j=0;j<n;j++)
		if(board[row][j])
			return 0;
	for(i=row,j=col;i>=0&&j>=0;i--,j--)
		if(board[i][j])
			return 0;
	for(i=row,j=col;i<n&&j>=0;i++,j--)
		if(board[i][j])
			return 0;
	return 1;			
}
int nqueen(int board[N][N],int col,int n)
{
	int i;
	if(col>=n)
	{
		printf("\n%d Queen - Solution:%d\n",n,++k);
		printsol(board,n);
		return 1;
	}
	for(i=0;i<n;i++)
	{
		if(issafe(board,i,col,n))
		{
			board[i][col]=1;
			nqueen(board,col+1,n);
			board[i][col]=0;
		}
	}
	return 0;
}

int main()
{
	int n,i,j;
	printf("Enter no. of queens:\n");
	scanf("%d",&n);
	int board[N][N];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			board[i][j]=0;
	nqueen(board,0,n);
	if(!k)
		printf("No solution exists");
	return 0;
}

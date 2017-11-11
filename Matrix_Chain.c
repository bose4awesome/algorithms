//Matrix Chain -> S. Bose
#include<stdio.h>
#include<limits.h>
#define size 100
p_o_p(int s[size][size],int i,int j)//Print optimal paranthesis
{
	if(i==j)
		printf(" A%d ",i);
	else
	{
		printf("(");
		p_o_p(s,i,s[i][j]);
		p_o_p(s,s[i][j]+1,j);
		printf(")");
	}
}
int matrix_chain(int p[size],int n)
{
	int m[size][size],s[size][size],i,j,k,l,q;
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("Paranthesis:\n");
	p_o_p(s,1,n);
	return m[1][n];
}
int main()
{
	int n,p[size],i;
	printf("MATRIX CHAIN\n----------------------------------------\n");
	printf("Enter the no. of matrices:\n");
	scanf("%d",&n);
	printf("Enter dimensions:\n");
	for(i=0;i<=n;i++)
		scanf("%d",&p[i]);
	printf("\nMin. Scalar Multiplication:\n%d",matrix_chain(p,n));
	return 0;
}

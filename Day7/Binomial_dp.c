#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int** dp;
int size=-1;
int binomial(int n,int k)
{
	int i,j;
	if(size==-1)
	{
		dp=(int**)malloc((n+1)*sizeof(int*));
		for(i=0;i<=n;i++)
		{
			dp[i]=(int*)malloc((n+1)*sizeof(int));
			for(j=0;j<=k;j++)
			{
				dp[i][j]=-1;
			}
		}
		size=n+1;
	}
	if(n>size)
	{
		dp=(int**)realloc(dp,(n+1)*sizeof(int*));
		for(i=size+1;i<=n;i++)
		{
			dp[i]=(int*)malloc((n+1)*sizeof(int));
			for(j=0;j<=k;j++)
			{
				dp[i][j]=-1;
			}
		}
		size=n+1;
	}
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k && j<=i;j++)
		{
			if(i==j || j==0)
			{
				dp[i][j]=1;
			}
			else
			{
				dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
			}
		}
	}
	return dp[n][k];
}

int main()
{
	int n,k;
	printf("\nEnter n: ");
	scanf("%d",&n);
	printf("\nENter k: ");
	scanf("%d",&k);
	clock_t start=clock();
	int ans=binomial(n,k);
	clock_t end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n%dC%d is: %d",n,k,ans);
	printf("\nCPU TIME: %lf",time);
	return 0;
}

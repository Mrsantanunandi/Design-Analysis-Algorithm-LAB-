#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define INF INT_MAX

void print(int** d,int v,int k)
{
	printf("D%d predecessor matrix:\n",k);
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(d[i][j]==INF)
			{
				printf("%7s\t", "INF");
			}
			else
			{
				printf("%7d\t",d[i][j]);
			}
		}
		printf("\n");
	}
}
	
void flyodwarshal(int** graph,int v)
{
	int** d=(int**)malloc(v*sizeof(int*));
	for(int i=0;i<v;i++)
	{
		d[i]=(int*)malloc(v*sizeof(int));
	}
	//initialization
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			d[i][j]=graph[i][j];
		}
	}
	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(d[i][k]!=INF && d[k][j]!=INF)
				{
				     if(d[i][k]+d[k][j]<d[i][j])
				     {
				          d[i][j]=d[i][k]+d[k][j];
				     }
				}
			}
		}
		print(d,v,k);
	}
	//print(d,v);
}
int main()
{
	int v;
	printf("\nEnter no of vertex: ");
	scanf("%d",&v);
	int **graph=(int**)malloc(v*sizeof(int*));
	for(int i=0;i<v;i++)
	{
		graph[i]=(int*)malloc(v*sizeof(int));
	}
	printf("\nEnter the graph as a mat: (0=For no edge) :\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(graph[i][j]==0 && i!=j)
			{
				graph[i][j]=INF;
			}
		}
	}
	flyodwarshal(graph,v);
		
	return 0;
}

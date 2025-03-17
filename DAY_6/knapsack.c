#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort(float **a,int n)
{
	int i,j;
	float* temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j][2]<a[j+1][2])
			{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
		}
	}
}

float* knap(float** a,int n,int m)
{
int i;
	for(i=0;i<n;i++)
	{
		a[i][2]=a[i][1]/a[i][0];
	}
	sort(a,n);
	for(i=0;i<n;i++){
	if(a[i][0]<=m)
	{
		a[i][3]=1;
		m-=a[i][0];
	}
	else
	{
		a[i][3]=m/a[i][0];
		m=0;
	}
	if(m==0)
	{
		break;
	}
	}
	float* ans=(float*)calloc(n,sizeof(float));
	for(i=0;i<n;i++)
	{
		ans[(int)a[i][4]-1]=a[i][3];
	}
	return ans;
}


int main()
{
	int n,m,i;
	printf("\nEnter no of weights: ");
	scanf("%d",&n);
	float** w=(float**)malloc(n*sizeof(float*));
	if(w==NULL)
	{
		printf("Error in creation\n");
		return 0;
	}
	else
	{
		for(i=0;i<n;i++)
		{
		w[i]=(float*)malloc(5*sizeof(float));
		}
	}
	for(i=0;i<n;i++)
	{
		printf("Enter %d weights: ",i+1);
		scanf("%f",&w[i][0]);
		printf("Enter %d profits: ",i+1);
		scanf("%f",&w[i][1]);
		w[i][4]=i+1;
	}
	printf("\nEnter knapscak weight: ");
	scanf("%d",&m);
	clock_t start=clock();
	float* ans=knap(w,n,m);
	clock_t end=clock();
	for(i=0;i<n;i++)
	{
		printf("%f  ",ans[i]);
	}
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\nCPU TIME: %lf sec\n",time);
	return 0;
}
	

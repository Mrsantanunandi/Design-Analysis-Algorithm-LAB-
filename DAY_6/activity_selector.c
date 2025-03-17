#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int **arr,int n)
{
 int* temp;
 int i,j;
 for(i=0;i<n-1;i++)
 {
	for(j=0;j<n-i-1;j++)
	{
		if((arr[j][2] > arr[j+1][2]) || (arr[j][2] == arr[j + 1][2] && arr[j][1] > arr[j + 1][1])) 
		{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
}
}

void activity_selector(int** arr,int n)
{
	sort(arr,n);
	int i=0,m,k=1;
	arr[i][3] = k;
    	k++;
    	for (m = 1; m < n; m++)
    	{
      	  if (arr[m][1] >= arr[i][2])
        	{
            	i = m;
            	arr[i][3] = k;
            	k++;
        	}
   	 }
 }
			
int main()
{
	int n;
	printf("\nEnter no of activity: ");
	scanf("%d",&n);
	int** a;
	a=(int**)malloc(n*sizeof(int*));
	int i;
	if(a==NULL)
	{
		printf("\nError in creation");
		return 0;
	}
	else
	{
	for(i=0;i<n;i++)
	{
		a[i]=(int*)malloc(4*sizeof(int));
	}
	}
	for(i=0;i<n;i++)
	{
		a[i][0]=i;
		a[i][3]=0;
		printf("Enter Starting Time: ");
		scanf("%d",&a[i][1]);
		printf("Enter ending Time: ");
		scanf("%d",&a[i][2]);
	}
	clock_t start=clock();
	activity_selector(a,n);
	clock_t end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	int *ans=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		ans[a[i][0]]=a[i][3];
	}
	printf("\nAns vector: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("\nCPU TIME: %lf",time);
	printf("\n");
	return 0;
}
	

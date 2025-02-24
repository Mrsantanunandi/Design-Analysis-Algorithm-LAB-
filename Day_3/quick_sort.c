#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int* a,int p,int r)
{
	int j,x,temp,i;
	x=a[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
return i+1;
}
	
void quicksort(int* arr,int p, int r)
{
	int q;
	if(p<r)
	{
		q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

int main()
{
	int n;
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
  	int i,j;
    	srand(time(NULL));
        int* a=(int*)malloc(n*sizeof(int));
        if(a==NULL)
        {
            printf("Error in Creation");
            return 0;
        }
        printf("\nEnter %d element: ",n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        clock_t start=clock();
        quicksort(a,0,n-1);
        clock_t end=clock();
        printf("\nArray after sorting: ");
        for(i=0;i<n;i++)
        {
        	printf("%d  ",a[i]);
        }
        double s=((double)(end-start))/ CLOCKS_PER_SEC;
        printf("\nInput size %d ----> Time taken %lf\n",n,s);
    return 0;
}

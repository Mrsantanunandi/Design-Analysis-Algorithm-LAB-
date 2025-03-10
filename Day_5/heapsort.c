#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void maxheap(int *arr,int n,int i)
{
	int l,r,largest,temp;
	l=2*i+1;
	r=2*i+2;
	if(l<n && arr[l]>arr[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		maxheap(arr,n,largest);
	}
}
void bmaxheap(int *arr,int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	{
		maxheap(arr,n,i);
	}
}
		
void heapsort(int *arr,int n)
{
	bmaxheap(arr,n);
	int i,temp;
	for(i=n-1;i>0;i--)
	{
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		n=n-1;
		maxheap(arr,n,0);
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
        heapsort(a,n);
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
	

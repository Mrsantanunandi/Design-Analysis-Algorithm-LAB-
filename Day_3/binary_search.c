#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bs(int* a,int x,int l,int h)
{
	int mid;
	if(l>h)
	{
		return -1;
	}
	else
	{
		mid=l+(h-l)/2;
		if(a[mid]==x)
		{
			return mid;
		}
		if(x>a[mid])
		{
			return bs(a,x,mid+1,h);
		}
		else
		{
			return bs(a,x,l,mid-1);
		}
	}
}

int main()
{
	int n,y;
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
        printf("Enter the elem you want to find: ");
        scanf("%d",&y);
        clock_t start=clock();
        j=bs(a,y,0,n-1);
        clock_t end=clock();
        if(j!=-1)
        {
        	printf("\nElem %d present at index %d",y,j);
        }
        else
        {
        	printf("\nThe item not found");
        }
        double s=((double)(end-start))/ CLOCKS_PER_SEC;
        printf("\nInput size %d ----> Time taken %lf\n",n,s);
        return 0;
}		

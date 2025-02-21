#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
void merge(int* arr,int l,int mid,int h)
{
	int n1=mid-l+1;
	int n2=h-mid;
	int *l1=(int*)malloc((n1+1)*sizeof(int));
	int *r=(int*)malloc((n2+1)*sizeof(int));
	int i,j,k;
	for(i=0;i<n1;i++)
	{
		l1[i]=arr[l+i];
	}
	for(j=0;j<n2;j++)
	{
		r[j]=arr[mid+j+1];
	}
    l1[n1]=INT_MAX;
    r[n2]=INT_MAX;
	i=0,j=0;
    for (k = l; k <= h; k++) {
        if (l1[i] <= r[j]) {
            arr[k] = l1[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
    }
    free(l1);
    free(r);
}
void mergesort(int* a,int l,int h)
{
	if(l<h)
	{
		int mid=l+((h-l)/2);
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}
int main()
{
	    int n, i;
    	srand(time(NULL));
        printf("Enter the size of the array: ");
        scanf("%d",&n);
        int* arr = (int*)malloc(n* sizeof(int));
        if (arr == NULL) 
        {
            printf("Memory allocation failed\n");
            return 0;
        }
        printf("\nEnter %d elements: ",n);
	    for (i = 0; i < n; i++)
	    {
		    scanf("%d",&arr[i]);
        }
		clock_t start = clock();
		mergesort(arr, 0,n-1);
		clock_t end = clock();
		double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nArray after sorting:");
        for(i=0;i<n;i++)
        {
            printf("%d\t",arr[i]);
        }
		printf("\nTime taken to run the algorithm : %f seconds\n", time_taken);
        free(arr);
	return 0;
}
	
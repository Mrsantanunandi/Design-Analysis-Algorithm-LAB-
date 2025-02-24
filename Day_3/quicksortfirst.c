#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* a, int left, int right) {
	int pivot = a[left];
	int up = right;
	int down = left;

	while (down < up) 
	{
		while (a[down] <= pivot && down < up) {
			down++;
		}
		while (a[up] > pivot) {
			up--;
		}
		if (down < up) {
			swap(&a[down], &a[up]);
		}
	}
	swap(&a[left], &a[up]);
	return up;
}

void quicksort(int* a, int left, int right) {
	if (left < right) {
		int pivot = partition(a, left, right);
		quicksort(a, left, pivot - 1);
		quicksort(a, pivot + 1, right);
	}
}

int main() {
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

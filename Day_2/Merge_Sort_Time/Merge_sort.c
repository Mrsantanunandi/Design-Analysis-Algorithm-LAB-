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
	    FILE *fptr = fopen("mergesort.txt", "w");
        if (fptr == NULL) {
            printf("Error in opening file\n");
            return 1;
        }
	    fprintf(fptr, "%-12s  %-12s\n", "No of data", "Time taken (s)");
	    int n, i, term = 1, j;
    	srand(time(NULL));
    	for (j = 1; j <=6 ; j++) {
        term*=10;
        int* arr = (int*)malloc(term * sizeof(int));
        if (arr == NULL) 
        {
            printf("Memory allocation failed\n");
            return 0;
        }
	    for (i = 0; i < term; i++)
	    {
		    arr[i]=rand();
        }
		clock_t start = clock();
		mergesort(arr, 0,term-1);
		clock_t end = clock();
		double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Time taken to run the algorithm for %d: %f seconds\n", term, time_taken);
		// fprintf(fptr,"Time taken to run the algorithm: %f seconds\n", time_taken);
		fprintf(fptr, "%-12d  %-12.6f\n", term, time_taken);
        free(arr);
	}
	fclose(fptr);
	return 0;
}
	
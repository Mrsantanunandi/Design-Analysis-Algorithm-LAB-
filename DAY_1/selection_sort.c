#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int *arr,int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}
int main()
{
    FILE *fptr=fopen("selectionsort.txt","w");
    fprintf(fptr,"%-12s  %-12s\n","Input Size","Time taken(s)");
    int i,j,temp=1;
    srand(time(NULL));
    for(j=1;j<=6;j++)
    {
        temp*=10;
        int *arr=(int*)malloc(temp*sizeof(int));
        if(arr==NULL)
        {
            printf("Error in creating file\n");
            return 0;
        }
        for(i=0;i<temp;i++)
        {
            arr[i]=rand();
        }
        clock_t start=clock();
        selectionsort(arr,temp);
        clock_t end=clock();
        double s=((double)(end-start))/CLOCKS_PER_SEC;
        printf("\nInput size %d--->>Time taken(%lf SEC)",temp,s);
        fprintf(fptr,"%-12d  %-12.6f\n",temp,s);
    }
    fclose(fptr);
    return 0;
}
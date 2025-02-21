#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int *arr,int n)
{
    int i,j,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}
int main()
{
    FILE *fptr=fopen("Bubble_sort.txt","w");
    fprintf(fptr,"%-12s  %-12s\n","Input size","Time taken");
    int i,j,temp=1,n;
    srand(time(NULL));
    for(j=1;j<6;j++)
    {
        temp*=10;
        int *arr=(int*)malloc(temp*sizeof(int));
        if(arr==NULL)
        {
            printf("Error in Creation");
            return 0;
        }
        for(i=0;i<temp;i++)
        {
            arr[i]=rand();
        }
        clock_t start=clock();
        bubblesort(arr,temp);
        clock_t end=clock();
        double s=((double)(end-start))/ CLOCKS_PER_SEC;
        printf("Input size %d ----> Time taken %lf\n",temp,s);
        fprintf(fptr,"%-12d   %-12.6f\n",temp,s);
    }
    fclose(fptr);
    return 0;
}
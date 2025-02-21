#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionsort(int *arr,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}
int main()
{
    FILE *fptr=fopen("insertionsort.txt","w");
    fprintf(fptr,"%-12s   %-12s\n","Input size","Time Taken(s)");
    int i,j,temp=1;
    srand(time(NULL));
    for(i=1;i<6;i++)
    {
        temp*=10;
        int *arr=(int*)malloc(temp*sizeof(int));
        if(arr==NULL)
        {
            printf("Error in creating File\n");
            return 0;
        }
        for(j=0;j<temp;j++)
        {
            arr[j]=rand();
        }
        clock_t start=clock();
        insertionsort(arr,temp);
        clock_t end=clock();
        double s=((double)(end-start))/CLOCKS_PER_SEC;
        fprintf(fptr,"%-12d   %-12.6f\n",temp,s);
    }
    fclose(fptr);
    return 0;
}
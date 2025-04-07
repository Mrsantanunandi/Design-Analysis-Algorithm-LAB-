#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort(int** arr,int n)
{
    int* temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j][1]< arr[j+1][1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int job(int** arr,int n,int max)
{
    sort(arr,n);
    int* slot=(int*)calloc(max,sizeof(int));
    int i,curdeadline,maxprofit=0;
    for(i=0;i<n;i++)
    {
        curdeadline=arr[i][2];
        while(curdeadline>=1)
        {
            if(slot[curdeadline-1]==0)
            {
                slot[curdeadline-1]=arr[i][0]+1;
                maxprofit+=arr[i][1];
                break;
            }
            curdeadline--;
        }
    }
    return maxprofit;

}
int main()
{
    int n,i;
    printf("\nEnter number of jobs: ");
    scanf("%d",&n);
    int** arr;
    arr=(int**)malloc(n*sizeof(int*));
    if(arr==NULL)
    {
        printf("Error in creation\n");
        return 0;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            arr[i]=(int*)malloc(3*sizeof(int));
        }
    }
    for(i=0;i<n;i++)
    {
        arr[i][0]=i;
        printf("\nEnter %d profit: ",i+1);
        scanf("%d",&arr[i][1]);
        printf("\nEnter %d deadline: ",i+1);
        scanf("%d",&arr[i][2]);
    }
    int max=arr[0][2];
    for(i=0;i<n;i++)
    {
        if(arr[i][2]>max)
        {
            max=arr[i][2];
        }
    }
    clock_t start=clock();
    int ans=job(arr,n,max);
    clock_t end=clock();
    double time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nMax profit is %d",ans);
    printf("\nCPU TIME: %lf sec\n",time);
    return 0;

}

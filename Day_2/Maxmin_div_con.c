#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* num;
int Max(int a,int b)
{
    return a>b?a:b;
}
int Min(int a,int b)
{
    return a<b?a:b;
}
int* maxmin(int x,int y)
{
    int* arr=(int*)malloc(2*sizeof(int));
    if(y-x<=1)
    {
        arr[0]=Max(num[x],num[y]);
        arr[1]=Min(num[x],num[y]);
        return arr;
    }
    else
    {
        int* arr2=maxmin(x,(x+y)/2);
        int max1=arr2[0];
        int min1=arr2[1];
        int* arr3=maxmin((((x+y)/2)+1),y);
        int max2=arr3[0];
        int min2=arr3[1];
        arr[0]=Max(max1,max2);
        arr[1]=Min(min1,min2);
        return arr;
    }
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    num=(int*)malloc(n*sizeof(int));
    if(num==NULL)
    {
        printf("error in creating array\n");
        return 0;
    }
    printf("enter %d elements: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    int* ans=(int*)malloc(2*sizeof(int));
    clock_t start=clock();
    ans=maxmin(0,n-1);
    clock_t end=clock();
    double time=((double)(end-start))/ CLOCKS_PER_SEC;
    printf("\nThe Max elem is : %d",ans[0]);
    printf("\nThe Min elem is : %d",ans[1]);
    printf("\nTime taken: %lf",time);
    return 0;
}
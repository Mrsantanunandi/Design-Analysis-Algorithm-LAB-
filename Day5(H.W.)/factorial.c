#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
int main()
{
    int n,ans;
    printf("Enter n: ");
    scanf("%d",&n);
    clock_t start=clock();
    ans=fact(n);
    clock_t end=clock();
    double time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nFactorial of %d---> %d",n,ans);
    printf("\nCPU Time--> %lf SEC",time);
    return 0;
}
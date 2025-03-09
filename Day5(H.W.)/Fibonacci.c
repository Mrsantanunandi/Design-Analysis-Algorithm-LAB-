#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int fib(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else
    {
        return fib(n-2)+fib(n-1);
    }
}
int main()
{
    int n,ans;
    printf("Enter n: ");
    scanf("%d",&n);
    clock_t start=clock();
    ans=fib(n);
    clock_t end=clock();
    double time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n %dth Fib is ---> %d",n,ans);
    printf("\nCPU Time--> %lf SEC",time);
    return 0;
}
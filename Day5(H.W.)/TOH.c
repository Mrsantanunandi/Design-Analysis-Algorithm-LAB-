#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void TOH(int n,char source,char dest,char temp)
{
    if(n==1)
    {
        printf("\nMove %dst disk from %c to %c via %c",n,source,dest,temp);
    }
    else
    {
        TOH(n-1,source,temp,dest);
        TOH(1,source,dest,temp);
        TOH(n-1,temp,dest,source);
    }
}
int main()
{
    int n,ans;
    char A,B,C;
    printf("Enter number of disk: ");
    scanf("%d",&n);
    clock_t start=clock();
    TOH(n,'A','B','C');
    clock_t end=clock();
    double time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nCPU Time--> %lf SEC",time);
    return 0;
}
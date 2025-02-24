#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bio(int n,int k)
{
	if(k==0 || k==n)
	{
		return 1;
	}
	else
	{
		return (bio(n-1,k-1)+bio(n-1,k));
	}
}

int main()
{
	int n,k,s;
	srand(time(NULL));
	printf("\nEnter n: ");
	scanf("%d",&n);
	printf("\nEnter K:");
	scanf("%d",&k);
	clock_t start=clock();
        s=bio(n,k);
        clock_t end=clock();
        printf("\%d C %d = %d",n,k,s);
	double s1=((double)(end-start))/ CLOCKS_PER_SEC;
        printf("\nTime taken %lf\n",s1);
        return 0;
        }
        

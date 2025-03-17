#include <stdio.h>
#include <stdlib.h>
#include<time.h>


struct Coin
{
    int value;
    int index;
};

int compare(const void *a, const void *b)
{
    struct Coin *c1 = (struct Coin *)a;
    struct Coin *c2 = (struct Coin *)b;
    return c2->value - c1->value;
}

int main()
{
    int w, n, i;
    printf("Enter no of coin: ");
    scanf("%d", &n);

    int coin[n];
    printf("\nEnter coin value: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &coin[i]);
    }

    printf("\nEnter Amount: ");
    scanf("%d", &w);

    int ans = 0;
    struct Coin c[n];
    for (i = 0; i < n; i++)
    {
        c[i].value = coin[i];
        c[i].index = i;
    }
	clock_t start=clock();
    qsort(c, n, sizeof(struct Coin), compare);

    int arr[n];
    for (i = 0; i < n; i++)
        arr[i] = 0;

    int j = 0;
    while (w != 0 && j < n)
    {
        if (w < c[j].value)
        {
            j++;
        }
        else
        {
            w -= c[j].value;
            ans++;
            arr[c[j].index]++;
        }
    }
	clock_t end=clock();
	double time =((double)(end-start))/CLOCKS_PER_SEC;	
    //printf("%d\n", ans);
    if(w==0){
    printf("\nAns Vector: ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    }
    else
    {
	printf("\nNot possible to reach target");
     }
     printf("\nCPU TIME: %lf SEC\n",time);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* knapsack(int** arr, int n, int c) 
{
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) 
    {
        dp[i] = (int*)malloc((c + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= c; j++) 
        {
            if (i == 0 || j == 0) 
            {
                dp[i][j] = 0;
            } 
            else if (j < arr[i - 1][0]) 
            {
                dp[i][j] = dp[i - 1][j];
            } else {
                int exclude = dp[i - 1][j];
                int include = arr[i - 1][1] + dp[i - 1][j - arr[i - 1][0]];
                dp[i][j] = (exclude > include) ? exclude : include;
            }
        }
    }
    printf("\nAns Table: \n");
    for(int i=0;i<=n;i++)
    {
	for(int j=0;j<=c;j++)
	{
		printf("%d\t",dp[i][j]);
	}
	printf("\n");
    }
    int* ans = (int*)calloc(n, sizeof(int));
    int i = n, j = c;

    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            ans[i - 1] = 1;
            j -= arr[i - 1][0];
        }
        i--;
    }


    for (i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return ans;
}

int main() 
{
    int n;
    printf("\nEnter number of items: ");
    scanf("%d", &n);

    int** k = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) 
    {
        k[i] = (int*)malloc(2 * sizeof(int));
        printf("Enter weight of item %d: ", i + 1);
        scanf("%d", &k[i][0]);
        printf("Enter profit of item %d: ", i + 1);
        scanf("%d", &k[i][1]);
    }

    int capacity;
    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);

    clock_t start = clock();
    int* ans = knapsack(k, n, capacity);
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSelected items (0 = not taken, 1 = taken):\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", ans[i]);
    }

    printf("\nCPU Time: %lf sec\n", time);

    for (int i = 0; i < n; i++) 
    {
        free(k[i]);
    }
    free(k);
    free(ans);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void add(int n,int a[][n],int b[n][n],int c[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}
void sub(int n,int a[][n],int b[][n],int c[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }
}

void mat(int n,int a[][n],int b[][n],int c[][n])
{
    int i,j;
    if(n==1)
    {
        c[0][0]=a[0][0]*b[0][0];
        return;
    }
    int m=n/2;
    int a11[m][m],a12[m][m],a21[m][m],a22[m][m];
    int b11[m][m],b12[m][m],b21[m][m],b22[m][m];
    int c11[m][m],c12[m][m],c21[m][m],c22[m][m];

    int p1[m][m],p2[m][m],p3[m][m],p4[m][m],p5[m][m],p6[m][m],p7[m][m];
    int x[m][m],y[m][m];
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            a11[i][j]=a[i][j];
            a12[i][j]=a[i][j+m];
            a21[i][j]=a[i+m][j];
            a22[i][j]=a[i+m][j+m];

            b11[i][j]=b[i][j];
            b12[i][j]=b[i][j+m];
            b21[i][j]=b[i+m][j];
            b22[i][j]=b[i+m][j+m];
        }
    
    }
    sub(m,b12,b22,x);
    mat(m,a11,x,p1);
    add(m,a11,a12,x);
    mat(m,b22,x,p2);
    add(m,a21,a22,x);
    mat(m,b11,x,p3);
    sub(m,b21,b11,x);
    mat(m,a22,x,p4);
    add(m,a11,a22,x);
    add(m,b11,b22,y);
    mat(m,x,y,p5);
    sub(m,a12,a22,x);
    add(m,b21,b22,y);
    mat(m,x,y,p6);
    sub(m,a11,a21,x);
    add(m,b11,b12,y);
    mat(m,x,y,p7);
    
    add(m,p5,p4,x);
    sub(m,x,p2,y);
    add(m,y,p6,c11);
    add(m,p1,p2,c12);

    add(m,p3,p4,c21);

    add(m,p5,p1,x);
    sub(m,x,p3,y);
    sub(m,y,p7,c22);
    for(m,i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            c[i][j]=c11[i][j];
            c[i][j+m]=c12[i][j];
            c[i+m][j]=c21[i][j];
            c[i+m][j+m]=c22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter matrix size: ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);}}

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &B[i][j]);}
            }
    clock_t start=clock();
    mat(n,A, B, C);
    clock_t end=clock();
    double time=((double)(end-start))/CLOCKS_PER_SEC;
    
    printf("Result matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("\nCPU TIME:--> %lf",time);
    printf("\n");
    return 0;
}

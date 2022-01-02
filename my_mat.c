#include <stdio.h>
#include "my_mat.h"

int min(int, int);
void calc_dis();
#define V 10

int mat[V][V];

void fun1()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    calc_dis();
}

void fun2()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (mat[a][b] != 0)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

void fun3()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (mat[a][b] == 0 || a == b)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", mat[a][b]);
    }
}

void calc_dis()
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i == j)
                {
                    mat[i][i] = 0;
                }
                else if (i == k || j == k)
                {
                    mat[i][j] = mat[i][j];
                }
                else
                {
                    int val = mat[i][k] + mat[k][j];
                    if (mat[i][k] == 0 || mat[k][j] == 0){
                        val = 0;
                    }
                    mat[i][j] = min(mat[i][j], val);
                }
            }
        }
    }
}

int min(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
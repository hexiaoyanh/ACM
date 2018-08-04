//
// Created by mika on 18-8-4.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 10000000

int map[101][101];

void init_map(int n)
{
    int i, j;

    for (i = 1; i <= n; i ++)
    {
        for (j = 1; j <= n; j ++)
        {
            map[i][j] = INF;
        }
    }
}

int prim(int n)
{
    int lowcost[101], visited[101];
    int minc, i, j;
    int res = 0, mnt;

    memset(visited, 0, sizeof(visited));

    for (i = 1; i <= n; i ++)
    {
        lowcost[i] = map[1][i];
    }
    visited[1] = 1;

    for (i = 1; i < n; i ++)
    {
        minc = INF;
        mnt = -1;

        for (j = 1; j <= n; j ++)
        {
            if (visited[j] == 0 && minc > lowcost[j])
            {
                minc = lowcost[j];
                mnt = j;
            }
        }

        if (mnt == -1)
            return -1;

        res += minc;

        visited[mnt] = 1;

        for (j = 1; j <= n; j ++)
        {
            if (visited[j] == 0 && lowcost[j] > map[mnt][j])
            {
                lowcost[j] = map[mnt][j];
            }
        }
    }
    return res;
}


int main()
{
    int i, n, en, u, v, len, res;

    while (scanf("%d", &n) != EOF && n)
    {
        init_map(n);

        en = n * (n - 1) / 2;

        for (i = 0; i < en; i ++)
        {
            scanf("%d %d %d", &u, &v, &len);
            map[u][v] = map[v][u] = len;
        }

        // prime求最小生成树
        res = prim(n);

        printf("%d\n", res);
    }
    return 0;
}

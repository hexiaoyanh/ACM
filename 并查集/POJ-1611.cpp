#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
int a[30300];

int find(int x)
{
    int r = x;
    while (a[r] != r)
        r = a[r];
    int i = x,j;
    while (a[i] != r)
    {
        j = a[i];
        a[i] = r;
        i = j;
    }
    return r;
}


void mix(int x,int y)
{
    int fx = find(x),fy=find(y);
    if(fx < fy)
    {
        a[fy]=fx;
    }
    if(fy<fx)
    {
        a[fx] = fy;
    }
}

int main()
{
    int n,m;
    while(cin>>n>>m )
    {
        if(n==0 && m ==0)
            break;
        for (int i = 0; i < n; ++i)
        {
            a[i]=i;
        }
        for (int i = 0; i < m; ++i)
        {
            int q[30020];
            int w;
            scanf("%d",&w);
            for (int j = 0; j < w; ++j)
            {
                scanf("%d",&q[j]);
            }
            for (int k = 1; k < w; ++k)
            {
                mix(q[k-1],q[k]);
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if(a[find(i)]==0)
                sum++;
        }
        printf("%d\n",sum);
    }
}

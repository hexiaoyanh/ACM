/*
    @Author: wchhlbt
    @Date:   2017/4/28
*/
//#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>

#define Fori(x) for(int i=0;i<x;i++)
#define Forj(x) for(int j=0;j<x;j++)
#define maxn 50007
#define inf 0x3f3f3f3f
#define ONES(x) __builtin_popcount(x)
using namespace std;

typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n,m;
int ans;
int f[maxn];
int r[maxn];//保存和根节点的性别关系
int sum[maxn];

void init()//初始化
{
    for(int i = 0; i<maxn-2; i++)
        f[i] = i , r[i] = 0 , sum[i] = 1;
}

int find(int u)//更新父节点
{
    if(u!=f[u]){
        int t = f[u];
        f[u] = find(f[u]);
        r[u] += r[t];
    }
    return f[u];
}

void connect(int u, int v)
{
    int x = find(u);
    int y = find(v);
    if(x!=y){
        f[x] = y;
        r[x] = sum[y];
        sum[y] += sum[x];
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    int q;
    scanf("%d",&q);
    init();
    while(q--)
    {
        char ch;
        int a,b;
        scanf("\n%c %d",&ch,&a);
        if(ch=='M'){
            scanf("%d",&b);
            connect(a,b);
        }
        else{
            find(a);
            printf("%d\n", r[a]);
        }
    }
    return 0;
}

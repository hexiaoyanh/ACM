//
// Created by mika on 18-6-12.
//

#include <stdio.h>
#include <string.h>
int fa[2005];
int rela[2005];
bool bugs;
void init(int n)
{
    for(int i=1;i<=n;i++)
        fa[i]=i,rela[i]=0;
}
int find(int x)
{
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
void uni(int a,int b)
{
    int aa=find(a);
    int bb=find(b);
    if(aa!=bb)
        fa[aa]=bb;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
#endif
    int ncase;
    int t=1;
    scanf("%d",&ncase);
    while(ncase--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        init(n);
        bugs=false;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(!bugs)
            {
                int xx=find(x);
                int yy=find(y);
                if(xx==yy) bugs=true;
                if(rela[x]) uni(rela[x],y);
                else rela[x]=y;
                if(rela[y]) uni(rela[y],x);
                else rela[y]=x;
            }
        }
        printf("Scenario #%d:\n",t++);
        if(bugs)
            puts("Suspicious bugs found!\n");
        else
            puts("No suspicious bugs found!\n");
    }
    return 0;
}
#include <cstdio>
#include <iostream>
using namespace std;
int bugs[2010];
int relation[2010];
void init(int len)
{
    for(int i = 0;i <= len; i++)
    {
        bugs[i] = i;
        relation[i] = 1;
    }
}
int find(int bug)
{
    if(bugs[bug]==bug)
		return bug;
    int tem = bugs[bug];
    bugs[bug] = find(bugs[bug]);
	relation[bug] = (relation[bug]+relation[tem]+1)%2;
    return bugs[bug];
}

void union_set(int a,int b,int x,int y)
{
    bugs[x]=y;
    relation[x] = (relation[b]-relation[a])%2;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("./output.txt","w",stdout);
#endif
    int S;
    int n,inter;
    int bug1,bug2,parent1,parent2;
    bool flag;
	scanf("%d",&S);
    for(int i=1; i<=S;i++)
    {
        scanf("%d%d",&n,&inter);
        flag = false;
        init(n);
        for(int j = 1; j <= inter; j++)
        {
            scanf("%d%d",&bug1,&bug2);
            if(flag)continue;
            parent1 = find(bug1);
            parent2 = find(bug2);
            if(parent1==parent2)
            {
                if(relation[bug1]==relation[bug2])
				{
					flag = true;
					goto aa;
				}
			}
            union_set(bug1,bug2,parent1,parent2);
        }aa:
			if(flag)
				printf("Scenario #%d:\nSuspicious bugs found!\n",i);
			else
		        printf("Scenario #%d:\nNo suspicious bugs found!\n",i);
        printf("\n");
    }
    return 0;
}

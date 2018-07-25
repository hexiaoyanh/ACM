#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
#include <map>

using namespace std;
#define ll long long
#define ull unsigned ll
#define MAXN 50010

struct point
{
	int l,r;
	int sum;
};

int num[MAXN];

point tree[MAXN<<2];

void build(int root ,int l,int r)
{
	tree[root].l=l;
	tree[root].r=r;
	if(tree[root].l==tree[root].r)
	{
		tree[root].sum=num[l];
		return;
	}
	int mid=(l+r)/2;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
}

void update(int root ,int pose,int val)
{
	if(tree[root].l==tree[root].r)
	{
		tree[root].sum=val;
		return;
	}
	int mid =( tree[root].l+tree[root].r)/2;
	if(pose<=mid)
		update(root<<1,pose,val);
	else
		update(root<<1|1,pose,val);
	tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
}

int query(int root ,int l,int r)
{
	if(l<=tree[root].l&&r>=tree[root].r)
	{
		return tree[root].sum;
	}
	int mid=(tree[root].l+tree[root].r)/2,ret=0;
	if(l<=mid)
		ret+=query(root<<1,l,r);
	if(r>mid)
		ret+=query(root<<1|1,l,r);
	return ret;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
#endif
	ll T;
	scanf("%lld",&T);
	int Case=1;
	while (T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&num[i]);
		printf("Case %d:\n",Case++);
		build(1,1,MAXN);
		string s;
		int l,r;
		while(cin>>s>>l>>r && s!="End")
		{
			if(s[0]=='Q')
			{
				cout<<query(1,l,r)<<endl;
			}
			else if(s[0]=='A')
			{
				num[l]+=r;
				update(1,l,num[l]);
			}
			else if(s[0]=='S')
			{
				num[l]-=r;
				update(1,l,num[l]);
			}
		}
	}
}

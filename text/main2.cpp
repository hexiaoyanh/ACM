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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
#endif
	ios::sync_with_stdio(false);
	ll l,r;
	int k;
	while (cin>>l>>r>>k)
	{
		map<ll,int>mp;
		int A[k];
		for(int i=0;i<k;++i)
		{
			cin>>A[i];
		}
		for(ll x:A)
		{
			ll fst,last;
			fst=l/x;
			last=r/x;
			for(ll i=fst;i<=last;++i)
			{
				ll temp=x*i;
				//cout<<temp<<endl;
				mp[temp]++;
			}
		}
		ll sum=0;
		for(ll i=l;i<=r;++i)
		{
			if(mp[i]==0)
				sum++;
		}
		cout<<sum<<endl;
	}
}


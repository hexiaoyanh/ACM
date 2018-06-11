/*
TLE 不知道为什么
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
#define int long long
	int n;
	int cases=1;
	while(cin>>n)
	{
		int s=n;
		int bd[n+5];
		int top=0;
		memset(bd,-1,sizeof(bd));
		for(int i=0;i<n;++i)
		{
			int h;
			scanf("%lld",&h);
			if(h<0)continue;
			if(h==0)
			{
				--s;
				top=0;
				memset(bd,-1,sizeof(bd));
				continue;
			}
			if(h>bd[top])
				bd[++top]=h;
			else
			{
				while(h<=bd[top])
				{
					bd[top]=-1;
					--top;
				}
				bd[++top]=h;
				s--;
			}
		}	
		printf("Case %lld: %lld\n",cases++,s);
	}
}

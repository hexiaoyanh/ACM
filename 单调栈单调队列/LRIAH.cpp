#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(!n)break;
		int hhh[n+5];
		int his[n+5];
		memset(his,-1,sizeof(his));
		int top=0;
		long long ans=0;
		for(int i=0;i<=n;++i)	
		{
			int h;
			if (i!=n)
				cin>>h;
			else
				h=0;
			if(h>his[top])
			{
				his[++top]=h;
				hhh[top]=1;
			}
			else
			{
				ll cnt=0;
				while(h<=his[top])
				{
					ans=max(ans,(cnt+hhh[top])*his[top]);
					//等于当前值乘以之前比它大的值
					cnt+=hhh[top--];
				}
				his[++top]=h;
				hhh[top]=cnt+1;//记录之前有几个值大于自己
			}
		}
		cout<<ans<<endl;
	}

}

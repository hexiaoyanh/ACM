#include <iostream>
#include <stack>
#include <algorithm>
#define ll long long
using namespace std;
struct point
{
	ll num;
	ll da;
};
int main()
{
	ll n;
	while(cin>>n)
	{
		stack<ll>sk;
		ll sum=0;
		point x[n];
		for(int i=0;i<n;++i)
			cin>>x[i].num;
		reverse(x,x+n);
		for(int i=0;i<n;++i)
		{
			int s=0;
			while(!sk.empty() && x[i].num>x[sk.top()].num)
			{
				++s;
				if(x[sk.top()].da!=0)
					s+=x[sk.top()].da;
				sk.pop();
			}
			x[i].da=s;
			sum+=s;
			sk.push(i);
		}
		cout<<sum<<endl;
	}
}

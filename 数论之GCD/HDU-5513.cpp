//
// Created by mika on 18-4-3.
//

#include <iostream>
#include <algorithm>
//#include "../config.h"
#define ll long long
using namespace std;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll r = exgcd(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t-a/b*y;
    return r;
}
int main()
{
    ll a,b;
    while (cin>>a>>b)
    {
        ll x,y;
        ll r = exgcd(a,b,x,y);
        if(r!=1)
        {
            cout<<"sorry"<<endl;
            continue;
        }
        x = (x%b+b)%b;
        y = (1-a*x)/b;
        cout<<x<<" "<<y<<endl;
    }
}

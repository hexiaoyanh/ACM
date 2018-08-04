#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
typedef long long ll;
using namespace std;
const ll mod=1ll<<47;
map<string,ll> mp;
ll mul_mod(ll x,ll y)
{
    ll ans=0;
    while(y)
    {
        if(y&1) ans=(ans+x)%mod;
        y>>=1;
        x=(x+x)%mod;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    string a,b,c;
    while(cin>>a>>b)
    {
        if(a=="def")
        {
            ll x;
            cin>>x;
            mp[b]=x;
            cout<<b<<" = "<<x<<endl;
            continue;
        }
        cin>>c;
        if(a[0]=='a')
        {
            mp[b]=(mp[c]+mp[b])%mod;
            cout<<b<<" = "<<mp[b]<<endl;
        }
        else if(a[0]=='s')
        {
            mp[b]=(mp[b]-mp[c]+mod)%mod;
            cout<<b<<" = "<<mp[b]<<endl;
        }
        else if(a[0]=='d')
        {
            mp[b]/=mp[c];
            mp[b]=(mp[b]+mod)%mod;
            cout<<b<<" = "<<mp[b]<<endl;
        }
        else if(a=="mod")
        {
            mp[b]%=mp[c];
            cout<<b<<" = "<<mp[b]<<endl;
        }
        else
        {
            mp[b]=mul_mod(mp[b],mp[c]);
            cout<<b<<" = "<<mp[b]<<endl;
        }
    }
    return 0;
}

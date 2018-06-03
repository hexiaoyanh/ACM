#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 10000000
#define ll long long
int a[maxn];

ll gcd(ll x, ll y);

int main()
{
    ll T;
    scanf("%lld",&T);
    while(T--)
    {
        vector<ll>vec;
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        ll gg = gcd(x>y?x:y,x>y?y:x);
        ll gd = sqrt(gg);
        for (int i = gd; i >=1 ; --i)
        {
            if(gg%i==0)
            {
                vec.push_back(i);
                if(i*i!=gg)
                {
                    vec.push_back(gg/i);
                }
            }
        }
        //cout<<vec.size()<<endl;
        sort(vec.begin(),vec.end());
//        for(vector<ll>::iterator it = vec.begin();it!=vec.end();it++)
//        {
//            cout<<*it<<' ';
//        }
//        cout<<endl;
        if(vec.size()>=z)
        {
            //cout<<vec[z-1]<<endl;
            cout<<gg/vec[z-1]<<endl;
        }
        else cout<<-1<<endl;
    }
}

ll gcd(ll x, ll y)
{
    return y?gcd(y,x%y):x;
}
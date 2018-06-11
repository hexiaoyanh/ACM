#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define pi acos(-1.0)
struct point
{
	double high;
	double x;
	int id;
	point(){};
	point(double high,double x,int id):high(high),x(x),id(id){};
	bool operator <(const point &b)const
	{
		return x<b.x;
	}
	point operator -(const point &b)const
	{
		return point(high-b.high,x-b.x,0);
	}
};

int all;
const int Max = 1e5+20;
double ans[2*Max];
point tp[2*Max];
point a[2*Max];

int cross(const struct point &a,const struct point &b)
{
	return  a.high*b.x-b.high*a.x>0;
}

int judge(point &a,point &b,point &c)
{
	return cross(a-c,c-b);
}

double angle(point a,point b)
{
	return atan((b.x-a.x)/a.high);
}

void solve()
{
	int top=0;
    for(int i=0;i<all;i++)
	{
        if(a[i].high==0){
            while(top>=2&&judge(tp[top-1],tp[top],a[i])) 
				top--;
            ans[a[i].id]+=angle(tp[top],a[i]);
        }
        else
		{
            while(top&&tp[top].high<=a[i].high) top--;
            while(top>=2&&judge(tp[top-1],tp[top],a[i])) top--;
            tp[++top]=a[i];
        }
    }
}

int main()
{
	int t;
	cin>>t;
	int cas=1;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>a[i].x>>a[i].high;
		all=n;
		int q;
		cin>>q;
		for(int i=0;i<q;++i)
		{
			cin>>a[all].x;
			a[all].high=0;
			a[all].id=i;
			all++;
		}
		sort(a,a+all);
		memset(ans,0,sizeof(ans));
		solve();
		reverse(a,a+all);
		for(int i=0;i<all;i++) 
			a[i].x=10000000-a[i].x ;
        solve();
        printf("Case #%d:\n",cas++);
        for(int i=0;i<q;i++){
            printf("%.10f\n",ans[i]*180/pi);
        }
	}
}

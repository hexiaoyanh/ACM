#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int maxn=1e5+100;
int L[maxn],R[maxn];
int a[maxn];
LL sum[maxn];
int s[maxn];
int n;
int main()
{
   while(~scanf("%d",&n))
   {
       sum[0]=0;
	   for(int i=1;i<=n;++i)
       {
         scanf("%d",&a[i]);
         sum[i]=sum[i-1]+a[i];
       }
       int top=0;
       for(int i=1;i<=n;i++)
       {
           while(top&&a[s[top]]>=a[i])
              --top;
           L[i]=(top==0?1:s[top]+1);
           s[++top]=i;
       }
       top=0;
       for(int i=n;i>=1;i--)
       {
           while(top&&a[s[top]]>=a[i])
            --top;
           R[i]=(top==0?n:s[top]-1);
           s[++top]=i;
       }
       LL ans=(LL)a[1]*(sum[R[1]]-sum[L[1]-1]);int pos=1;
       for(int i=2;i<=n;i++)
       {
           if((LL)a[i]*(sum[R[i]]-sum[L[i]-1])>ans)
           {
               ans=(LL)a[i]*(sum[R[i]]-sum[L[i]-1]);
               pos=i;
           }
       }
       printf("%lld\n",ans);
       printf("%d %d\n",L[pos],R[pos]);
   }
   return 0;
}


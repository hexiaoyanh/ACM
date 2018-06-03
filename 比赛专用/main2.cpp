#include<stdio.h>
#include<algorithm>
#define MAX_N 100009
using namespace std;
int rect[MAX_N];
struct seg
{
    long long  value,s;
}q[MAX_N];
int main()
{
    int n ;
    while(scanf("%d",&n)&&n)
    {
        long long area = 0 ,top = 0;
        for(int i=0;i!=n;++i)
            scanf("%d",rect+i);
        for(int i=0;i!=n;++i)
        {
            //队列为空或者当前元素大于队尾时入队
            if(!top || q[top-1].value < rect[i])
            {
                q[top].value = rect[i];
                q[top++].s = i ;
            }
            //此时，右边界出现，需要做更新
            else if(q[top-1].value>rect[i])
            {
                //如果有比最大值大的面积，则更新最大值
                while(top && q[top-1].value>rect[i])
                {
                    --top;
                    area = max(area,q[top].value*(i-q[top].s));
                }
                //队空
                if(!top)
                    q[top++].value = rect[i] ;
                else if(q[top-1].value < rect[i])
                    q[top++].value = rect[i] ;
            }
        }
        //队中可能还有元素，也要做相应的更新
        while(top)
        {
            --top;
            area = max(area,q[top].value*(n-q[top].s));
        }
        printf("%lld\n",area);
    }
    return 0;
}

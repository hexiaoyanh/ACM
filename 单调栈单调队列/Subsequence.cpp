//
// Created by mika on 18-6-11.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;
const int N = 100100+4;
int a[N];
deque<int> q1;
int ans;
deque<int> q2;
int main()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int last=0;
        while(!q1.empty()) q1.pop_front();
        while(!q2.empty()) q2.pop_front();
        for(int i=1;i<=n;i++)
        {
            while(!q1.empty()&&a[i]>=a[q1.back()]) q1.pop_back();
            while(!q2.empty()&&a[i]<=a[q2.back()]) q2.pop_back();
            q1.push_back(i);
            q2.push_back(i);
            while(!q1.empty()&&!q2.empty()&&a[q1.front()]-a[q2.front()]>k)
            {
                if(q1.front()>q2.front())
                {
                    last=q2.front();
                    q2.pop_front();
                }
                else
                {
                    last=q1.front();
                    q1.pop_front();
                }
            }
            if(!q1.empty()&&!q2.empty()&&a[q1.front()]-a[q2.front()]>=m)
            {
                ans=max(ans,i-last);
            }
        }
        printf("%d\n",ans);
    }
}
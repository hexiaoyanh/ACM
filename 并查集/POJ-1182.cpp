//
// Created by mika on 18-4-9.
//

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int a[105][105];
int n;
int s;
void digui(int x,int y,int fang,int flag)
{
    if(fang==1)
    {
        for (int i = 0; i <s ; ++i)
        {
            a[x--][y]=flag++;
        }
        //cout<<x<<' '<<y<<endl;
        int w;
        if(a[x][y-1]) {w=3;x++;y--;}
        else if(a[x][y+1]){w=11;x++,y++;}
        else return;
        s--;

        digui(x,y,w,flag);
    }
    if(fang==3)
    {
        for (int i = 0; i < s; ++i)
        {
            a[x][y--]=flag++;
        }
        int w;
        if(a[x+1][y]){w=7;x++;y++;}
        else if(a[x-1][y]){w=11;x--;y--;}
        else return;
        s--;
        digui(x,y,w,flag);
    }
    if(fang==7)
    {

        for (int i = 0; i <s ; ++i)
        {
            cout<<x<<' '<<y<<' '<<flag<<endl;
            a[x][y]=flag;
            cout<<a[x][y]<<endl;
            x++;
            flag++;
        }
        int w;
        if(a[x][y+1]){w=11;}
        else if(a[x][y-1]){w=3;}
        else return;
        s--;
    }
}


int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>n;
        memset(a,0, sizeof(a));
        for (int i = 0; i <= 100; ++i)
        {
            a[0][i]=-1;
            a[i][0]=-1;
        }
        for (int i = 1; i <= n; ++i)
        {
           a[1][i]=i;
        }
        int q=n+1;
        for (int i = 2; i <= n ; ++i)
        {
            a[i][n]= q++;
        }
        if(n!=1)s=n-1;
        digui(n,n-1,1,2*n);
        for (int i = 1; i <=n ; ++i)
        {
            for (int j = 1; j <=n ; ++j)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
    }
}
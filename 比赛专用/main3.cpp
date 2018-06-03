#include <iostream>
using namespace std;
char a[1010];
int main()
{
    int n,i;
    int flag=0;
	cin>>n;
	cin>>a;
    a[0]='0';
    a[n+1]='0';
    for(i=1;i<=n;i++)
    {
        if((a[i-1]=='0'&&a[i]=='0'&&a[i+1]=='0')||(a[i]=='1'&&a[i+1]=='1'))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)printf("No\n");
    else printf("Yes\n");
    return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int dt[140005],T,n,itmp[50005];
void init(int k,int l,int r) {
    if(r-l==1) {
        dt[k]=itmp[l];
        //printf("%d %d\n",l,r);
    } else {
        //printf("%d %d\n",l,r);
        int chl=k*2,chr=k*2+1;
        init(chl,l,(l+r)/2);
        init(chr,(l+r)/2,r);
        dt[k]=dt[chl]+dt[chr];
        //printf("%d %d %d %d\n",dt[k],l,(l+r)/2,r);
    }
}
void add(int a,int x,int k,int l,int r) {
    if(a<l||a>=r)return;
    dt[k]+=x;
    if(r-l==1) {
        return;
    }
    int chl=k*2,chr=k*2+1;
//    printf("%d %d\n",l,r);
    add(a,x,chl,l,(l+r)/2);
    add(a,x,chr,(l+r)/2,r);
}
void sub(int a,int x,int k,int l,int r) {
    if(a<l||a>=r)return;
    dt[k]-=x;
    if(r-l==1) {
        return;
    }
    int chl=k*2,chr=k*2+1;
    sub(a,x,chl,l,(l+r)/2);
    sub(a,x,chr,(l+r)/2,r);
}
int query(int a,int b,int k,int l,int r) {
    if(b<=l||a>=r)return 0;
    if(a<=l&&b>=r) {
        //printf("%d %d\n",k,dt[k]);
        return dt[k];
    }
    if(r-l!=1) {
        int chl=k*2,chr=k*2+1;

        int res=query(a,b,chl,l,(l+r)/2)+query(a,b,chr,(l+r)/2,r);
        //printf("%d %d %d %d\n",res,l,(l+r)/2,r);
        return res;
    }
}

int main() {
    scanf("%d",&T);
    int T0=T;
    while(T--) {
        memset(dt,0,sizeof(dt));
        memset(itmp,0,sizeof(itmp));
        scanf("%d",&n);
        for(int i=1; i<=n; i++) {
            scanf("%d",&itmp[i]);
        }
        init(1,1,n+1);

        string st;
        int x,y;
        printf("Case %d:\n",T0-T);
        cin>>st;
        while(st!="End") {
            scanf("%d%d",&x,&y);
            if(st=="Query") {
                printf("%d\n",query(x,y+1,1,1,n+1));
            }
            if(st=="Add") {
                add(x,y,1,1,n+1);
            }
            if(st=="Sub") {
                sub(x,y,1,1,n+1);
            }
            cin>>st;
        }
    }
    return 0;
}

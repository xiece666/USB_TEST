#include<bits/stdc++.h>
#pragma gcc optimize(2)
#define ll long long
#define ldb long double
#define mkp make_pair
#define pbk push_back
#define fir first
#define sec second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=1e5+10;
template <typename T> inline void read(T &x){
    x=0;T f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    x*=f;
}
template<typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void wrt(T x){
    if(x<0) x=-x,putchar('-');
    if(x>9) wrt(x/10);
    putchar(x%10+48);
}
template <typename T> void wrt(T x,char c){wrt(x),putchar(c);}
int n,F,p[N];
ldb ans,l,r=1e12,tmp[N];
bool ck(ldb md){
    for(int i=1;i<=n;i++)tmp[i]=tmp[i-1]+1.0*p[i]-md;
    ldb res=-1e12,mi=1e12;
    for(int i=F;i<=n;i++){
        mi=min(mi,tmp[i-F]);
        res=max(res,tmp[i]-mi);
    }
    return res>=0.0;
}
int main(){
    read(n,F);
    for(int i=1;i<=n;i++)read(p[i]);
    while(r-l>2e-13){
        ldb mid=(l+r)/(2.0);
        if(ck(mid))l=mid;
        else r=ans=mid;
        // printf("check(%lf):%d\n",mid,ck(mid));
    }
    wrt(int(ans*(ldb)(1000.0)));
    return  0;
}
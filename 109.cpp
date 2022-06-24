#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define fir first
#define sec second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=5e5+10;
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
template <typename T> void wrt(T x,char c1,T y,char c2){wrt(x,c1),wrt(y,c2);}
ll T,n,m,k,d,l,r,p[N],tmp[N],ct,ans;
inline ll calc(ll x,ll y){
    ct=0;
    for(ll i=x;i<=y&&i<=n;i++)tmp[++ct]=p[i];
    sort(tmp+1,tmp+1+ct);
    ll res=0;
    for(ll i=1;i<=m;i++){
        if(ct-i+1<=i)break;
        res+=(tmp[i]-tmp[ct-i+1])*(tmp[i]-tmp[ct-i+1]);
    }
    // printf("    calc(%lld,%lld):%lld\n",x,y,res);
    return res;
}
int main(){
    read(T);
    while(T--){
        read(n,m,k);
        for(ll i=1;i<=n;i++)read(p[i]);
        r=d=1,ans=0;
        while(1){
            l=r,d=1;
            while(d&&r<=n){
                if(calc(l,r+d)<=k)
                    r+=d,d<<=1;
                else d>>=1;
                // printf("    k:%lld r:%lld d:%lld\n",k,r,d);
                // puts("");
            }
            ans++;
            // printf("ans:%lld l:%lld r:%lld\n",ans,l,r);
            if(r>=n)break;
            r++;
        }
        wrt(ans,'\n');
    }
    return 0;
}
/*
1
100 88 1039
6 0 16 16 5 19 16 18 19 0 10 19 12 19 0 9 3 7 19 3 6 17 17 4 7 10 14 11 14 9 6 6 0 12 16 15 15 16 3 0 19 7 16 18 1 19 9 12 3 16 8 17 15 2 11 15 11 2 6 18 15 5 17 8 8 19 16 2 6 14 5 19 17 12 9 11 17 4 1 11 13 16 10 3 16 19 19 16 3 13 2 11 3 7 1 13 19 18 14 17

*/
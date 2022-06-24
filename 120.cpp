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
const ll N=2e5+10;
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
ll n,T,l,r,ans,s[N],e[N],d[N];
inline ll sum(ll x,ll y){
    ll res=0;
    x--;
    for(ll i=1;i<=n;i++){
        if(s[i]<=y)res+=(min(e[i],y)-s[i])/d[i]+1;
        if(s[i]<=x)res-=(min(e[i],x)-s[i])/d[i]+1;
    }
    // printf("calc [%d,%d]:%d\n",x,y,res);
    return res;
}
int main(){
    read(T);
    while(T--){
        read(n),l=r=0,ans=-1;
        for(ll i=1;i<=n;i++)
            read(s[i],e[i],d[i]),r=max(r,e[i]);
        if(!(sum(0,r)&1)){
            puts("There's no weakness.");
            continue;
        }
        while(l<=r){
            ll mid=(l+r)>>1;
            ll s=sum(l,mid);
            if(s&1)r=mid-1,ans=mid;
            else l=mid+1;
        }
        wrt(ans,' ',sum(ans,ans),'\n');
    }
    return 0;
}
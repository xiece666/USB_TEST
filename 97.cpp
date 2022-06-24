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
const ll N=1;
constexpr ll mod=9901;
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
template <typename T1,typename T2> void wrt(T1 x1,char c1,T2 x2,char c2){wrt(x1,c1),wrt(x2,c2);}
ll a,b,ans=1;
vector<pair<ll,ll>>p;
inline ll pw(ll x,ll y){
    ll res=1;
    for(;y;y>>=1){
        if(y&1)(res*=x)%=mod;
        (x*=x)%=mod;
    }
    return res;
}
inline ll calc(ll x,ll y){
    if(y==0)return 1;
    if(y&1)return (calc(x,(y-1)>>1)*(pw(x,(y+1)>>1)+1))%mod;
    return ((calc(x,y>>1)-1)*(pw(x,y>>1)+1)+1)%mod;
}
int main(){
    read(a,b);
    if(!a)return puts("0"),0;
    for(ll i=2;i*i<=a;i++)if(a%i==0){
        pair<ll,ll>tmp={i,0};
        while(a%i==0)a/=i,tmp.sec++;
        p.pbk(tmp);
    }
    if(a>1)p.pbk({a,1});
    for(pair<ll,ll>i:p){
        ll x=i.fir,y=i.sec*b;
        (ans*=calc(x,y))%=mod;
    }
    wrt(ans);
    return  0;
}
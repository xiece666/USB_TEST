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
template <typename T> void wrt(T x,char c1,T y,char c2){wrt(x,c1),wrt(y,c2);}
ll n;
set<pair<ll,ll>>s;
//{value,position}
int main(){
    read(n);
    s.insert({INT_MIN,INT_MIN});
    s.insert({INT_MAX,INT_MAX});
    for(ll i=1,x;i<=n;i++){
        read(x);
        if(i==1){
            s.insert({x,1});
            continue;
        }
        auto tx=s.lower_bound({x,0});
        auto ti=--tx;tx++;
        ll valx=tx->fir,vali=ti->fir;
        if(valx-x<x-vali)wrt(valx-x,' ',tx->sec,'\n');
        else wrt(x-vali,' ',ti->sec,'\n');
        // printf("mx:{%d,%d} mi:{%d,%d}\n\n",valx,tx->sec,vali,ti->sec);
        s.insert({x,i});
    }
    return 0;
}
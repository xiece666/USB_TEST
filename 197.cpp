#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define pbk push_back
#define fir first
#define sec second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
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
const ll N=1e6+10;
ll n;
vector<ll>prime,ansp,ansc;
bitset<N>vis;
int main(){
    read(n);
    for(ll i=2;i<=n;i++){
        if(!vis[i])prime.pbk(i);
        for(ll j=i;j<=n/i;j++)vis[j*i]=1;
    }
    for(ll i:prime){
        ll cnt=0;
        for(ll j=i;j<=n;j*=i)cnt+=n/j;
        if(!cnt)continue;
        ansp.pbk(i),ansc.pbk(cnt);
    }
    for(ll i=0;i<ansp.size();i++)
        wrt(ansp[i],' ',ansc[i],'\n');
    return  0;
}
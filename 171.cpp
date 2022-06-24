#include<bits/stdc++.h>
#pragma GCC optimize(fast)
#define ll long long
#define ull unsigned long long
#define lll __int128
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
const ll N=50;
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
ll n,V,ans,k,v[N];
vector<ll>p;
void dfs1(ll pos,ll sum){
    if(pos>k){
        p.pbk(sum);
        return;
    }
    if(sum+v[pos]<=V)dfs1(pos+1,sum+v[pos]);
    dfs1(pos+1,sum);
}
void dfs2(ll pos,ll sum){
    if(pos>n){
        ll rest=*(--upper_bound(p.begin(),p.end(),V-sum));
        ans=max(ans,rest+sum);
        return;
    }
    if(sum+v[pos]<=V)dfs2(pos+1,sum+v[pos]);
    dfs2(pos+1,sum);
}
int main(){
    read(V,n);
    for(ll i=1;i<=n;i++)read(v[i]);
    sort(v+1,v+1+n,greater<ll>());
    k=n/2+2;
    dfs1(1,0);
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    dfs2(k+1,0);
    wrt(ans);
    return  0;
}
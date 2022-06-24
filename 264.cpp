#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long double
#define ebk emplace_back
#define mkp make_pair
#define fir first
#define sec second
#define pii pair<ll,ll>
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
template <typename T1,typename T2> void wrt(T1 x,char c1,T2 y,char c2){wrt(x,c1),wrt(y,c2);}
const ll N=2e5+10,K=1e6+10;
ll n,k,ans=INT_MAX;
ll mp[K];
vector<pii>g[N],vec;
vector<ll>opt;
ll root,mi,siz[N];
bitset<N>vis;
bitset<K>vvis;
void dfs_cen(ll u,ll fa,ll s){
    siz[u]=1;
    ll mxp=0;
    for(auto [v,val]:g[u])if(v!=fa&&!vis[v])
        dfs_cen(v,u,s),siz[u]+=siz[v],mxp=max(mxp,siz[v]);
    mxp=max(mxp,s-siz[u]);
    if(mxp<mi)mi=mxp,root=u;
}
void dfs(ll u,ll  fa,ll dis,ll dep){
    if(dis>k)return;
    vec.ebk(dis,dep);
    for(auto [v,val]:g[u])if(v!=fa&&!vis[v])
        dfs(v,u,dis+val,dep+1);
}
void calc(ll u){
    opt.clear();
    for(auto [v,val]:g[u]){
        if(vis[v])continue;
        vec.clear();
        dfs(v,u,val,1);
        for(auto [val,d]:vec)
            ans=min(ans,mp[k-val]+d);
        for(auto [val,d]:vec){
            mp[val]=min(mp[val],d);
            if(!vvis[val])opt.ebk(val),vvis[val]=1;
        }
    }
    for(ll i:opt)mp[i]=INT_MAX,vvis[i]=0;
}
void solve(ll u){
    vis[u]=1,calc(u);
    for(auto [v,val]:g[u]){
        if(vis[v])continue;
        root=0,mi=INT_MAX;
        dfs_cen(v,u,siz[v]);
        dfs_cen(root,0,siz[v]);
        solve(root);
    }
}
int main(){
    read(n,k),vvis[0]=1;
    for(ll i=1;i<=k;i++)mp[i]=INT_MAX;
    bool fl=1;
    for(ll i=1,x,y,z;i<n;i++){
        read(x,y,z),x++,y++;
        g[x].ebk(y,z),g[y].ebk(x,z);
        if(z!=1)fl=0;
    }
    if(fl)return wrt(k),0;
    root=0,mi=INT_MAX;
    dfs_cen(1,0,n);
    dfs_cen(root,0,n);
    solve(root);
    wrt(ans<=n?ans:-1);
    return 0;
}
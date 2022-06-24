#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long double
#define ebk emplace_back
#define mkp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
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
const ll N=2e5+10;
int n,ans,siz[N],dp[N],deg[N];
vector<pii>g[N];
void dfs1(int u,int fa){
    for(auto [v,val]:g[u])if(v!=fa)
        dfs1(v,u),siz[u]+=(deg[v]==1?val:min(siz[v],val));
}
void dfs2(int u,int fa){
    // printf("dp[%d]:%d siz[%d]:%d\n",u,dp[u],u,siz[u]);
    for(auto [v,val]:g[u])if(v!=fa){
        dp[v]=(deg[u]==1?val:min(val,dp[u]-min(val,siz[v])))+siz[v];
        ans=max(ans,dp[v]),dfs2(v,u);
    }
}
signed main(){
    int Task;read(Task);
    while(Task--){
        // do you clear array&value?
        read(n);
        for(int i=0;i<=n;i++)
            deg[i]=siz[i]=dp[i]=0,g[i].clear();
        for(int i=1,x,y,z;i<n;i++){
            read(x,y,z);
            g[x].ebk(y,z),deg[y]++;
            g[y].ebk(x,z),deg[x]++;
        }
        dfs1(1,0);
        ans=dp[1]=siz[1];
        dfs2(1,0);
        wrt(ans,'\n');
    }
    return 0;
}
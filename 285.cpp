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
const ll N=6010;
int n,h[N],dp[2][N],rt;
bitset<N>exi;
vector<int>g[N];
void dfs(int u){
    dp[1][u]=h[u],dp[0][u]=0;
    for(int v:g[u]){
        dfs(v);
        dp[0][u]+=max(dp[0][v],dp[1][v]);
        dp[1][u]+=dp[0][v];
    }
}
signed main(){
    read(n);
    for(int i=1;i<=n;i++)read(h[i]);
    for(int i=1,x,y;i<n;i++)
        read(x,y),g[y].ebk(x),exi[x]=1;
    for(int i=1;i<=n&&!rt;i++)if(!exi[i])rt=i;
    dfs(rt);
    wrt(max(dp[0][rt],dp[1][rt]));
    return 0;
}
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
const ll N=310;
int n,m,a[N],dp[N][N];
vector<int>g[N];
void dfs(int u){
    for(int v:g[u]){
        dfs(v);
        for(int i=m;~i;i--)for(int j=0;j<=i;j++)
            dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
    }
    if(u)for(int i=m;i;i--)
        dp[u][i]=dp[u][i-1]+a[u];
}
signed main(){
    read(n,m);
    for(int i=1,x;i<=n;i++)
        read(x,a[i]),g[x].ebk(i);
    dfs(0);
    wrt(dp[0][m]);
    return 0;
}
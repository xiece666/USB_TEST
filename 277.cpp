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
const ll N=35,M=5010;
int n,m,g[N],p[N],s[N],ans[N];
int dp[N][M];
struct lyl{int a,b;}pre[N][M];
void calc(lyl sta){
    if(!sta.a)return;
    calc(pre[sta.a][sta.b]);
    if(pre[sta.a][sta.b].a==sta.a)
        for(int i=1;i<=sta.a;i++)ans[p[i]]++;
    else for(int i=pre[sta.a][sta.b].a+1;i<=sta.a;i++)ans[p[i]]=1;
}
signed main(){
    read(n,m),mem(dp,0x3f),dp[0][0]=0;
    for(int i=1;i<=n;i++)read(g[i]),p[i]=i;
    sort(p+1,p+1+n,[&](int a,int b){return g[a]>g[b];});
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+g[p[i]];
        for(int j=i;j<=m;j++){
            dp[i][j]=dp[i][j-i],pre[i][j]=(lyl){i,j-i};
            for(int k=0;k<i;k++)if(dp[i][j]>dp[k][j-(i-k)]+k*(s[i]-s[k]))
                dp[i][j]=dp[k][j-(i-k)]+k*(s[i]-s[k]),pre[i][j]=(lyl){k,j-(i-k)};
        }
    }
    wrt(dp[n][m],'\n');
    calc((lyl){n,m});
    for(int i=1;i<=n;i++)wrt(ans[i],' ');
    return 0;
}
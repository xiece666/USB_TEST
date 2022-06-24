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
const ll N=3831;
int n,b,a[N],ans,f;
int dp[2][N][2];
signed main(){
    read(n,b);
    for(int i=1;i<=n;i++)read(a[i]);
    mem(dp,0xcf),dp[f][0][0]=dp[f][1][1]=0;
    for(int i=2;i<=n;f^=1,i++)for(int j=0;j<=min(i,b);j++){
        dp[f^1][j][0]=max(dp[f][j][0],dp[f][j][1]);
        if(j)dp[f^1][j][1]=max(dp[f][j-1][1]+a[i],dp[f][j-1][0]);
    }
    ans=dp[f][b][0],f=0,mem(dp,0xcf),dp[f][0][0]=0,dp[f][1][1]=a[1];
    for(int i=2;i<=n;f^=1,i++)for(int j=0;j<=min(i,b);j++){
        dp[f^1][j][0]=max(dp[f][j][0],dp[f][j][1]);
        if(j)dp[f^1][j][1]=max(dp[f][j-1][1]+a[i],dp[f][j-1][0]);
    }
    ans=max(ans,dp[f][b][1]);
    wrt(ans);
    return 0;
}
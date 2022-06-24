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
const ll N=55;
int n,m,dp[N<<1][N][N],a[N][N];
int main(){
    read(n,m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)read(a[i][j]);
    for(int i=3;i<=n+m;i++)for(int j=1;j<=min(i-1,n);j++)for(int k=1;k<=min(i-1,n);k++){
        int del=a[j][i-j]+(j!=k)*a[k][i-k];
        int &cur=dp[i][j][k];
        cur=max(cur,dp[i-1][j][k]);
        cur=max(cur,dp[i-1][j-1][k]);
        cur=max(cur,dp[i-1][j][k-1]);
        cur=max(cur,dp[i-1][j-1][k-1]);
        cur+=del;
    }
    wrt(dp[n+m][n][n]);
    return 0;
}
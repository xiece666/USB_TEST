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
int dp[N][N],n,s[N];
signed main(){
    read(n);
    for(int i=1;i<=n;i++)
        read(s[i]),s[i]+=s[i-1];
    mem(dp,0x3f);
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int len=2;len<=n;len++)for(int l=1,r=len;r<=n;l++,r++)
        for(int k=l;k<r;k++)dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+s[r]-s[l-1]);
    wrt(dp[1][n]);
    return 0;
}
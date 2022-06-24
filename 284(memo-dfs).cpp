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
constexpr ll mod=1e9;
ll n,dp[N][N];
char s[N];
ll dfs(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if(l>r)return dp[l][r]=0;
    if(l==r)return dp[l][r]=1;
    dp[l][r]=0;
    for(int k=l+2;k<=r;k++)if(s[l]==s[k])
        (dp[l][r]+=dfs(l+1,k-1)*dfs(k,r)%mod)%=mod;
    return dp[l][r];
}
signed main(){
    scanf("%s",s+1),n=strlen(s+1);
    mem(dp,-1);
    wrt(dfs(1,n));
    return 0;
}
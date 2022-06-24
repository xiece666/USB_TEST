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
namespace IO{
#define MAXSIZE (1<<20)
char *p1=NULL,*p2=NULL,buf[MAXSIZE];
inline char gchar(){
    return
#ifdef DEBUG
    getchar();
#else
    getchar();
    // p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXSIZE,stdin),p1==p2)?EOF:*p1++;
#endif
}
template<typename _Tp>inline void read(_Tp &x){
    x=0;char ch=gchar();
    for(;!isdigit(ch);ch=gchar());
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
}
template<typename _Tp>inline void nread(_Tp &x){
    x=0;_Tp f=1;char ch=gchar();
    for(;!isdigit(ch);ch=gchar())ch=='-'&&(f=-1);
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
    x*=f;
}
template<typename _Tp,typename ...Args>
inline void read(_Tp &x,Args &...args){read(x),read(args...);}
template<typename _Tp,typename ...Args>
inline void nread(_Tp &x,Args &...args){nread(x),nread(args...);}
template<typename _Tp>inline void wrt(_Tp x){
    if(x<0)x=-x,putchar('-');
    if(x>9)wrt(x/10);
    putchar(x%10+48);
}
inline void wrt(char ch){putchar(ch);}
template<typename _Tp,typename ...Args>
inline void wrt(_Tp x,Args ...args){wrt(x),wrt(args...);}
#undef MAXSIZE
}
using IO::read,IO::nread,IO::wrt,IO::gchar;
const ll N=110,M=11;
int n,m,mp[N],ans;
vector<int>sta,g[1<<M];
int dp[2][1<<M][1<<M],f;
char s[M];
signed main(){
    read(n,m);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++)mp[i]=mp[i]<<1|(s[j]=='H');
    }
    for(int i=0;i<(1<<m);i++){
        bool fl=1;
        for(int j=0,la=-3;j<m&&fl;j++)
            if(i&(1<<j))fl&=(j-la>=3),la=j;
        if(fl)sta.ebk(i);
    }
    for(int i:sta)for(int j:sta)if(!(i&j))g[i].ebk(j);
    mem(dp,0xcf),dp[f][0][0]=0;
    for(int i=1;i<=n;i++,f^=1)for(int j:sta)for(int k:g[j])
        if(!(mp[i]&j)&&!(mp[i-1]&k))for(int l:g[k])
            if(!(j&l))dp[f^1][j][k]=max(dp[f^1][j][k],dp[f][k][l]+__builtin_popcount(j));
    for(int i:sta)for(int j:g[i])if(!(mp[n]&i)&&!(mp[n-1]&j))ans=max(ans,dp[f][i][j]);
    wrt(ans);
    return 0;
}
/*
5 4
PHPP
PPHH
PPPP
PHPP
PHHP

*/
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
    p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXSIZE,stdin),p1==p2)?EOF:*p1++;
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
const ll N=12;
int n,m,ans=INT_MAX;
int dis[N][1<<N],ex[1<<N];
int dp[N][1<<N],cost[1<<N][1<<N];
vector<pii>g[N];
vector<int>fr[1<<N];
signed main(){
    read(n,m);
    for(int i=1,x,y,z;i<=m;i++){
        read(x,y,z),x--,y--;
        g[x].ebk(y,z),g[y].ebk(x,z);
    }
    mem(dis,0x3f);
    for(int i=1;i<(1<<n);i++){
        ex[i]=i;
        for(int j=0;j<n;j++)if(i&(1<<j))
            for(auto [k,val]:g[j])if(!(i&(1<<k)))
                ex[i]|=1<<k,dis[k][i]=min(dis[k][i],val);
    }
    for(int i=1;i<(1<<n);i++)for(int j=i;j;j=(j-1)&i)
        if((i&ex[j])==i&&j!=i){
            fr[i].ebk(j);
            int t=i^j;
            for(int k=0;k<n;k++)if(t&(1<<k))
                cost[j][i]+=dis[k][j];
        }
    mem(dp,0x3f);
    for(int i=0;i<n;i++)dp[1][1<<i]=0;
    for(int i=2;i<=n;i++)for(int j=1;j<(1<<n);j++)
        for(int k:fr[j])dp[i][j]=min(dp[i][j],dp[i-1][k]+(i-1)*cost[k][j]);
    for(int i=1;i<=n;i++)ans=min(ans,dp[i][(1<<n)-1]);
    wrt(ans);
    return 0;
}
/*
4 5 
1 2 1 
1 3 3 
1 4 1 
2 3 4 
3 4 1

*/
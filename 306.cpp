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
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
namespace IO{
#define MAXSIZE (1<<20)
char *p1=NULL,*p2=NULL,buf[MAXSIZE];
#ifdef DEBUG
#define gchar() getchar()
#else
#define gchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXSIZE,stdin),p1==p2)?EOF:*p1++)
#endif
inline void read(char *x){
    char ch=gchar();
    while(ch==' '||ch=='\n'||ch=='\r')ch=gchar();
    do *x++=ch,ch=gchar(); while(ch!=' '&&ch!='\n'&&ch!='\r');
    *x='\0';
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
inline void wrt(char *s){while(*s!='\0')putchar(*s++);}
inline void wrt(const char *s){while(*s!='\0')putchar(*s++);}
template<typename _Tp,typename ...Args>
inline void wrt(_Tp x,Args ...args){wrt(x),wrt(args...);}
#undef MAXSIZE
}using IO::read,IO::nread,IO::wrt;
const ll S=2e5+10,N=2010,mod=1e9+7;
int h,w,n,p[N];
ll fac[S],inv[S];
int dp[N];
int x[N],y[N];
ll fpow(ll a,ll b){
    ll res=1;
    for(;b;(a*=a)%=mod,b>>=1)
        if(b&1)(res*=a)%=mod;
    return res;
}
ll C(int a,int b){return fac[a]*inv[b]%mod*inv[a-b]%mod;}
signed main(){
    read(h,w,n);
    fac[0]=inv[0]=1;
    for(int i=1;i<=h+w;i++)fac[i]=fac[i-1]*i%mod;
    inv[h+w]=fpow(fac[h+w],mod-2);
    for(int i=h+w-1;i;i--)inv[i]=inv[i+1]*(i+1)%mod;
    for(int i=1;i<=n;i++)read(x[i],y[i]),p[i]=i;
    p[n+1]=n+1,n++,x[0]=y[0]=1,x[n]=h,y[n]=w;
    sort(p,p+1+n,[](int a,int b){return x[a]==x[b]?y[a]<y[b]:x[a]<x[b];});
    dp[0]=1;
    for(int i=1;i<=n;i++)for(int j=0;j<i;j++)
        if(x[p[j]]<=x[p[i]]&&y[p[j]]<=y[p[i]])
            (dp[i]+=(mod+(j?-1:1)*dp[j]*C(x[p[i]]+y[p[i]]-x[p[j]]-y[p[j]],x[p[i]]-x[p[j]])%mod)%mod)%=mod;
    wrt(dp[n]);
    return 0;
}
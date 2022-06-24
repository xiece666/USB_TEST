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
#define pii pair<ll,ll>
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
const ll N=55,mod=1e9+7;
ll n,m,ans;
ll C[N][N];
ll f[N][N],g[N][N][N],h[N];
ll fpow(ll a,ll b){
    ll res=1;
    for(;b;(a*=a)%=mod,b>>=1)
        if(b&1)(res*=a)%=mod;
    return res;
}
signed main(){
    read(n,m),m=min(m,n-1);
    for(ll i=0;i<=n;i++){
        C[i][0]=1;
        for(ll j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    f[0][0]=1,g[0][0][0]=1;
    for(ll i=1;i<=n;i++){
        // h
        h[i]=fpow(2,i*(i-1)/2);
        for(ll j=1;j<i;j++)
            (h[i]+=mod-h[j]*C[i-1][j-1]%mod*fpow(2,(i-j)*(i-j-1)/2)%mod)%=mod;
        // f
        f[i][0]=h[i];
        for(ll j=1;j<i;j++){
            for(ll k=1;k<i;k++){
                ll t=f[k][0]*C[i-1][k-1]%mod;
                for(ll l=1;l<=j&&l<=i-k;l++)
                    (f[i][j]+=t*g[i-k][j-l][l]%mod*fpow(k,l)%mod)%=mod;
            }
            (f[i][0]+=mod-f[i][j])%=mod;
        }
        // g
        for(ll j=0;j<i;j++)for(ll k=1;k<=i;k++)
            for(ll l=1;l<=i;l++)for(ll r=0;r<=j;r++)
                (g[i][j][k]+=f[l][r]*C[i-1][l-1]%mod*l%mod*g[i-l][j-r][k-1]%mod)%=mod;
    }
    for(ll i=0;i<=m;i++)(ans+=f[n][i])%=mod;
    wrt(ans);
    return 0;
}
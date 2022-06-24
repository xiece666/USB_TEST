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
const ll N=25,S=20;
ll n,c;
ll dp[2][N][N];
// 0:l>i<r 1:l<i>r
bitset<N>usd;
signed main(){
    dp[0][1][1]=dp[1][1][1]=1;
    for(ll i=2;i<=S;i++){
        for(ll j=1;j<i;j++)for(ll k=j;k<i;k++)
            dp[0][i][j]+=dp[1][i-1][k];
        for(ll j=2;j<=i;j++)for(ll k=1;k<j;k++)
            dp[1][i][j]+=dp[0][i-1][k];
    }
    // printf("dp[%d][%d][%d]:%lld\n",0,2,1,dp[0][2][1]);
    ll Task;read(Task);
    while(Task--){
        // do you clear array&value?
        read(n,c),usd=0;
        ll la=0,t=0;
        bool fl=0;
        for(la=1;la<=n&&!fl;la++)for(t=1;~t&&!fl;t--)
            if(dp[t][n][la]<c)c-=dp[t][n][la];
            else fl=1,t++,la--;
        // printf("%lld %lld\n",la,t);
        usd[la]=1,wrt(la,' ');
        for(ll i=2;i<=n;i++){
            t^=1;
            for(ll j=1,k=0;j<=n;j++)if(!usd[j]){
                k++;
                if((!t)^(j>la)){
                    if(dp[t][n-i+1][k]<c)c-=dp[t][n-i+1][k];
                    else{la=j;break;}
                }
            }
            usd[la]=1,wrt(la,' ');
        }
        puts("");
    }
    return 0;
}
/*
2
2 1
3 3

*/
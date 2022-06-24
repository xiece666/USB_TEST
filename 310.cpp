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
ll n,m;
ll dp[4][N];
signed main(){
    dp[0][0]=1;
    for(ll i=1;i<=S;i++){
        dp[0][i]=9*(dp[0][i-1]+dp[1][i-1]+dp[2][i-1]);
        dp[1][i]=dp[0][i-1],dp[2][i]=dp[1][i-1];
        dp[3][i]=dp[3][i-1]*10+dp[2][i-1];
    }
    ll Task;read(Task);
    while(Task--){
        // do you clear array&value?
        read(n);
        for(m=3;dp[3][m]<n;m++);
        // printf("m:%lld\n",m);
        for(ll i=m,t=0;i;i--)for(ll j=0;j<10;j++){
            ll rk=dp[3][i-1];
            if(t==3||j==6)for(ll k=max(0ll,3-t-(j==6));k<3;k++)
                rk+=dp[k][i-1];
            if(rk<n)n-=rk;
            else{
                t<3&&(t=(t+1)*(j==6)),wrt(j);
                break;
            }
        }
        assert(n==1);
        puts("");
    }
    return 0;
}
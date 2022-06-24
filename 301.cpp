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
inline void wrt(const char *s){while(*s!='\0')putchar(*s++);}
template<typename _Tp,typename ...Args>
inline void wrt(_Tp x,Args ...args){wrt(x),wrt(args...);}
#undef MAXSIZE
}using IO::read,IO::nread,IO::wrt;
const ll N=3e5+10;
ll n,S,st[N],sc[N];
ll dp[N];
ll q[N],h=1,t=1;
#define X(i) (sc[i])
#define Y(i) (dp[i]-S*sc[i])
#define K(i) (st[i])
#define slope(i,j) (1.0*(Y(j)-Y(i))/(X(j)-X(i)))
signed main(){
    read(n,S);
    for(ll i=1;i<=n;i++)
        read(st[i],sc[i]),st[i]+=st[i-1],sc[i]+=sc[i-1];
    for(ll i=1;i<=n;i++){
        while(h<t&&slope(q[h],q[h+1])<=K(i))h++;
        dp[i]=Y(q[h])-K(i)*X(q[h])+st[i]*sc[i]+S*sc[n];
        while(h<t&&slope(q[t-1],q[t])>=slope(q[t],i))t--;
        q[++t]=i;
    }
    wrt(dp[n]);
    return 0;
}
/*
5 1
1 3
3 2
4 3
2 3
1 4
*/
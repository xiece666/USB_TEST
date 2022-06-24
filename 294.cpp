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
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
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
template<typename _Tp,typename ...Args>
inline void wrt(_Tp x,Args ...args){wrt(x),wrt(args...);}
#undef MAXSIZE
}
using IO::read,IO::nread,IO::wrt;
const ll N=110,L=27;
ll n1,n2,l1,l2,ans,tot;
ll dp[L][N];
// dp[i][j] = min elements of s1 from j need to span conn(s2,2^i)
char s1[N],s2[N];
signed main(){
    while(~scanf("%s%lld%s%lld",s2,&n2,s1,&n1)){
        l1=strlen(s1),l2=strlen(s2),ans=tot=0;
        for(ll i=0;i<l1;i++){
            ll p=i;
            dp[0][i]=0;
            for(ll j=0;j<l2;j++){
                ll cnt=0;
                while(s1[p]!=s2[j]){
                    ++p%=l1;
                    if(++cnt>=l1){puts("0");goto CON;}
                }
                dp[0][i]+=cnt+1,++p%=l1;
            }
        }
        for(ll i=1;i<L;i++)for(ll j=0;j<l1;j++)
            dp[i][j]=dp[i-1][j]+dp[i-1][(j+dp[i-1][j])%l1];
        for(ll i=L-1;~i;i--)if(tot+dp[i][tot%l1]<=l1*n1)
            tot+=dp[i][tot%l1],ans+=1<<i;
        wrt(ans/n2,'\n');
        CON:;
    }
    return 0;
}
/*
ab 2
acb 4
acb 1
acb 1
aa 1
aaa 3
baab 1
baba 11
aaaaa 1
aaa 20

*/
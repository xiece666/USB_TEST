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
const int N=15,M=35,mod=11380;
int n[3],m;
int dp[N][N][N][M];
signed main(){
    read(n[0],n[1],n[2],m);
    for(int i=0;i<=m;i++)dp[0][0][0][i]=1;
    for(int d=1;d<=m;d++)for(int a=0;a<=n[0];a++)
        for(int b=0;b<=n[1];b++)for(int c=0;c<=n[2];c++){
            if(a>0)for(int i=1;i<=a;i++)for(int j=0;j<=b;j++)
                for(int k=0;k<=c;k++)(dp[a][b][c][d]+=dp[i-1][j][k][d-1]*dp[a-i][b-j][c-k][d])%=mod;
            if(b>0)for(int j=1;j<=b;j++)for(int k=0;k<=c;k++)
                (dp[a][b][c][d]+=dp[0][j-1][k][d-1]*dp[a][b-j][c-k][d])%=mod;
            if(c>0)for(int k=1;k<=c;k++)(dp[a][b][c][d]+=dp[0][0][k-1][d-1]*dp[a][b][c-k][d])%=mod;
        }
    wrt((dp[n[0]][n[1]][n[2]][m]+mod-dp[n[0]][n[1]][n[2]][m-1])%mod,'\n');
    return 0;
}
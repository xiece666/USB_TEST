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
const ll D=15,N=9;
int n,a[N][N];
ldb dp[N][N][N][N][D];
ldb ave;
ldb calc(int sx,int sy,int ex,int ey){
    ldb s=a[ex][ey]-a[sx-1][ey]-a[ex][sy-1]+a[sx-1][sy-1];
    return (s-ave)*(s-ave);
}
signed main(){
    read(n);
    for(int i=1;i<N;i++)for(int j=1;j<N;j++)
        read(a[i][j]),a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    ave=(ldb)(a[N-1][N-1])/n;
    for(int i=1;i<N;i++)for(int j=1;j<N;j++)for(int k=i;k<N;k++)
        for(int l=j;l<=N;l++)dp[i][j][k][l][1]=calc(i,j,k,l);
    for(int d=2;d<=n;d++)for(int ex=1;ex<N;ex++)for(int ey=1;ey<N;ey++)
        for(int sx=ex;sx;sx--)for(int sy=ey;sy;sy--){
            ldb &t=dp[sx][sy][ex][ey][d];
            t=1e9;
            for(int i=sx;i<ex;i++){
                t=min(t,dp[sx][sy][i][ey][d-1]+calc(i+1,sy,ex,ey));
                t=min(t,dp[i+1][sy][ex][ey][d-1]+calc(sx,sy,i,ey));
            }
            for(int i=sy;i<ey;i++){
                t=min(t,dp[sx][sy][ex][i][d-1]+calc(sx,i+1,ex,ey));
                t=min(t,dp[sx][i+1][ex][ey][d-1]+calc(sx,sy,ex,i));
            }
        }
    printf("%.3Lf\n",sqrt(dp[1][1][N-1][N-1][n]/n));
    return 0;
}
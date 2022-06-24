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
const ll N=1010;
int n,m,X,Y;
db a[N][N],dp[N][N];
signed main(){
    read(n,m,X,Y);
    if(m==1)return printf("%d.0000\n",(n-X)<<1),0;
    for(int h=n-1;h>=X;h--){
        a[1][1]=2.0/3,a[1][2]=-1.0/3,a[1][m+1]=1.0/3*dp[h+1][1]+1;
        for(int i=2;i<m;i++)
            a[i][i]=0.75,a[i][i-1]=a[i][i+1]=-0.25,a[i][m+1]=0.25*dp[h+1][i]+1;
        a[m][m]=2.0/3,a[m][m-1]=-1.0/3,a[m][m+1]=1.0/3*dp[h+1][m]+1;
        for(int i=2;i<=m;i++){
            db k=a[i][i-1]/a[i-1][i-1];
            a[i][i-1]=0.0,a[i][i]-=a[i-1][i]*k,a[i][m+1]-=a[i-1][m+1]*k;
        }
        dp[h][m]=a[m][m+1]/a[m][m];
        for(int i=m-1;i;i--)dp[h][i]=(a[i][m+1]-a[i][i+1]*dp[h][i+1])/a[i][i];
    }
    printf("%.4lf\n",dp[X][Y]);
    return 0;
}
/*
10 14 
5 14

*/
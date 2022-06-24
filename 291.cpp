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
const ll N=11;
int n,m;
ll dp[N+1][1<<N];
bitset<1<<N>fl;
signed main(){
    while(read(n,m),n&&m){
        dp[0][0]=1;
        for(int i=0;i<(1<<m);i++){
            bool t=0,f=0;
            for(int j=0;j<m;j++)
                if(i&(1<<j))f|=t,t=0;
                else t^=1;
            fl[i]=!(f|t);
        }
        for(int i=1;i<=n;i++)for(int j=0;j<(1<<m);j++){
            dp[i][j]=0;
            for(int k=0;k<(1<<m);k++)if(!(j&k)&&fl[j|k])
                dp[i][j]+=dp[i-1][k];
        }
        wrt(dp[n][0],'\n');
    }
    return 0;
}
/* 
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0

*/
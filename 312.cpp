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
const ll N=351,M=41;
bool st;
int n,m,t[5],val[N],ans=-1;
int dp[5][M][M][M];
bool ed;
signed main(){
    read(n,m);
    for(int i=1;i<=n;i++)read(val[i]);
    for(int i=1,x;i<=m;i++)
        read(x),t[x]++;
    mem(dp,0xcf),dp[1][0][0][0]=val[1];
    for(int i=2;i<=n;i++){
        int f0=i%5,f1=(i-1)%5,f2=(i-2)%5,f3=(i-3)%5,f4=(i-4)%5;
        for(int a=0;a<=t[1];a++)for(int b=0;b<=t[2];b++)
            for(int c=0;c<=t[3];c++){
                int d=m-a-b-c;
                dp[f0][a][b][c]=INT_MIN/2;
                if(a&&i>1)dp[f0][a][b][c]=max(dp[f0][a][b][c],dp[f1][a-1][b][c]);
                if(b&&i>2)dp[f0][a][b][c]=max(dp[f0][a][b][c],dp[f2][a][b-1][c]);
                if(c&&i>3)dp[f0][a][b][c]=max(dp[f0][a][b][c],dp[f3][a][b][c-1]);
                if(d&&i>4)dp[f0][a][b][c]=max(dp[f0][a][b][c],dp[f4][a][b][c]);
                dp[f0][a][b][c]+=val[i];
            }
    }
    for(int a=0;a<=t[1];a++)for(int b=0;b<=t[2];b++)
        for(int c=0;c<=t[3];c++)ans=max(ans,dp[n%5][a][b][c]);
    wrt(ans);
    return 0;
}
/*
9 5
6 10 14 2 8 8 18 5 17
1 3 1 2 1

*/
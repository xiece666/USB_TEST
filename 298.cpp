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
const ll N=16010,M=110;
int n,m,c;
int dp[M][N];
int q[N],h,t;
struct lyl{
    int l,p,val;
    bool operator<(const lyl b)const{return p<b.p;}
}a[N];
int calc(int y){return dp[c-1][y]-y*a[c].val;}
signed main(){
    read(n,m);
    for(int i=1,x,y,z;i<=m;i++)
        read(x,y,z),a[i]=(lyl){x,z,y};
    sort(a+1,a+1+m);
    for(c=1;c<=m;c++){
        // printf("{%d,%d,%d}\n",a[c].l,a[c].p,a[c].val);
        q[h=t=1]=0;
        for(int i=1;i<=n;i++){
            dp[c][i]=max(dp[c-1][i],dp[c][i-1]);
            if(a[c].p<=i){
                while(h<=t&&q[h]+a[c].l<i)h++;
                if(h<=t)dp[c][i]=max(dp[c][i],calc(q[h])+i*a[c].val);
            }
            if(i<a[c].p){
                while(h<=t&&calc(i)>=calc(q[t]))t--;
                q[++t]=i;
            }
            // printf("dp[%d][%d]:%d\n",c,i,dp[c][i]);
        }
    }
    wrt(dp[m][n]);
    return 0;
}
/*
8 4
3 2 2
3 2 3
3 3 5
1 1 7
*/
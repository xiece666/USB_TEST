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
const ll N=110;
int n,m;
vector<pii>g[N];
db a[N][N],ans;
void gauss(){
    for(int i=1;i<=n;i++){
        int mx=i;
        for(int j=i+1;j<=n;j++)
            if(fabs(a[j][i])>fabs(a[mx][i]))mx=j;
        if(mx!=i)swap(a[i],a[mx]);
        for(int j=n+1;j>=i;j--)a[i][j]/=a[i][i];
        for(int j=1;j<=n;j++)if(i!=j)
            for(int k=n+1;k>=i;k--)a[j][k]-=a[j][i]*a[i][k];
    }
}
signed main(){
    read(n,m);
    for(int i=1,x,y,z;i<=m;i++){
        read(x,y,z),g[x].ebk(y,z);
        if(x!=y)g[y].ebk(x,z);
    }
    for(int b=0;b<30;b++){
        for(int u=1;u<n;u++){
            for(int v=1;v<=n+1;v++)a[u][v]=0;
            a[u][u]=g[u].size();
            for(auto [v,val]:g[u])
                if(val&(1<<b))a[u][v]+=1,a[u][n+1]+=1;
                else a[u][v]-=1;
        }
        a[n][n]=1;
        gauss();
        ans+=a[1][n+1]*(1<<b);
    }
    printf("%.3lf\n",ans);
    return 0;
}
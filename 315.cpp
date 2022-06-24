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
const ll N=85,S=26;
int n,m;
char s[N],t[N];
int dp[N][N];
int ps[N][S],pt[N][S];
set<string>st;
void dfs(int x,int y,int l,string cur){
    if(x<0||y<0)return;
    if(!l)return st.emplace(cur),void();
    if(!x||!y)return;
    if(dp[x][y]!=l)return;
    for(int i=0;i<S;i++)
        dfs(ps[x][i]-1,pt[y][i]-1,l-1,(char)('a'+i)+cur);
}
signed main(){
    read(s+1),read(t+1);
    n=strlen(s+1),m=strlen(t+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        if(s[i]==t[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
    for(int i=1;i<=n;i++)for(int j=0;j<S;j++)
        if(s[i]=='a'+j)ps[i][j]=i;
        else ps[i][j]=ps[i-1][j];
    for(int i=1;i<=m;i++)for(int j=0;j<S;j++)
        if(t[i]=='a'+j)pt[i][j]=i;
        else pt[i][j]=pt[i-1][j];
    dfs(n,m,dp[n][m],"");
    for(auto i=st.begin();i!=st.end();i++)wrt((*i).c_str(),'\n');
    return 0;
}
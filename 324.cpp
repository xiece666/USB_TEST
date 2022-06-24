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
#define gchar() getchar()
// #define gchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXSIZE,stdin),p1==p2)?EOF:*p1++)
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
const ll N=210;
int n,V,rt,c[N],w[N];
int dp[N][N];
int tot;
unordered_map<string,int>mp;
vector<int>g[N];
bitset<N>fl;
string s,t;
stringstream buf;
void dfs(int u){
    dp[u][0]=0;
    for(int i=1;i<=V;i++)dp[u][i]=1e9;
    for(int v:g[u])dfs(v),c[u]+=c[v];
    for(int v:g[u])for(int i=c[u];i;i--)for(int j=1;j<=i;j++)
        dp[u][i]=min(dp[u][i],dp[u][i-j]+dp[v][j]);
    for(int i=1;i<=c[u];i++)dp[u][i]=min(dp[u][i],w[u]);
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    while(getline(cin,s),s[0]!='#'){
        buf.clear(),buf.str(s),buf>>n>>V;
        fl=rt=tot=0,mp.clear();
        for(int i=0;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++){
            getline(cin,s),buf.clear(),buf.str(s);
            buf>>t,!mp[t]&&(mp[t]=++tot);
            int x=mp[t];
            buf>>w[x],c[x]=1;
            // printf("%s %d\n",t.c_str(),x);
            while(buf>>t){
                !mp[t]&&(mp[t]=++tot);
                int y=mp[t];
                g[x].ebk(y),fl[y]=1;
                // printf("%d %d\n",x,y);
            }
        }
        // for(auto [x,y]:mp)printf("%s:%d\n",x.c_str(),y);
        w[0]=1e9,c[0]=1;
        for(int i=1;i<=n;i++)if(!fl[i])g[0].ebk(i);
        dfs(0);
        wrt(dp[0][V],'\n');
    }
    return 0;
}
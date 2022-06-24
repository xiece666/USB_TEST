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
const ll N=1010,mod=1e9+7;
int n,m,S,a[N],ans;
int dp[N][N];
vector<int>g;
class BIT{
    private:
        int ar[N];
    public:
        inline void clear(){for(int i=1;i<=S;i++)ar[i]=0;}
        inline void add(int p,int d){
            for(;p<=S;p+=p&-p)(ar[p]+=d)%=mod;
 // need to config~~^
        }
        inline int ask(int p){
            int res=0;
            for(;p;p&=p-1)(res+=ar[p])%=mod;
            return res;
        }
}bit;
signed main(){
    int Task;read(Task);
   for(int T=1;T<=Task;T++){
        // do you clear array&value?
        read(n,m),g.clear(),ans=0;
        for(int i=1;i<=n;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++)
            nread(a[i]),g.ebk(a[i]);
        sort(g.begin(),g.end()),g.erase(unique(g.begin(),g.end()),g.end());
        S=g.size()+1;
        for(int i=1;i<=n;i++)a[i]=lower_bound(g.begin(),g.end(),a[i])-g.begin()+2;
        dp[0][0]=a[0]=1;
        for(int i=1;i<=m;i++){
            bit.clear();
            for(int j=1;j<=n;j++){
                bit.add(a[j-1],dp[i-1][j-1]);
                dp[i][j]=bit.ask(a[j]-1);
            }
        }
        for(int i=1;i<=n;i++)(ans+=dp[m][i])%=mod;
        wrt("Case #",T,": ",ans,'\n');
    }
    return 0;
}
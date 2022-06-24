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
const ll N=1e5+10,M=1e18;
int n,L,P,a[N];
char s[N][35];
ldb dp[N];
int fr[N];
int h,t;
struct lyl{int l,r,p;}q[N];
ldb w(int x,int y){
    ldb res=1,v=abs(a[y]-a[x]+y-x-1-L);
    for(int i=P;i;v*=v,i>>=1)
        if(i&1)res*=v;
    return res+dp[x];
}
void print(int p){
    if(!p)return;
    print(fr[p]);
    for(int i=fr[p]+1;i<p;i++)wrt(s[i],' ');
    wrt(s[p],'\n');
}
signed main(){
    int Task;read(Task);
    while(Task--){
        // do you clear array&value?
        read(n,L,P);
        for(int i=1;i<=n;i++)
            read(s[i]),a[i]=strlen(s[i])+a[i-1];
        // wrt(w(0,1),'\n');
        q[h=t=1]=(lyl){1,n,0};
        for(int i=1;i<=n;i++){
            // wrt("w(0,",i,"):",w(0,i),'\n');
            while(h<=t&&q[h].r<i)h++;
            q[h].l=i;
            int pos=-1;
            dp[i]=w(fr[i]=q[h].p,i);
            // wrt("dp[",i,"]:",dp[i]," <- ",fr[i],'\n');
            while(h<=t&&w(q[t].p,q[t].l)>=w(i,q[t].l))pos=q[t--].l;
            if(w(q[t].p,q[t].r)>=w(i,q[t].r)){
                pos=-1;
                int l=q[t].l,r=q[t].r;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(w(q[t].p,mid)>=w(i,mid))pos=mid,r=mid-1;
                    else l=mid+1;
                }
                assert(~pos);
                q[t].r=pos-1;
            }
            if(~pos)q[++t]=(lyl){pos,n,i};
        }
        if(dp[n]<=M)wrt((ll)dp[n],'\n'),print(n);
        else puts("Too hard to arrange");
        puts("--------------------");
    }
    return 0;
}
/*
4
4 9 3
brysj,
hhrhl.
yqqlm,
gsycl.
4 9 2
brysj,
hhrhl.
yqqlm,
gsycl.
1 1005 6
poet
1 1004 6
poet

*/
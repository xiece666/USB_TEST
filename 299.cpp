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
const ll N=1e5+10;
ll n,m,a[N],s[N],ans;
ll dp[N];
ll st[N],tp=1,pos;
class SegmentTree{
    private:
        int L,R,D;
        int mn[N<<2],tag[N<<2];
        void push_up(int rt){mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);}
        void update(int rt,int d){mn[rt]+=d,tag[rt]+=d;}
        void push_down(int rt){
            if(!tag[rt])return;
            update(rt<<1,tag[rt]),update(rt<<1|1,tag[rt]);
            tag[rt]=0;
        }
        void __modify(int rt,int l,int r){
            if(L<=l&&r<=R)return update(rt,D);
            push_down(rt);
            int mid=(l+r)>>1;
            if(L<=mid)__modify(rt<<1,l,mid);
            if(R>mid)__modify(rt<<1|1,mid+1,r);
            push_up(rt);
        }
        int __query(int rt,int l,int r){
            if(L<=l&&r<=R)return mn[rt];
            push_down(rt);
            int mid=(l+r)>>1,res=INT_MAX;
            if(L<=mid)res=min(res,__query(rt<<1,l,mid));
            if(R>mid)res=min(res,__query(rt<<1|1,mid+1,r));
            return res;
        }
    public:
        void modify(int l,int r,int d){L=l,R=r,D=d,__modify(1,0,n);}
        int query(int l,int r){return L=l,R=r,__query(1,0,n);}
}segT;
signed main(){
    read(n,m),a[0]=1e9;
    for(int i=1;i<=n;i++){
        read(a[i]);
        if(a[i]>m)return puts("-1"),0;
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        while(s[i]-s[pos]>m)pos++;
        segT.modify(i-1,i-1,a[i]);
        while(a[st[tp]]<=a[i]){
            segT.modify(st[tp-1],st[tp]-1,a[i]-a[st[tp]]);
            tp--;
        }
        st[++tp]=i;
        segT.modify(i,i,ans=segT.query(pos,i-1));
    }
    wrt(ans);
    return 0;
}
/*
8 17
2 2 2 8 1 8 2 1
*/
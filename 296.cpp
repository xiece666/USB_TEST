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
#define pii pair<ll,ll>
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
template<typename _Tp,typename ...Args>
inline void wrt(_Tp x,Args ...args){wrt(x),wrt(args...);}
#undef MAXSIZE
}using IO::read,IO::nread,IO::wrt;
const ll N=1e4+10,S=86409;
ll n,L,R,c[S],ans=INT_MAX;
struct lyl{
    ll l,r,val;
    bool operator<(const lyl b)const{return r<b.r;}
}a[N];
class SegmentTree{
    private:
        ll tl,tr,D;
        ll mn[S<<2];
        void push_up(ll rt){mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);}
        void __modify(ll rt,ll l,ll r){
            if(l==r)return mn[rt]=min(mn[rt],D),void();
            ll mid=(l+r)>>1;
            if(tl<=mid)__modify(rt<<1,l,mid);
            else __modify(rt<<1|1,mid+1,r);
            push_up(rt);
        }
        ll __query(ll rt,ll l,ll r){
            if(tl<=l&&r<=tr)return mn[rt];
            ll mid=(l+r)>>1,res=INT_MAX;
            if(tl<=mid)res=min(res,__query(rt<<1,l,mid));
            if(tr>mid)res=min(res,__query(rt<<1|1,mid+1,r));
            return res;
        }
        void __build(ll rt,ll l,ll r){
            mn[rt]=INT_MAX;
            if(l==r)return;
            ll mid=(l+r)>>1;
            __build(rt<<1,l,mid),__build(rt<<1|1,mid+1,r);
        }
    public:
        void build(){__build(1,L-1,R);}
        void modify(ll p,ll d){tl=p,D=d,__modify(1,L-1,R);}
        ll query(ll l,ll r){return tl=l,tr=r,__query(1,L-1,R);}
}segT;
signed main(){
    read(n,L,R),L++,R++;
    for(ll i=1,x,y,z;i<=n;i++)
        read(x,y,z),a[i]=(lyl){++x,++y,z},c[x]++,c[y+1]--;
    for(ll i=L;i<=R;i++)if(!(c[i]+=c[i-1]))return puts("-1"),0;
    sort(a+1,a+1+n);
    segT.build(),segT.modify(L-1,0);
    for(ll i=1;i<=n;i++){
        ll res=segT.query(a[i].l-1,a[i].r-1)+a[i].val;
        segT.modify(a[i].r,res);
        if(a[i].r==R)ans=min(ans,res);
    }
    wrt(ans);
    return 0;
}
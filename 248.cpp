#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define pbk push_back
#define fir first
#define sec second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
template <typename T> inline void read(T &x){
    x=0;T f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    x*=f;
}
template<typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void wrt(T x){
    if(x<0) x=-x,putchar('-');
    if(x>9) wrt(x/10);
    putchar(x%10+48);
}
template <typename T> void wrt(T x,char c){wrt(x),putchar(c);}
template <typename T1,typename T2> void wrt(T1 x1,char c1,T2 x2,char c2){wrt(x1,c1),wrt(x2,c2);}
const ll N=2e4+10;
ll n,m,H,W,ans,ly[N],ry[N];
ll L,R,D,mx[N<<2],lazy[N<<2];
vector<ll>g;
struct lyl{
    ll x,yl,yr,del;
    bool operator<(const lyl a)const{
        return x==a.x?del>a.del:x<a.x;
    }
}p[N];
inline void push_up(ll rt){mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);}
inline void push_down(ll rt){
    ll ls=rt<<1,rs=rt<<1|1;
    lazy[ls]+=lazy[rt],lazy[rs]+=lazy[rt];
    mx[ls]+=lazy[rt],mx[rs]+=lazy[rt];
    lazy[rt]=0;
}
inline void update(ll rt,ll l,ll r){
    if(L<=l&&r<=R){
        mx[rt]+=D,lazy[rt]+=D;
        return;
    }
    push_down(rt);
    ll mid=(l+r)>>1;
    if(L<=mid)update(rt<<1,l,mid);
    if(R>mid)update(rt<<1|1,mid+1,r);
    push_up(rt);
}
int main(){
    while(~scanf("%lld%lld%lld",&n,&W,&H)){
        for(ll i=1,a,b,c;i<=n;i++){
            read(a,b,c);
            p[i*2-1].x=a,p[i<<1].x=a+W-1;
            p[i*2-1].del=c,p[i<<1].del=-c;
            ly[i*2-1]=ly[i<<1]=b;
            ry[i*2-1]=ry[i<<1]=b+H-1;
            g.pbk(b),g.pbk(b+H-1);
        }
        sort(g.begin(),g.end());
        g.erase(unique(g.begin(),g.end()),g.end());
        m=g.size();
        for(ll i=1;i<=n;i++){
            p[i*2-1].yl=p[i<<1].yl=lower_bound(g.begin(),g.end(),ly[i<<1])-g.begin()+1;
            p[i*2-1].yr=p[i<<1].yr=lower_bound(g.begin(),g.end(),ry[i<<1])-g.begin()+1;
        }
        sort(p+1,p+1+2*n);
        ans=0;
        for(ll i=1;i<=2*n;i++){
            L=p[i].yl,R=p[i].yr,D=p[i].del;
            update(1,1,m);
            ans=max(ans,mx[1]+lazy[1]);
            // printf("x:%d L:%d R:%d D:%d current_max:%d ans:%d\n",p[i].x,L,R,D,mx[1]+lazy[1],ans);
        }
        wrt(ans,'\n');        
    }
    return  0;
}
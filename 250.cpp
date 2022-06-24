#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define mkp make_pair
#define ebk emplace_back
#define fir first
#define sec second
#define pll pair<ll,ll>
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
using namespace __gnu_pbds;
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
const ll N=2.5e5+10,SN=510;
ll n,sx,sy,ps,rs,ans;
ll bl,cnt,st[SN],ed[SN],mi[SN],mx[SN],vis[N];
struct lyl{ll x,y,m,p,r;}a[N];
queue<pll>q;
ll dis(lyl t){return (t.x-sx)*(t.x-sx)+(t.y-sy)*(t.y-sy);}
int main(){
    read(sx,sy,ps,rs,n),bl=sqrt(n),rs*=rs;
    for(ll i=1;i<=n;i++)read(a[i].x,a[i].y,a[i].m,a[i].p,a[i].r),a[i].r*=a[i].r;
    sort(a+1,a+1+n,[&](lyl xx,lyl yy){return xx.m<yy.m;});
    for(ll i=1;i<=n;i+=bl){
        st[++cnt]=i,ed[cnt]=min(i+bl-1,n);
        mi[cnt]=a[st[cnt]].m,mx[cnt]=a[ed[cnt]].m;
        sort(a+st[cnt],a+ed[cnt]+1,[&](lyl xx,lyl yy){return dis(xx)<dis(yy);});
    }
    // for(ll i=1;i<=cnt;puts(""),i++)for(ll j=st[i];j<=ed[i];j++)
    //     printf("{%d,%d,%d,%d,%d} %d\n",a[j].x,a[j].y,a[j].m,a[j].p,a[j].r,dis(a[j]));
    q.emplace(ps,rs),vis[0]=1;
    while(!q.empty()){
        ll up=q.front().fir,ur=q.front().sec;q.pop();
        ans++;
        for(ll k=1;k<=cnt;k++){
            if(mi[k]>up)break;
            if(mx[k]<=up){
                while(st[k]<=ed[k]&&dis(a[st[k]])<=ur){
                    if(!vis[st[k]])q.emplace(a[st[k]].p,a[st[k]].r);
                    vis[st[k]++]=1;
                }
            }else if(mi[k]<=up){
                for(ll i=st[k];i<=ed[k];i++)
                    if(dis(a[i])<=ur&&a[i].m<=up&&!vis[i])
                        q.emplace(a[i].p,a[i].r),vis[i]=1;
            }
        }
    }
    wrt(ans-1);
    return 0;
}
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define fir first
#define sec second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=1e5+10;
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
ll n,k,ans,p[N],l[N],r[N];
bitset<N>fl;
struct lyl{
    ll val,pos;
    bool operator<(const lyl a)const{
        return val>a.val;
    }
};
__gnu_pbds::priority_queue<lyl>q;
__gnu_pbds::priority_queue<lyl>::point_iterator it[N];
int main(){
    read(n,k);
    for(ll i=1;i<=n;i++)read(p[i]),p[i-1]=p[i]-p[i-1];
    n--;
    for(ll i=1;i<=n;i++){
        l[i]=i-1,r[i]=i+1;
        it[i]=q.push((lyl){p[i],i});
    }
    fl[0]=fl[n+1]=1;
    p[0]=p[n+1]=INT_MAX;
    while(k--&&!q.empty()){
        ll u=q.top().pos;
        ans+=p[u];
        ll L=l[u],R=r[u];
        if(!fl[L])q.erase(it[L]);
        if(!fl[R])q.erase(it[R]);
        fl[L]=fl[R]=1;
        p[u]=p[L]+p[R]-p[u];
        l[u]=l[L],r[u]=r[R];
        r[l[L]]=l[r[R]]=u;
        q.modify(it[u],(lyl){p[u],u});
    }
    wrt(ans);
    return  0;
}
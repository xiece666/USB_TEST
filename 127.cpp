#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define x first
#define y second
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
ll n,m,anst,anss;
pair<ll,ll>p[N],q[N];
multiset<ll>s;
int main(){
    read(n,m);
    for(ll i=1;i<=n;i++)read(q[i].x,q[i].y);
    for(ll i=1;i<=m;i++)read(p[i].x,p[i].y);
    sort(p+1,p+1+m,greater<pair<ll,ll>>());
    sort(q+1,q+1+n,greater<pair<ll,ll>>());
    for(ll i=1,j=1;i<=m;i++){
        while(j<=n&&p[i].x<=q[j].x)s.insert(q[j++].y);
        auto t=s.lower_bound(p[i].y);
        if(t==s.end())continue;
        anst++,anss+=500*p[i].x+(p[i].y<<1);
        s.erase(t);
    }
    wrt(anst,' ',anss,'\n');
    return  0;
}
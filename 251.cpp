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
const ll N=5e4+10;
ll n,m,cnt,p[N],t[N];
ll bl,ct,L,R;
struct lyl{
    ll l,r,num;
    bool operator<(const lyl a)const{
        return l/bl==a.l/bl?(r>a.r)^((l/bl)&1):l<a.l;
    }
}q[N];
struct fraction{
    ll so,ma;
    fraction& fix(){
        if(!so){
            ma=1;
            return *this;
        }
        ll tmp=__gcd(ma,so);
        ma/=tmp,so/=tmp;
        return *this;
    }
}ans[N];
inline void insert(ll x){cnt+=2*t[x],t[x]++;}
inline void erase(ll x){t[x]--,cnt-=2*t[x];}
int main(){
    read(n,m),bl=sqrt(n);
    for(ll i=1;i<=n;i++)read(p[i]);
    for(ll i=1;i<=m;i++)read(q[i].l,q[i].r),q[i].num=i;
    sort(q+1,q+1+m);
    L=1,R=0;
    for(ll i=1;i<=m;i++){
        // printf("{%d,%d,%d}\n",q[i].l,q[i].r,q[i].num);
        if(q[i].l==q[i].r){
            ans[q[i].num]=(fraction){0,1};
            continue;
        }
        while(L>q[i].l)insert(p[--L]);
        while(R<q[i].r)insert(p[++R]);
        while(L<q[i].l)erase(p[L++]);
        while(R>q[i].r)erase(p[R--]);
        // printf("L:%d R:%d cnt:%d\n",L,R,cnt);
        ans[q[i].num]=(fraction){cnt,(R-L)*(R-L+1)}.fix();
    }
    for(ll i=1;i<=m;i++)wrt(ans[i].so,'/',ans[i].ma,'\n');
    return 0;
}
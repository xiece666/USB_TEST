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
const ll N=5e5+10;
template<typename _Tp,const int SI>
class BIT{
    private:
        _Tp array[SI+10];
        inline _Tp lowbit(_Tp x){return x&-x;}
    public:
        inline void clear(){mem(array,0);}
        inline void config(_Tp __pos,_Tp delta){
            for(;__pos<=SI;__pos+=lowbit(__pos))array[__pos]+=delta;
        }
        inline _Tp prefix_sum(_Tp __pos){
            if(__pos<0)return 0;
            _Tp res=_Tp();
            for(;__pos;__pos-=lowbit(__pos))res+=array[__pos];
            return res;
        }
        inline _Tp range_sum(_Tp __l,_Tp __r){
            return prefix_sum(__r)-prefix_sum(__l-1);
        }
};
BIT<ll,N-10>bit;
ll n,Q,P,D,L,R,p[N];
ll _gcd[N<<2];
inline void push_up(ll rt){_gcd[rt]=__gcd(_gcd[rt<<1],_gcd[rt<<1|1]);}
inline void build(ll rt,ll l,ll r){
    if(l==r)return void(_gcd[rt]=p[l]);
    ll mid=(l+r)>>1;
    build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
    push_up(rt);
    // printf("_gcd[%lld,%lld]:%lld\n",l,r,_gcd[rt]);
}
inline void update(ll rt,ll l,ll r){
    if(l==r)return void(_gcd[rt]+=D);
    ll mid=(l+r)>>1;
    if(P<=mid)update(rt<<1,l,mid);
    else update(rt<<1|1,mid+1,r);
    push_up(rt);
    // printf("_gcd[%lld,%lld]:%lld\n",l,r,_gcd[rt]);
}
inline ll query(ll rt,ll l,ll r){
    // printf("query[%lld,%lld]:\n",l,r);
    if(L<=l&&r<=R)return _gcd[rt];
    ll mid=(l+r)>>1,res=0;
    if(L<=mid)res=__gcd(query(rt<<1,l,mid),res);
    if(R>mid)res=__gcd(query(rt<<1|1,mid+1,r),res);
    return abs(res);
}
int main(){
    read(n,Q);
    for(int i=1;i<=n;i++)read(p[i]);
    for(int i=n;i;i--)p[i]-=p[i-1];
    for(int i=1;i<=n;i++)bit.config(i,p[i]);
    build(1,1,n);
    while(Q--){
        char c;cin>>c;
        ll l,r,d;
        read(l,r);
        if(c=='C'){
            read(d);
            P=l,D=d,update(1,1,n),bit.config(l,d);
            if(r<n)P=r+1,D=-d,update(1,1,n),bit.config(r+1,-d);
        }else{
            L=l+1,R=r;
            // putchar('>');
            if(l==r)wrt(bit.prefix_sum(l),'\n');
            else wrt(__gcd(bit.prefix_sum(l),query(1,1,n)),'\n');
        }
    }
    return  0;
}
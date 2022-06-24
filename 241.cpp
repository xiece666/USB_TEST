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
template <typename T1,typename T2> void wrt(T1 x1,char c,T2 x2){wrt(x1,c),wrt(x2);}
template <typename T1,typename T2> void wrt(T1 x1,char c1,T2 x2,char c2){wrt(x1,c1),wrt(x2,c2);}
const ll N=2e5+10;
ll n,p[N],pre_smaller[N],pre_bigger[N];
ll ansa,ansv;
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
int main(){
    read(n);
    for(ll i=1;i<=n;i++)read(p[i]);
    for(ll i=1;i<=n;i++){
        pre_smaller[i]=bit.prefix_sum(p[i]-1);
        pre_bigger[i]=bit.range_sum(p[i]+1,n);
        bit.config(p[i],1);
    }
    bit.clear();
    for(ll i=n;i;i--){
        ansa+=pre_smaller[i]*bit.prefix_sum(p[i]-1);
        ansv+=pre_bigger[i]*bit.range_sum(p[i]+1,n);
        bit.config(p[i],1);
    }
    wrt(ansv,' ',ansa);
    return  0;
}
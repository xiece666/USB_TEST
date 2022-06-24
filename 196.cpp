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
const ll N=1e6+10;
ll L,R,SR,cl1,cl2,di1,di2,cl,di,la;
vector<ll>prime;
bitset<N>vis;
int main(){
    while(~scanf("%lld%lld",&L,&R)){
        vis=0,prime.clear();
        SR=(ll)(ceil(sqrt(R*1.0)));
        for(ll i=2;i<=SR;i++){
            if(!vis[i])prime.pbk(i);
            for(ll j=i;j*i<=SR;j++)vis[j*i]=1;
        }
        vis=0;
        // for(ll i:prime)wrt(i,'\n');
        for(ll i:prime)for(ll j=(ll)(ceil(L*1.0/i));j<=R/i;j++)
            if(j>1)vis[i*j-L]=1;
        la=-1,cl=1e7,di=-1;
        for(ll i=0;i<=R-L;i++)if(!vis[i]&&i+L>1){
            if(la==-1){
                la=i;
                continue;
            }
            if(cl>i-la)cl=i-la,cl1=la+L,cl2=i+L;
            if(di<i-la)di=i-la,di1=la+L,di2=i+L;
            la=i;
        }
        if(cl==1e7||di==-1)puts("There are no adjacent primes.");
        else printf("%lld,%lld are closest, %lld,%lld are most distant.\n",cl1,cl2,di1,di2);
    }
    return  0;
}
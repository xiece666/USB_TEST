#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
const ll N=1e5;
ll Q,a,b,c,d,ans;
//gcd(a,x)=c lcm(b,x)=d
vector<ll>prime;
bitset<N+10>vis;
inline bool calc(ll p){
    if(p>d)return 0;
    if(d%p)return 1;
    ll ma=0,mb=0,mc=0,md=0;
    while(a%p==0)ma++,a/=p;
    while(b%p==0)mb++,b/=p;
    while(c%p==0)mc++,c/=p;
    while(d%p==0)md++,d/=p;
    // printf("p:%lld\tma:%lld\tmb:%lld\tmc:%lld\tmd:%lld\n",p,ma,mb,mc,md);
    ll res=0;
    if((ma>mc&&mb<md&&mc==md)
     ||(ma>mc&&mb==md&&mc<=md)
     ||(ma==mc&&mb<md&&mc<=md))res=1;
    else if(ma==mc&&mb==md&&mc<=md)res=md-mc+1;
    // printf(" a:%lld\tb:%lld\tc:%lld\td:%lld\n",a,b,c,d);
    // printf(" p:%lld\tres:%lld\n",p,res);
    ans*=res;
    return 1;
}
int main(){
    for(ll i=2;i<=N;i++){
        if(!vis[i])prime.pbk(i);
        for(ll j=i;j*i<=N;j++)vis[j*i]=1;
    }
    read(Q);
    while(Q--){
        read(a,c,b,d);
        if(a%c|d%b|d%c){
            puts("0");
            continue;
        }
        // printf("a:%lld\tb:%lld\tc:%lld\td:%lld\n",a,b,c,d);
        ans=1;
        for(ll i:prime)if(!calc(i))break;
        if(d>1)ans*=calc(d);
        wrt(ans,'\n');
    }
    return  0;
}
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
#pragma GCC optimize(2)
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
const ll N=1e6+10,SIZE=1e6+10;
ll n,m,S,ans[N];
struct lyl{
    ll x,y,tp,id;
    bool operator<(const lyl a)const{return x==a.x?y<a.y:x<a.x;}
}op[N],p[N];
template<typename _Tp>
class BIT{
    private:
        _Tp array[SIZE];
        inline _Tp lowbit(_Tp x){return x&-x;}
    public:
        inline void set(_Tp pos){
            for(;pos<S;pos+=lowbit(pos))array[pos]=INT_MIN;
        }
        inline void config(_Tp pos,_Tp delta){
            for(;pos<S;pos+=lowbit(pos))array[pos]=max(array[pos],delta);
        }
        inline _Tp prefix_max(_Tp pos){
            _Tp res=INT_MIN;
            for(;pos;pos-=lowbit(pos))res=max(res,array[pos]);
            return res;
        }
};
BIT<ll>bit;
inline void solve(ll st,ll ed,ll dx,ll dy){
    for(ll i=st;i!=ed;i+=dx){
        ll y=(dy==1?p[i].y:S-p[i].y);
        ll sum=dx*p[i].x+dy*p[i].y;
        if(!p[i].tp)bit.config(y,sum);
        else ans[p[i].id]=min(ans[p[i].id],abs(sum-bit.prefix_max(y)));
    }
    for(ll i=st;i!=ed;i+=dx)if(!p[i].tp)bit.set(dy==1?p[i].y:S-p[i].y);
}
inline void CDQ_solve(ll L,ll R){
    if(L==R)return;
    ll mid=(L+R)>>1,tot=0;
    CDQ_solve(L,mid),CDQ_solve(mid+1,R);
    for(ll i=L;i<=R;i++)if((i<=mid&&!op[i].tp)||(i>mid&&op[i].tp))
        p[++tot]=op[i];
    sort(p+1,p+1+tot);
    // printf("[%d,%d]:\n",L,R);
    // for(ll i=1;i<=tot;i++)printf("p[%d]:{%d,%d,%d,%d}\n",i,p[i].x,p[i].y,p[i].tp,p[i].id);
    solve(1,tot+1,1,1);
    solve(1,tot+1,1,-1);
    solve(tot,0,-1,-1);
    solve(tot,0,-1,1);
}
int main(){
    read(n,m);
    for(ll i=1;i<=n;i++)read(op[i].x,op[i].y),op[i].tp=1;
    for(ll i=n+1;i<=n+m;i++)read(op[i].tp,op[i].x,op[i].y);
    for(ll i=1;i<=n+m;i++)op[i].x++,op[i].tp--,op[i].id=i,S=max(S,++op[i].y);
    S++,mem(ans,0x3f);
    for(ll i=1;i<S;i++)bit.set(i);
    CDQ_solve(1,n+m);
    for(ll i=1;i<=n+m;i++)if(op[i].tp)wrt(ans[i],'\n');
    return 0;
}
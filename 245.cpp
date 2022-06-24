#include<bits/stdc++.h>
#include<bits/extc++.h>
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
int n,Q,L,R,P,D;
int sum[N<<2],lmx[N<<2],rmx[N<<2],mx[N<<2];
struct lyl{int _1,_2,_3,_4;};
inline void push_up(int rt){
    int ls=rt<<1,rs=rt<<1|1;
    sum[rt]=sum[ls]+sum[rs];
    lmx[rt]=max(lmx[ls],sum[ls]+lmx[rs]);
    rmx[rt]=max(rmx[rs],sum[rs]+rmx[ls]);
    mx[rt]=max(max(mx[ls],mx[rs]),rmx[ls]+lmx[rs]);
}
inline void build(int rt,int l,int r){
    if(l==r){
        read(sum[rt]);
        lmx[rt]=rmx[rt]=mx[rt]=sum[rt];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
    push_up(rt);
}
inline void update(int rt,int l,int r){
    if(l==r){
        sum[rt]=lmx[rt]=rmx[rt]=mx[rt]=D;
        return;
    }
    int mid=(l+r)>>1;
    if(P<=mid)update(rt<<1,l,mid);
    else update(rt<<1|1,mid+1,r);
    push_up(rt);
}
inline lyl query(int rt,int l,int r){
    if(L<=l&&r<=R)return (lyl){sum[rt],lmx[rt],rmx[rt],mx[rt]};
    int mid=(l+r)>>1;
    lyl res1,res2,res;
    if(L<=mid)res=res1=query(rt<<1,l,mid);
    if(R>mid)res=res2=query(rt<<1|1,mid+1,r);
    if(L<=mid&&R>mid){
        res._1=res1._1+res2._1;
        res._2=max(res1._2,res1._1+res2._2);
        res._3=max(res2._3,res2._1+res1._3);
        res._4=max(max(res1._4,res2._4),res1._3+res2._2);
    }
    return res;
}
int main(){
    read(n,Q);
    build(1,1,n);
    while(Q--){
        int op,x,y;
        read(op,x,y);
        if(op==1){
            if(x>y)swap(x,y);
            L=x,R=y;
            // printf("start query(%d,%d):\n",L,R);
            wrt(query(1,1,n)._4,'\n');
        }else{
            P=x,D=y;
            update(1,1,n);
        }
    }
    return  0;
}
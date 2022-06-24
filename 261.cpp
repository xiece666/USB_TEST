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
#define pii pair<int,int>
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
const ll N=5e4+10;
int n,m;
int L,R,D;
int mx[N<<2],lmx[N<<2],rmx[N<<2],tag[N<<2],is0[N<<2];
void push_up(int rt){
    int ls=rt<<1,rs=rt<<1|1;
    mx[rt]=max(rmx[ls]+lmx[rs],max(mx[ls],mx[rs]));
    lmx[rt]=max(lmx[ls],is0[ls]?mx[ls]+lmx[rs]:0);
    rmx[rt]=max(rmx[rs],is0[rs]?mx[rs]+rmx[ls]:0);
    is0[rt]=is0[ls]&is0[rs];
}
void push_down(int rt,int l,int r){
    if(tag[rt]==-1)return;
    int mid=(l+r)>>1,ls=rt<<1,rs=rt<<1|1;
    tag[ls]=tag[rs]=tag[rt];
    is0[ls]=is0[rs]=tag[rt]^1;
    if(tag[rt]){
        lmx[ls]=rmx[ls]=mx[ls]=0;
        lmx[rs]=rmx[rs]=mx[rs]=0;
    }else{
        lmx[ls]=rmx[ls]=mx[ls]=mid-l+1;
        lmx[rs]=rmx[rs]=mx[rs]=r-mid;
    }
    tag[rt]=-1;
}
void build(int rt,int l,int r){
    tag[rt]=-1;
    if(l==r)return void(lmx[rt]=rmx[rt]=mx[rt]=is0[rt]=1);
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
    push_up(rt);
}
void cover(int rt,int l,int r){
    if(L<=l&&r<=R){
        is0[rt]=D^1,tag[rt]=D;
        if(D)mx[rt]=lmx[rt]=rmx[rt]=0;
        else mx[rt]=lmx[rt]=rmx[rt]=r-l+1;
        return;
    }
    push_down(rt,l,r);
    int mid=(l+r)>>1;
    if(L<=mid)cover(rt<<1,l,mid);
    if(R>mid)cover(rt<<1|1,mid+1,r);
    push_up(rt);
}
int query(int rt,int l,int r){
    push_down(rt,l,r);
    int mid=(l+r)>>1,ls=rt<<1,rs=rt<<1|1;
    if(lmx[rt]>=D)return l;
    if(mx[ls]>=D)return query(ls,l,mid);
    if(rmx[ls]+lmx[rs]>=D)return mid-rmx[ls]+1;
    return query(rs,mid+1,r);
}
int main(){
    read(n,m);
    build(1,1,n);
    while(m--){
        int op,x,y;
        read(op,x);
        if(op==1){
            if(mx[1]<x){
                puts("0");
                continue;
            }
            D=x;
            int pos=query(1,1,n);
            wrt(pos,'\n');
            L=pos,R=pos+x-1,D=1;
            cover(1,1,n);
        }else{
            read(y);
            L=x,R=x+y-1,D=0;
            cover(1,1,n);
        }
    }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long double
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
template <typename T> void wrt(T x,char c1,T y,char c2){wrt(x,c1),wrt(y,c2);}
const ull N=3e5+10;
ull n,m,k,tar[N],ans[N],p[N],ls[N],rs[N];
vector<ull>g[N];
struct lyl{
    ull l,r,s;
}op[N];
template<typename _Tp>
class BIT{
    private:
        _Tp array[N];
        inline _Tp lowbit(_Tp x){return x&-x;}
    public:
        inline void config(_Tp pos,_Tp delta){
            for(;pos<=m;pos+=lowbit(pos))array[pos]+=delta;
        }
        inline void update(ull x,ull y,ull d){
            if(x<=y)config(x,d),config(y+1,-d);
            else config(x,d),config(m+1,-d),config(1,d),config(y+1,-d);
        }
        inline _Tp prefix_sum(_Tp pos){
            if(pos<0)return 0;
            _Tp res=_Tp();
            for(;pos;pos-=lowbit(pos))res+=array[pos];
            return res;
        }
};
BIT<ull>bit;
inline void solve(ull L,ull R,ull l,ull r){
    if(L>R||l>r)return;
    // printf("[%d,%d] %d [%d,%d]\n",L,R,(L+R)>>1,l,r);
    // for(ull i=l;i<=r;i++)printf("\t{%d,%d}\n",p[i],tar[p[i]]);
    if(L==R){
        for(ull i=l;i<=r;i++)ans[p[i]]=L;
        return;
    }
    ull mid=(L+R)>>1,tl=0,tr=0;
    for(ull i=L;i<=mid;i++)bit.update(op[i].l,op[i].r,op[i].s);
    for(ull i=l;i<=r;i++){
        ull sum=0;
        for(ull j:g[p[i]])sum+=bit.prefix_sum(j);
        if(sum<tar[p[i]])tar[p[i]]-=sum,rs[++tr]=p[i];
        else ls[++tl]=p[i];
    }
    for(ull i=L;i<=mid;i++)bit.update(op[i].l,op[i].r,-op[i].s);
    for(ull i=l;i<l+tl;i++)p[i]=ls[i-l+1];
    for(ull i=l+tl;i<=r;i++)p[i]=rs[i-r+tr];
    solve(L,mid,l,l+tl-1),solve(mid+1,R,l+tl,r);
}
int main(){
    read(n,m),iota(p,p+1+n,0);
    for(ull i=1,x;i<=m;i++)read(x),g[x].pbk(i);
    for(ull i=1;i<=n;i++)read(tar[i]);
    read(k);
    for(ull i=1;i<=k;i++)read(op[i].l,op[i].r,op[i].s);
    op[++k]=(lyl){1,1,0};
    solve(1,k,1,n);
    for(ull i=1;i<=n;i++)
        if(ans[i]<k)wrt(ans[i],'\n');
        else puts("NIE");
    return 0;
}
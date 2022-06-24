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
const ll N=2e5+10;
int n,m,a[N];
vector<int>g;
class PersistentSegmentTree{
    private:
        int P,D;
        int tot,root[N];
        struct __node{int sum,ls,rs;}Tr[N<<5];
        int __new(int from=0){return Tr[++tot]=Tr[from],tot;}
        int __init(int l,int r){
            int new_rt=__new();
            if(l==r)return new_rt;
            int mid=(l+r)>>1;
            Tr[new_rt].ls=__init(l,mid);
            Tr[new_rt].rs=__init(mid+1,r);
            return new_rt;
        }
        int __insert(int rt,int l,int r){
            int new_rt=__new(rt);
            Tr[new_rt].sum++;
            if(l==r)return new_rt;
            int mid=(l+r)>>1;
            if(P<=mid)Tr[new_rt].ls=__insert(Tr[rt].ls,l,mid);
            else Tr[new_rt].rs=__insert(Tr[rt].rs,mid+1,r);
            return new_rt;
        }
        int __query(int rt_st,int rt_ed,int l,int r){
            if(l==r)return l;
            int mid=(l+r)>>1,s=Tr[Tr[rt_ed].ls].sum-Tr[Tr[rt_st].ls].sum;
            if(s>=D)return __query(Tr[rt_st].ls,Tr[rt_ed].ls,l,mid);
            return D-=s,__query(Tr[rt_st].rs,Tr[rt_ed].rs,mid+1,r);
        }
    public:
        void init(){root[0]=__init(1,g.size());}
        void insert(int tim,int pos,int del){P=pos,D=del,root[tim]=__insert(root[tim-1],1,g.size());}
        int query(int tim_st,int tim_ed,int ord){return D=ord,__query(root[tim_st-1],root[tim_ed],1,g.size());}
}SegT;
int main(){
    read(n,m);
    for(int i=1;i<=n;i++)
        read(a[i]),g.ebk(a[i]);
    sort(g.begin(),g.end()),g.erase(unique(g.begin(),g.end()),g.end());
    for(int i=1;i<=n;i++)a[i]=lower_bound(g.begin(),g.end(),a[i])-g.begin()+1;
    // for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    SegT.init();
    for(int i=1;i<=n;i++)SegT.insert(i,a[i],1);
    while(m--){
        int l,r,k;
        read(l,r,k);
        wrt(g[SegT.query(l,r,k)-1],'\n');
    }
    return 0;
}
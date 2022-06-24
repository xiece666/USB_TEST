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
int n,m,la;
class PersistentSegmentTree{
    private:
        bool flag;
        int P,D;
        int tot,root[N];
        struct __node{int val,ls,rs;}Tr[N<<5];
        int __new(int from=0){return Tr[++tot]=Tr[from],tot;}
        int __init(int l,int r){
            int new_rt=__new();
            if(l==r)return Tr[new_rt].val=(flag?1:l),new_rt;
            int mid=(l+r)>>1;
            Tr[new_rt].ls=__init(l,mid);
            Tr[new_rt].rs=__init(mid+1,r);
            return new_rt;
        }
        int __insert(int rt,int l,int r){
            int new_rt=__new(rt);
            if(l==r)return Tr[new_rt].val=D,new_rt;
            int mid=(l+r)>>1;
            if(P<=mid)Tr[new_rt].ls=__insert(Tr[rt].ls,l,mid);
            else Tr[new_rt].rs=__insert(Tr[rt].rs,mid+1,r);
            return new_rt;
        }
        int __query(int rt,int l,int r){
            if(l==r)return Tr[rt].val;
            int mid=(l+r)>>1;
            if(P<=mid)return __query(Tr[rt].ls,l,mid);
            return __query(Tr[rt].rs,mid+1,r);
        }
    public:
        void init(int f){flag=f,root[0]=__init(1,n);}
        void copy(int to,int fr){root[to]=root[fr];}
        void insert(int tim,int pos,int del){P=pos,D=del,root[tim]=__insert(root[tim],1,n);}
        int query(int tim,int pos){return P=pos,__query(root[tim],1,n);}
}fa,siz;
int find(int tim,int x){
    int pa=fa.query(tim,x);
    // printf("pa(%d,%d):%d\n",tim,x,pa);
    return pa==x?x:find(tim,pa);
}
int main(){
    read(n,m);
    fa.init(0),siz.init(1);
    for(int i=1;i<=m;i++){
        int tp,a,b;
        read(tp,a),a^=la;
        if(tp!=2)read(b),b^=la;
        if(tp==2)fa.copy(i,a),siz.copy(i,a);
        else fa.copy(i,i-1),siz.copy(i,i-1);
        if(tp==1){
            int fx=find(i,a),fy=find(i,b);
            // printf("i:%d find(%d):%d find(%d):%d\n",i,a,fx,b,fy);
            if(fx==fy)continue;
            int sx=siz.query(i,fx),sy=siz.query(i,fy);
            if(sx<sy)swap(fx,fy);
            fa.insert(i,fy,fx);
            siz.insert(i,fx,sx+sy);
            // printf("i:%d find(%d):%d find(%d):%d\n",i,a,find(i,a),b,find(i,b));
        }
        if(tp==3)wrt(la=(find(i,a)==find(i,b)?1:0),'\n');
    }
    return 0;
}
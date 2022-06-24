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
const ll N=5010;
int n,m,l[N],r[N],op[N],fa[N<<1];
vector<int>g;
inline int root(int x){return fa[x]==x?x:fa[x]=root(fa[x]);}
int main(){
    read(n,m);
    for(int i=1;i<=m;i++){
        read(l[i],r[i]),l[i]--;
        op[i]=(getchar()=='o');
        g.pbk(l[i]),g.pbk(r[i]);
    }
    sort(g.begin(),g.end());
    g.erase(unique(g.begin(),g.end()),g.end());
    n=g.size(),iota(fa,fa+n*2+1,0);
    for(int i=1;i<=m;i++){
        int x=lower_bound(g.begin(),g.end(),l[i])-g.begin()+1;
        int y=lower_bound(g.begin(),g.end(),r[i])-g.begin()+1;
        int fx1=root(x),fx2=root(x+n),fy1=root(y),fy2=root(y+n);
        // printf("l[%d]:%d->%d\tr[%d]:%d->%d\tfx1:%d\tfx2:%d\tfy1:%d\tfy2:%d\n",i,l[i],x,i,r[i],y,fx1,fx2,fy1,fy2);
        if(op[i]){
            if(fx1==fy1)return wrt(i-1),0;
            fa[fx1]=fy2,fa[fx2]=fy1;
        }else{
            if(fx1==fy2)return wrt(i-1),0;
            fa[fx1]=fy1,fa[fx2]=fy2;
        }
    }
    wrt(m);
    return  0;
}
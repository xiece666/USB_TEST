#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define fir first
#define sec second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=1010;
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
int n,root,ans;
struct lyl{
    int siz,fa,val;
}p[N];
int main(){
    read(n,root);
    for(int i=1;i<=n;i++)
        read(p[i].val),ans+=p[i].val,p[i].siz=1;
    for(int i=1,x,y;i<n;i++){
        read(x,y);
        p[y].fa=x;
    }
    for(int i=1;i<n;i++){
        int cur;
        db mx=0.0;
        for(int j=1;j<=n;j++)
            if(j!=root&&mx*p[j].siz<p[j].val*1.0)
                mx=p[j].val*1.0/p[j].siz,cur=j;
        int pa=p[cur].fa;
        ans+=p[cur].val*p[pa].siz;
        for(int j=1;j<=n;j++)
            if(p[j].fa==cur)p[j].fa=pa;
        p[pa].val+=p[cur].val;
        p[pa].siz+=p[cur].siz;
        p[cur].val=-1;
    }
    wrt(ans);
    return 0;
}
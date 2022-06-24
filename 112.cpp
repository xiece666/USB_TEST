#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define l first
#define r second
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
int n,d,ans;
db la=-1e4;
pair<db,db>p[N];
int main(){
    read(n,d);
    for(int i=1,x,y;i<=n;i++){
        read(x,y);
        if(y>d)return puts("-1"),0;
        p[i].l=x*1.0-sqrt(d*d*1.0-y*y*1.0);
        p[i].r=x*1.0+sqrt(d*d*1.0-y*y*1.0);
    }
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++){
        if(p[i].l>la)la=p[i].r,ans++;
        else la=min(la,p[i].r);
    }
    wrt(ans);
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define x first
#define y second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=1e4+10;
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
int n,ans,x[N],y[N];
int main(){
    read(n);
    for(int i=1;i<=n;i++)read(x[i]),read(y[i]);
    sort(y+1,y+1+n),sort(x+1,x+1+n);
    for(int i=1;i<=n;i++)ans+=abs(y[i]-y[(n>>1)+1]),x[i]-=i;
    sort(x+1,x+1+n);
    for(int i=1;i<=n;i++)ans+=abs(x[i]-x[(n>>1)+1]);
    wrt(ans);
    return  0;
}
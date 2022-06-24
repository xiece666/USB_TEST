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
const ll N=1e5+10;
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
ll n,m,t,ansr,ansc;
ll col[N],row[N],s[N];
int main(){
    read(n,m,t);
    for(ll i=1,x,y;i<=t;i++)
        read(x,y),row[x]++,col[y]++;
    if(t%n==0){
        ll k=t/n;
        for(ll i=1;i<=n;i++){
            row[i]-=k;
            s[i]=s[i-1]+row[i];
        }
        sort(s+1,s+1+n);
        for(ll i=1;i<=n;i++)ansr+=abs(s[i]-s[(n>>1)+1]);
    }
    if(t%m==0){
        ll k=t/m;
        for(ll i=1;i<=m;i++){
            col[i]-=k;
            s[i]=s[i-1]+col[i];
        }
        sort(s+1,s+1+m);
        for(ll i=1;i<=m;i++)ansc+=abs(s[i]-s[(m>>1)+1]);
    }
    if(t%n&&t%m)puts("impossible");
    if(!(t%n)&&!(t%m))printf("column %lld",ansc);
    if(!(t%n)&&t%m)printf("row %lld",ansr);
    if(t%n&&!(t%m))printf("both %lld",ansc+ansr);
    return  0;
}
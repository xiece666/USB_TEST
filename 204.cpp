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
const ll N=30;
ll n,x,y,a,m,A,M;
inline ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b)return x=y=1,a;
    int res=exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return res;
}
int main(){
    read(n,A,M);
    for(int i=1;i<n;i++){
        read(a,m);
        ll res=exgcd(A,a,x,y);
        if((m-M)%res)return puts("-1"),0;
        x=x*(m-M)/res;
        x=((x%(a/res))+(a/res))%(a/res);
        M=M+x*A;
        A=A*a/res;
    }
    wrt(M);
    return  0;
}
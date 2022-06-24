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
const ll N=15;
ll n,anst,ans=INT_MAX,c[N];
ll prime[]={0,2,3,5,7,11,13,17,19,23,29};
void dfs(ll pos,ll p,ll sumc,ll cntc){
    if(pos==11){
        if(cntc>anst)anst=cntc,ans=p;
        if(cntc==anst&&p<ans)ans=p;
        return;
    }
    for(ll i=0,del=1;i<=min(c[pos-1],30-sumc);del*=prime[pos],i++){
        if(p*del>n)break;
        c[pos]=i;
        dfs(pos+1,p*del,sumc+i,cntc*(i+1));
    }
}
int main(){
    read(n),c[0]=INT_MAX;
    dfs(1,1,0,1);
    wrt(ans);
    return  0;
}
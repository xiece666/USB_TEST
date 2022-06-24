#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
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
template <typename T1,typename T2> void wrt(T1 x1,char c1,T2 x2,char c2){wrt(x1,c1),wrt(x2,c2);}
int n,m,ans=INT_MAX,miv[N],mis[N],h[N],r[N];
void dfs(int dep,int s,int v){
    if(v+miv[dep]>n)return;
    if(s+2*(n-v)/r[dep+1]>=ans)return;
    if(s+mis[dep]>=ans)return;
    if(!dep){
        if(v==n)ans=s;
        return;
    }
    for(int nr=min(int(sqrt(n-v)),r[dep+1]-1);nr>=dep;nr--)
        for(int nh=min((n-v)/(nr*nr),h[dep+1]-1);nh>=dep;nh--){
            h[dep]=nh,r[dep]=nr;
            int del=(dep==m?nr*nr:0);
            dfs(dep-1,s+nr*2*nh+del,v+nr*nr*nh);
        }
}
int main(){
    read(n,m);
    for(int i=1;i<=m;i++){
        miv[i]=miv[i-1]+i*i*i;
        mis[i]=mis[i-1]+i*i*2;
    }
    r[m+1]=h[m+1]=INT_MAX;
    dfs(m,0,0);
    wrt(ans==INT_MAX?0:ans);
    return 0;
}
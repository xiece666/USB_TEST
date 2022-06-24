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
const ll N=3e4+10;
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
int n,m,in[N];
bitset<N>dp[N];
vector<int>g[N];
queue<int>q;
void top_sort(){
    for(int i=1;i<=n;i++)if(!in[i])q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        dp[u][u]=1;
        for(int v:g[u]){
            dp[v]|=dp[u];
            if(!(--in[v]))q.push(v);
        }
    }
}
int main(){
    read(n,m);
    for(int i=1,x,y;i<=m;i++){
        read(x,y);
        in[x]++;
        g[y].pbk(x);
    }
    top_sort();
    for(int i=1;i<=n;i++)wrt(dp[i].count(),'\n');
    return  0;
}
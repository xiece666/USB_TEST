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
template <typename T1,typename T2> void wrt(T1 x1,char c1,T2 x2,char c2){wrt(x1,c1),wrt(x2,c2);}
int n,m,k,U,V,dis[N],cnt[N];
bitset<N>vis;
vector<pair<int,int>>g[N],_g[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void dijkstra(){
    mem(dis,0x3f),dis[V]=0;
    q.push({0,V});
    while(!q.empty()){
        int u=q.top().sec;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto i:_g[u]){
            int v=i.fir,vl=i.sec;
            if(dis[u]+vl<dis[v]){
                dis[v]=dis[u]+vl;
                q.push({dis[v],v});
            }
        }
    }
}
int h(int x){return dis[x];}
int A_star(){
    if(U==V)k++;
    q.push({h(U),U});
    while(!q.empty()){
        int u=q.top().sec;
        int d=q.top().fir-h(u);
        q.pop();
        cnt[u]++;
        if(cnt[V]==k)return d;
        for(auto i:g[u]){
            int v=i.fir,vl=i.sec;
            if(cnt[v]<k)q.push({d+vl+h(v),v});
        }
    }
    return -1;
}
int main(){
    read(n,m);
    for(int i=1,x,y,z;i<=m;i++){
        read(x,y,z);
        g[x].pbk({y,z});
        _g[y].pbk({x,z});
    }
    read(U,V,k);
    dijkstra();
    wrt(A_star());
    return  0;
}
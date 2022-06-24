#include<bits/stdc++.h>
#include<bits/extc++.h>
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
const ll N=510;
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
int n,m,T,tot,mp[N][N],dis[N*N];
char s[N][N];
vector<pair<int,int>>g[N*N];
__gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int>>>q;
__gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int>>>::point_iterator it[N*N];
void dijkstra(){
    q.clear();
    it[1]=q.push({0,1});
    for(int i=2;i<=tot;i++)dis[i]=INT_MAX>>1,it[i]=q.push({dis[i],i});
    static int u;
    while(!q.empty()){
        u=q.top().sec;q.pop();
        if(u==tot)return;
        for(auto i:g[u]){
            int v=i.fir,vl=i.sec;
            if(dis[u]+vl<dis[v]){
                dis[v]=dis[u]+vl;
                q.modify(it[v],{dis[v],v});
            }
        }
    }
}
int main(){
    read(T);
    while(T--){
        read(n,m);
        for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
        tot=0;
        for(int i=1;i<=n+1;i++)for(int j=1;j<=m+1;j++)
            mp[i][j]=++tot,g[tot].clear();
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            int x=mp[i][j],y=mp[i+1][j+1];
            int z=(s[i][j]=='/');
            g[x].pbk({y,z}),g[y].pbk({x,z});
            g[x+1].pbk({y-1,z^1}),g[y-1].pbk({x+1,z^1});
            // printf("x:%d y:%d z:%d\n",x,y,z);
        }
        dijkstra();
        if(dis[tot]>1e8)puts("NO SOLUTION");
        else wrt(dis[tot],'\n');
    }
    return  0;
}
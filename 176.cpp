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
int Q,n,m,C,U,V,p[N],dis[N][110];
vector<pair<int,int>>g[N];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q,emp;
//{cost,{city,fuel}}
int dijkstra(){
    q=emp;
    mem(dis,0x3f);
    dis[U][0]=0;
    q.push({0,{U,0}});
    while(!q.empty()){
        auto u=q.top().sec;q.pop();
        if(u.fir==V)return dis[u.fir][u.sec];
        if(u.sec<C&&dis[u.fir][u.sec+1]>dis[u.fir][u.sec]+p[u.fir]){
            dis[u.fir][u.sec+1]=dis[u.fir][u.sec]+p[u.fir];
            q.push({dis[u.fir][u.sec+1],{u.fir,u.sec+1}});
        }
        for(auto i:g[u.fir]){
            int v=i.fir,vl=i.sec;
            if(u.sec<vl)continue;
            if(dis[u.fir][u.sec]<dis[v][u.sec-vl]){
                dis[v][u.sec-vl]=dis[u.fir][u.sec];
                q.push({dis[v][u.sec-vl],{v,u.sec-vl}});
            }
        }
    }
    return -1;
}
int main(){
    read(n,m);
    for(int i=1;i<=n;i++)read(p[i]);
    for(int i=1,x,y,z;i<=m;i++){
        read(x,y,z);
        x++,y++;
        g[x].pbk({y,z});
        g[y].pbk({x,z});
    }
    read(Q);
    while(Q--){
        read(C,U,V);
        U++,V++;
        int res=dijkstra();
        if(res==-1)puts("impossible");
        else wrt(res,'\n');
    }
    return  0;
}
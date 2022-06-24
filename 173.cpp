#include<bits/stdc++.h>
#pragma GCC optimize(2)
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
int n,m,dis[N][N];
bitset<N>p[N];
queue<pair<int,int>>q;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void bfs(){
    mem(dis,-1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        if(p[i][j])q.push({i,j}),dis[i][j]=0;
    while(!q.empty()){
        int x=q.front().fir,y=q.front().sec;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>n||ny>m||nx<1||ny<1)continue;
            if(dis[nx][ny]!=-1)continue;
            dis[nx][ny]=dis[x][y]+1;
            q.push({nx,ny});
        }
    }
}
int main(){
    read(n,m);
    for(int i=1,x;i<=n;i++)for(int j=1;j<=m;j++)
        scanf("%1d",&x),p[i][j]=x;
    bfs();
    for(int i=1;i<=n;puts(""),i++)for(int j=1;j<=m;j++)wrt(dis[i][j],' ');
    return 0;
}
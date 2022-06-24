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
using namespace std;
const ll N=380,V=5,D=8;
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
int n;
int dx[]={-1,1,0,0,-2,2,0,0,0};
int dy[]={0,0,-1,1,0,0,-2,2,0};
bool vis[N][V][V][D][D][D][D];
bool sch[N][V][V];
struct lyl{
    int day,x,y,a,b,c,d;
};
queue<lyl>q,emp;
bool ck(int d,int x,int y){
    return sch[d][x][y]|sch[d][x+1][y]|sch[d][x][y+1]|sch[d][x+1][y+1];
}
int bfs(){
    if(ck(1,1,1))return 0;
    q=emp;
    mem(vis,0);
    q.push((lyl){1,1,1,1,1,1,1});
    vis[1][1][1][1][1][1][1]=1;
    while(!q.empty()){
        lyl u=q.front();q.pop();
        if(u.day==n)return 1;
        for(int i=0;i<9;i++){
            lyl v=u;
            v.x+=dx[i],v.y+=dy[i];
            v.day++;
            if(v.x<0||v.x>2||v.y<0||v.y>2)continue;
            if(ck(v.day,v.x,v.y))continue;
            v.a=(v.x==0&&v.y==0?0:v.a+1);
            v.b=(v.x==0&&v.y==2?0:v.b+1);
            v.c=(v.x==2&&v.y==0?0:v.c+1);
            v.d=(v.x==2&&v.y==2?0:v.d+1);
            if(v.a==7||v.b==7||v.c==7||v.d==7)continue;
            if(vis[v.day][v.x][v.y][v.a][v.b][v.c][v.d])continue;
            vis[v.day][v.x][v.y][v.a][v.b][v.c][v.d]=1;
            q.push(v);
        }
    }
    return 0;
}
int main(){
    while(read(n),n){
        for(int i=1,x;i<=n;i++)
            for(int j=0;j<16;j++)
                read(x),sch[i][j/4][j%4]=x;
        wrt(bfs(),'\n');
    }
    return  0;
}
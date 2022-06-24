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
const ll N=110;
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
int n,m,sx,sy,ans;
int dis[N][N];
char mp[N][N];
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={-1,-1,0,1,1,1,0,-1};
queue<pair<int,int>>q;
int main(){
    read(m,n,sy,sx);
    for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
    mem(dis,-1);
    dis[sx][sy]=0;
    q.push({sx,sy});
    while(!q.empty()){
        int ux=q.front().fir,uy=q.front().sec;
        q.pop();
        ans=max(ans,dis[ux][uy]);
        for(int i=0;i<8;i++){
            int vx=ux+dx[i],vy=uy+dy[i];
            if(vx<1||vx>n||vy<1||vy>m)continue;
            if(mp[vx][vy]=='*')continue;
            if(dis[vx][vy]!=-1)continue;
            dis[vx][vy]=dis[ux][uy]+1;
            q.push({vx,vy});
        }
    }
    wrt(ans);
    return  0;
}
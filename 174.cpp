#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
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
const ll N=25;
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
int T;
int n,m,anss,ansb;
char mp[N][N];
int disb[N][N][4],diss[N][N][4];
int ansd;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dxx[]={-1,1,0,0};
int dyy[]={0,0,-1,1};
int sbx,sby,ssx,ssy,ebx,eby;//start,end position
struct LYL{int x,y,dir;};
struct lyl{int x,y,dis;};
string ans[N][N][4],pre[N][N];
char hs[2][4]={
    {'n','s','w','e'},
    {'N','S','W','E'}
};
bitset<N>vis[N];//for man's walking
queue<LYL>Q,emp1;//box
queue<lyl>q,emp2;//man
void find_se(){
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(mp[i][j]=='B')sbx=i,sby=j,mp[i][j]='.';
        if(mp[i][j]=='S')ssx=i,ssy=j,mp[i][j]='.';
        if(mp[i][j]=='T')ebx=i,eby=j,mp[i][j]='.';
    }
}
int walk(int sx,int sy,int ex,int ey,int _x,int _y){//start(x,y) end(x,y) box(x,y)
    q=emp2;
    for(int i=1;i<=n;i++)vis[i]=0;
    q.push((lyl){sx,sy,0});
    pre[sx][sy].clear();
    vis[sx][sy]=1;
    while(!q.empty()){
        lyl u=q.front();q.pop();
        if(u.x==ex&&u.y==ey)return u.dis;
        for(int i=0;i<4;i++){
            int vx=u.x+dxx[i],vy=u.y+dyy[i];
            if(vx<1||vx>n||vy<1||vy>m)continue;
            if(mp[vx][vy]=='#')continue;
            if(vx==_x&&vy==_y)continue;
            if(vis[vx][vy])continue;
            vis[vx][vy]=1;
            pre[vx][vy]=pre[u.x][u.y]+hs[0][i];
            q.push((lyl){vx,vy,u.dis+1});
        }
    }
    return -1;
}
//s    n   e    w
//down up right left
//0  1    2    3
bool bfs(){
    Q=emp1;
    mem(disb,-1),mem(diss,-1);
    for(int i=0;i<4;i++){
        int _x=sbx+dx[i],_y=sby+dy[i];
        if(_x<1||_x>n||_y<1||_y>m)continue;
        if(mp[_x][_y]=='#')continue;
        int d=walk(ssx,ssy,_x,_y,sbx,sby);
        if(d==-1)continue;
        diss[sbx][sby][i]=d;
        disb[sbx][sby][i]=0;
        ans[sbx][sby][i]=pre[_x][_y];
        Q.push((LYL){sbx,sby,i});
    }
    ansb=anss=INT_MAX,ansd=-1;
    while(!Q.empty()){
        int ux=Q.front().x,uy=Q.front().y;
        int ud=Q.front().dir;Q.pop();
        if(ux==ebx&&uy==eby){
            if(disb[ux][uy][ud]<ansb){
                ansd=ud;
                ansb=disb[ux][uy][ud];
                anss=diss[ux][uy][ud];
            }else if(disb[ux][uy][ud]==ansb)
                if(diss[ux][uy][ud]<anss){
                    ansd=ud;
                    anss=diss[ux][uy][ud];
                }
        }
        for(int i=0;i<4;i++){
            int vx=ux-dx[i],vy=uy-dy[i];
            if(vx<1||vx>n||vy<1||vy>m)continue;
            if(mp[vx][vy]=='#')continue;
            if(disb[vx][vy][i]!=-1&&disb[vx][vy][i]<disb[ux][uy][ud]+1)continue;
            int d=walk(ux+dx[ud],uy+dy[ud],ux+dx[i],uy+dy[i],ux,uy);
            if(d==-1)continue;
            if(diss[vx][vy][i]!=-1&&diss[vx][vy][i]<=diss[ux][uy][ud]+d)continue;
            diss[vx][vy][i]=diss[ux][uy][ud]+d;
            disb[vx][vy][i]=disb[ux][uy][ud]+1;
            ans[vx][vy][i]=ans[ux][uy][ud]+pre[ux+dx[i]][uy+dy[i]]+hs[1][i];
            Q.push((LYL){vx,vy,i});
        }
    }
    return ansd!=-1;
}
int main(){
    while(read(n,m),n&&m){
        printf("Maze #%d\n",++T);
        for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
        find_se();
        if(!bfs())puts("Impossible.");
        else puts(ans[ebx][eby][ansd].c_str());
        puts("");
    }
    return  0;
}

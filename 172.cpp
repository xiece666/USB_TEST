#include<bits/stdc++.h>
#pragma GCC optimize(2)
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
int n,m,ans;
char mp[N][N];
int dis[N][N][3];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int Dx[3][4]={
    {0,0,-2,1},
    {0,0,-1,1},
    {0,0,-1,2}
};
int Dy[3][4]={
    {-2,1,0,0},
    {-1,2,0,0},
    {-1,1,0,0}
};
int Ds[3][4]={
    {1,1,2,2},
    {0,0,1,1},
    {2,2,0,0}
};
struct lyl{
    int x,y,sta;
    bool operator==(const lyl a)const{
        return x==a.x&&y==a.y&&sta==a.sta;
    }
}S,E;
//sta=0->stand sta=1->row-lie,left at(x,y) sta=2->col-lie,up at(x,y)
queue<lyl>q,emp;
void find_SE(){
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(mp[i][j]=='O')E=(lyl){i,j,0},mp[i][j]='.';
        if(mp[i][j]=='X'){
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(mp[x][y]=='X'){
                    mp[i][j]=mp[x][y]='.';
                    S=(lyl){min(i,x),min(j,y),1+(k>=2)};
                    break;
                }
            }
            if(mp[i][j]=='X')S=(lyl){i,j,0},mp[i][j]='.';
        }
    }
}
bool ck(lyl cur){
    int _x=cur.x,_y=cur.y,s=cur.sta;
    if(_x>n||_x<1||_y>m||_y<1)return 0;
    if(mp[_x][_y]=='#')return 0;
    if(!s&&mp[_x][_y]!='.')return 0;
    if(s==1&&mp[_x][_y+1]=='#')return 0;
    if(s==2&&mp[_x+1][_y]=='#')return 0;
    if(dis[_x][_y][s]!=-1)return 0;
    return 1;
}
int bfs(){
    mem(dis,-1);
    q=emp;
    q.push(S),dis[S.x][S.y][S.sta]=0;
    while(!q.empty()){
        lyl cur=q.front();q.pop();
        if(cur==E)return dis[cur.x][cur.y][cur.sta];
        for(int i=0;i<4;i++){
            lyl nxt;
            nxt.x=cur.x+Dx[cur.sta][i];
            nxt.y=cur.y+Dy[cur.sta][i];
            nxt.sta=Ds[cur.sta][i];
            if(!ck(nxt))continue;
            dis[nxt.x][nxt.y][nxt.sta]=dis[cur.x][cur.y][cur.sta]+1;
            q.push(nxt);
        }
    }
    return -1;
}
int main(){
    while(read(n,m),n&&m){
        for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
        find_SE();
        ans=bfs();
        if(ans==-1)puts("Impossible");
        else wrt(ans,'\n');
    }
    return  0;
}
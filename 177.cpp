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
const ll N=810;
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
int n,m,T,gx,gy,bx,by,zx[3],zy[3],zt;
char mp[N][N];
int disb[N][N],disg[N][N];
queue<pair<int,int>>qg,qb,emp;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool ck(int x,int y,int k){
    // printf("ck(%d,%d,%d)\n",x,y,k);
    for(int i=1;i<=2;i++)
        if(abs(zx[i]-x)+abs(zy[i]-y)<=(k<<1))return 0;
    return 1;
}
void expandb(int k){
    while(!qb.empty()){
        int x=qb.front().fir,y=qb.front().sec;
        if(disb[x][y]>=(k*3))return;
        qb.pop();
        if(!ck(x,y,k))continue;
        // printf("b:\nfrom(%d,%d)\n",x,y);
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            // printf("    try(%d,%d)\n",nx,ny);
            if(nx<1||nx>n||ny<1||ny>m)continue;
            // puts("    1");
            if(mp[nx][ny]=='X')continue;
            // puts("    2");
            if(disb[nx][ny]!=-1)continue;
            // puts("    3");
            if(!ck(nx,ny,k))continue;
            // puts("    4");
            disb[nx][ny]=disb[x][y]+1;
            // printf("    ->(%d,%d)\n",nx,ny);
            qb.push({nx,ny});
        }
    }
}
void expandg(int k){
    while(!qg.empty()){
        int x=qg.front().fir,y=qg.front().sec;
        if(disg[x][y]>=k)return;
        qg.pop();
        if(!ck(x,y,k))continue;
        // printf("g:\nfrom(%d,%d)\n",x,y);
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m)continue;
            if(mp[nx][ny]=='X')continue;
            if(disg[nx][ny]!=-1)continue;
            if(!ck(nx,ny,k))continue;
            disg[nx][ny]=disg[x][y]+1;
            // printf("    ->(%d,%d)\n",nx,ny);
            qg.push({nx,ny});
        }
    }
}
int bfs(){
    if(bx==gx&&by==gy)return 0;
    if(!ck(bx,by,0)||!ck(gx,gy,0))return -1;
    qb=qg=emp;
    mem(disg,-1),mem(disb,-1);
    qb.push({bx,by}),qg.push({gx,gy});
    disb[bx][by]=disg[gx][gy]=0;
    for(int i=1;i<=n+m;i++){
        expandb(i);
        expandg(i);
        for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)
            if(disb[j][k]!=-1&&disg[j][k]!=-1)return i;
        if(i>300)return -1;
    }
    return -1;
}
int main(){
    read(T);
    while(T--){
        read(n,m);
        for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
        zt=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            if(mp[i][j]=='M')bx=i,by=j,mp[i][j]='.';
            if(mp[i][j]=='G')gx=i,gy=j,mp[i][j]='.';
            if(mp[i][j]=='Z')zx[++zt]=i,zy[zt]=j;
        }
        wrt(bfs(),'\n');
    }
    return  0;
}
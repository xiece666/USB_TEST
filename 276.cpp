#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long double
#define ebk emplace_back
#define mkp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
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
template <typename T1,typename T2> void wrt(T1 x,char c1,T2 y,char c2){wrt(x,c1),wrt(y,c2);}
const ll N=16;
int n,m,k,ans=INT_MIN;
int a[N][N];
int dp[N][N*N][N][N][2][2];
struct lyl{int a,b,c,d,e,f;}
pre[N][N*N][N][N][2][2],ed;
// 0:go left 1:go right
void print(lyl s){
    if(!s.a)return;
    print(pre[s.a][s.b][s.c][s.d][s.e][s.f]);
    for(int i=s.c;i<=s.d;i++)if(i)wrt(s.a,' ',i,'\n');
}
signed main(){
    read(n,m,k);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        read(a[i][j]),a[i][j]+=a[i][j-1];
    for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)
        for(int l=1;l<=m;l++)for(int r=l;r<=m;r++){
            int len=r-l+1;
            if(len>j)continue;
            // 0 1
            if(j==r-l+1){
                dp[i][j][l][r][0][1]=dp[i-1][0][0][0][0][1];
                pre[i][j][l][r][0][1]=(lyl){i-1,0,0,0,0,1};
            }else for(int p=l;p<=r;p++)for(int q=p;q<=r;q++)
                if(dp[i][j][l][r][0][1]<dp[i-1][j-len][p][q][0][1]){
                    dp[i][j][l][r][0][1]=dp[i-1][j-len][p][q][0][1];
                    pre[i][j][l][r][0][1]=(lyl){i-1,j-len,p,q,0,1};
                }
            // 0 0
            for(int p=l;p<=r;p++)for(int q=r;q<=m;q++)for(int y=0;y<2;y++)
                if(dp[i][j][l][r][0][0]<dp[i-1][j-len][p][q][0][y]){
                    dp[i][j][l][r][0][0]=dp[i-1][j-len][p][q][0][y];
                    pre[i][j][l][r][0][0]=(lyl){i-1,j-len,p,q,0,y};
                }
            // 1 1
            for(int p=1;p<=l;p++)for(int q=l;q<=r;q++)for(int x=0;x<2;x++)
                if(dp[i][j][l][r][1][1]<dp[i-1][j-len][p][q][x][1]){
                    dp[i][j][l][r][1][1]=dp[i-1][j-len][p][q][x][1];
                    pre[i][j][l][r][1][1]=(lyl){i-1,j-len,p,q,x,1};
                }
            // 1 0
            for(int p=1;p<=l;p++)for(int q=r;q<=m;q++)for(int x=0;x<2;x++)for(int y=0;y<2;y++)
                if(dp[i][j][l][r][1][0]<dp[i-1][j-len][p][q][x][y]){
                    dp[i][j][l][r][1][0]=dp[i-1][j-len][p][q][x][y];
                    pre[i][j][l][r][1][0]=(lyl){i-1,j-len,p,q,x,y};
                }
            for(int x=0;x<2;x++)for(int y=0;y<2;y++)
                dp[i][j][l][r][x][y]+=a[i][r]-a[i][l-1];
        }
    for(int i=1;i<=n;i++)for(int l=1;l<=m;l++)for(int r=l;r<=m;r++)
        for(int x=0;x<2;x++)for(int y=0;y<2;y++)if(ans<dp[i][k][l][r][x][y])
            ans=dp[i][k][l][r][x][y],ed=(lyl){i,k,l,r,x,y};
    printf("Oil : %d\n",ans);
    print(ed);
    return 0;
}
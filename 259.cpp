#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define mkp make_pair
#define ebk emplace_back
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
template <typename T1,typename T2> void wrt(T1 x1,char c1,T2 x2,char c2){wrt(x1,c1),wrt(x2,c2);}
bool st;
const ll N=610;
int m,n,p1,p2;
int cnt,siz[2][N];
int dp[N][N],thr[N][N];
bitset<N>vis;
vector<int>ans;
vector<pii>g[N],s[N];
bool ed;
void dfs(int u,int fl){
    s[cnt].ebk(u,fl),siz[fl][cnt]++;
    vis[u]=1;
    for(auto [v,val]:g[u])if(!vis[v])
        dfs(v,fl^val);
}
int main(){
    // printf("%.10lf\n",(&st-&ed)*1.0/1024/1024);
    while(read(m,p1,p2),n=p1+p2,m||p1||p2){
        vis=0,cnt=0,ans.clear();
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)for(int j=0;j<=p1;j++)dp[i][j]=0;
        for(int i=1;i<=n;i++)s[i].clear(),siz[0][i]=siz[1][i]=0;
        for(int i=1,x,y;i<=m;i++){
            read(x,y);
            if(getchar()=='y')g[x].ebk(y,0),g[y].ebk(x,0);
            else g[x].ebk(y,1),g[y].ebk(x,1);
        }
        for(int i=1;i<=n;i++)if(!vis[i])cnt++,dfs(i,0);
        // for(int i=1;i<=cnt;i++){
        //     printf("scp %d:\n",i);
        //     for(auto [x,y]:s[i])wrt(x,' ',y,'\n');
        // }
        dp[0][0]=1;
        for(int i=1;i<=cnt;i++)for(int j=min(siz[0][i],siz[1][i]);j<=p1;j++){
            if(j>=siz[0][i]&&dp[i-1][j-siz[0][i]])dp[i][j]+=dp[i-1][j-siz[0][i]],thr[i][j]=0;
            if(j>=siz[1][i]&&dp[i-1][j-siz[1][i]])dp[i][j]+=dp[i-1][j-siz[1][i]],thr[i][j]=1;
        }
        if(dp[cnt][p1]!=1)puts("no");
        else{
            for(int i=cnt,j=p1;i;i--){
                int f=thr[i][j];
                for(auto [u,fl]:s[i])if(fl==f)
                    ans.ebk(u);
                j-=siz[f][i];
            }
            sort(ans.begin(),ans.end());
            for(int i:ans)wrt(i,'\n');
            puts("end");
        }
    }
    return 0;
}
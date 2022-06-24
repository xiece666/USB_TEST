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
bool st;
const ll N=210,M=25,S=800,base=400;
int task;
int n,m,p[N],d[N],best;
int ansp,ansd;
int dp[N][M][S+10];
struct lyl{int a,b,c;}pre[N][M][S+10];
stack<int>ans;
bool ed;
signed main(){
    // printf("%.10lf\n",(&st-&ed)*1.0/1024/1024);
    while(read(n,m),n||m){
        ansp=ansd=best=0;
        mem(dp,0xcf),dp[0][0][base]=0;
        for(int i=1;i<=n;i++)read(p[i],d[i]);
        for(int i=1;i<=n;i++)for(int j=0;j<=m;j++)for(int k=0;k<=S;k++){
            dp[i][j][k]=dp[i-1][j][k],pre[i][j][k]=(lyl){i-1,j,k};
            int t=k-(p[i]-d[i]);
            if(j-1<0||t<0||t>S)continue;
            int fr=dp[i-1][j-1][t]+(p[i]+d[i]);
            if(dp[i][j][k]<fr)dp[i][j][k]=fr,pre[i][j][k]=(lyl){i-1,j-1,t};
        }
        while(dp[n][m][base-best]<0&&dp[n][m][base+best]<0)best++;
        if(dp[n][m][base-best]>=dp[n][m][base+best])best=base-best;
        else best=base+best;
        for(int i=n,j=m;i>=1;i--){
            int nxt=pre[i][j][best].b;
            if(nxt==j-1){
                ansp+=p[i],ansd+=d[i];
                ans.emplace(i);
            }
            best=pre[i][j][best].c,j=nxt;
        }
        printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n ",++task,ansp,ansd);
        for(;!ans.empty();ans.pop())wrt(ans.top(),' ');
        puts("\n");
    }
    return 0;
}
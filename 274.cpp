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
const ll N=1010,L=210;
int n,m,c[L][L],p[N],dp[N][L][L],ans=INT_MAX;
int main(){
    read(m,n);
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)
        read(c[i][j]);
    for(int i=1;i<=n;i++)read(p[i]);
    p[0]=3;
    mem(dp,0x3f),dp[0][1][2]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++)for(int k=1;k<=m;k++){
            if(p[i]==j||j==k||k==p[i])continue;
            int cur=dp[i][j][k];
            if(p[i+1]!=j&&p[i+1]!=k)dp[i+1][j][k]=min(dp[i+1][j][k],cur+c[p[i]][p[i+1]]);
            if(p[i+1]!=p[i]&&p[i+1]!=k)dp[i+1][p[i]][k]=min(dp[i+1][p[i]][k],cur+c[j][p[i+1]]);
            if(p[i+1]!=p[i]&&p[i+1]!=j)dp[i+1][j][p[i]]=min(dp[i+1][j][p[i]],cur+c[k][p[i+1]]);
        }
    }
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)ans=min(ans,dp[n][i][j]);
    wrt(ans);
    return 0;
}
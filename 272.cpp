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
const ll N=3010;
int n,a[N],b[N],ans;
int dp[N][N];
int main(){
    read(n),a[0]=b[0]=-1;
    for(int i=1;i<=n;i++)read(a[i]);
    for(int i=1;i<=n;i++)read(b[i]);
    for(int i=1;i<=n;i++){
        int mx=dp[i-1][0];
        for(int j=1;j<=n;j++){
            if(a[i]!=b[j])dp[i][j]=dp[i-1][j];
            else dp[i][j]=mx+1;
            ans=max(ans,dp[i][j]);
            if(b[j]<a[i])mx=max(mx,dp[i-1][j]);
        }
    }
    wrt(ans);
    return 0;
}
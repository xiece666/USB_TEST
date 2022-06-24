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
const ll N=110;
int n,a[N],ans;
vector<int>anse;
int dp[2][N][N];
//0:mx 1:mn
bitset<N>op;
//0:+ 1:*
int calc(int x,bool fl,int y){return fl?x*y:x+y;}
signed main(){
    read(n);
    for(int i=1;i<=n;i++){
        char ch=getchar();
        read(a[i]),op[i]=(ch=='x');
    }
    bool tmp=op[1];
    for(int i=1;i<n;i++)op[i]=op[i+1];op[n]=tmp;
    for(int i=1;i<=n;i++)a[i+n]=a[i],op[i+n]=op[i];
    mem(dp[0],0xcf),mem(dp[1],0x3f);
    for(int i=1;i<=n<<1;i++)
        dp[0][i][i]=dp[1][i][i]=a[i];
    for(int len=2;len<=n;len++)for(int l=1,r=len;r<=n*2;l++,r++)
        for(int k=l;k<r;k++){
            dp[0][l][r]=max(dp[0][l][r],calc(dp[0][l][k],op[k],dp[0][k+1][r]));
            if(op[k])for(int i=0;i<2;i++)for(int j=0;j<2;j++)
                dp[0][l][r]=max(dp[0][l][r],calc(dp[i][l][k],1,dp[j][k+1][r]));
            dp[1][l][r]=min(dp[1][l][r],calc(dp[1][l][k],op[k],dp[1][k+1][r]));
            if(op[k])for(int i=0;i<2;i++)for(int j=0;j<2;j++)
                dp[1][l][r]=min(dp[1][l][r],calc(dp[i][l][k],1,dp[j][k+1][r]));
        }
    for(int i=1;i<=n;i++)ans=max(ans,dp[0][i][i+n-1]);
    for(int i=1;i<=n;i++)if(dp[0][i][i+n-1]==ans)anse.ebk(i);
    wrt(ans,'\n');
    for(int i:anse)wrt(i,' ');
    return 0;
}
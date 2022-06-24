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
const ll N=1e5+10;
int n,m,a[N],c[N],cnt[N],ans;
bool dp[N];
signed main(){
    while(read(n,m),n||m){
        mem(dp,0);
        ans=0,dp[0]=1;
        for(int i=1;i<=n;i++)read(a[i]);
        for(int i=1;i<=n;i++)read(c[i]);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++)cnt[j]=0;
            for(int j=a[i];j<=m;j++)
                if(!dp[j]&&dp[j-a[i]]&&cnt[j-a[i]]<c[i])
                    dp[j]=1,cnt[j]=cnt[j-a[i]]+1;
        }
        for(int i=1;i<=m;i++)ans+=dp[i];
        wrt(ans,'\n');
    }
    return 0;
}
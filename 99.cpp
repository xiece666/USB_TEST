#include<bits/stdc++.h>
#define ll long long
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
const ll N=5010;
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
int f[N][N],n,m,r,c,ans;
int main()
{
    read(n,m);
    m=min(m,5001),r=c=m;
    for(int i=1,x,y,z;i<=n;i++){
        read(x,y,z);
        f[++x][++y]+=z;
        r=max(r,x),c=max(c,y);
    }
    for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)
        f[i][j]+=(f[i-1][j]+f[i][j-1]-f[i-1][j-1]);
    for(int i=m;i<=r;i++)for(int j=m;j<=c;j++)
        ans=max(ans,f[i][j]-f[i][j-m]-f[i-m][j]+f[i-m][j-m]);
    wrt(ans);
    return 0;
}
#include<bits/stdc++.h>
#include<bits/extc++.h>
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
const ll N=1010,P1=131,P2=13331;
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
int n,m,a,b,Q;
ull hs[N][N],H[N][N],pw1[N],pw2[N];
__gnu_pbds::cc_hash_table<ull,bool>fl;
int main(){
    read(n,m,a,b);
    pw1[0]=pw2[0]=1;
    for(int i=1;i<=b;i++)pw1[i]=pw1[i-1]*P1;
    for(int i=1;i<=a;i++)pw2[i]=pw2[i-1]*P2;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        scanf("%1llu",&hs[i][j]),hs[i][j]+=hs[i][j-1]*P1+1;
    for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)
        hs[i][j]+=hs[i-1][j]*P2+1;
    for(int i=a;i<=n;i++)for(int j=b;j<=m;j++){
        ull now=hs[i][j]-hs[i-a][j]*pw2[a]-hs[i][j-b]*pw1[b]+hs[i-a][j-b]*pw1[b]*pw2[a];
        fl[now]=1;
    }
    read(Q);
    while(Q--){
        for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)
            scanf("%1llu",&H[i][j]),H[i][j]+=H[i-1][j]*P1+1;
        for(int j=1;j<=b;j++)for(int i=1;i<=a;i++)
            H[i][j]+=H[i][j-1]*P2+1;
        puts(fl[H[a][b]]?"1":"0");
    }
    return  0;
}
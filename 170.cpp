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
const ll N=1010;
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
int n,ans;
int p[N];
bitset<N>vis;
bool dfs(int pos){
    if(p[pos-1]==n)return 1;
    if(pos>ans)return 0;
    vis=0;
    for(int i=pos-1;i;i--)for(int j=i;j;j--){
        if(vis[p[i]+p[j]])continue;
        if(p[i]+p[j]>n)continue;
        if(p[i]+p[j]<=p[pos-1])continue;
        vis[p[i]+p[j]]=1;
        p[pos]=p[i]+p[j];
        if(dfs(pos+1))return 1;
    }
    return 0;
}
int main(){
    p[1]=1,p[2]=2;
    while(read(n),n){
        if(n<=2){
            for(int i=1;i<=n;i++)wrt(p[i],' ');
            puts("");
            continue;
        }
        for(ans=1;ans<=10;ans++)
            if(dfs(3))break;
        for(int i=1;i<=ans;i++)wrt(p[i],' ');
        puts("");
    }
    return  0;
}
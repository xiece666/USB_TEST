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
const ll N=2510;
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
template <typename T> void wrt(T x,char c1,T y,char c2){wrt(x,c1),wrt(y,c2);}
int n,m,ans,spf[N],num[N];
pair<int,int>p[N];
int main(){
    read(n,m);
    for(int i=1;i<=n;i++)read(p[i].fir,p[i].sec);
    for(int i=1;i<=m;i++)read(spf[i],num[i]);
    sort(p+1,p+1+n,greater<pair<int,int>>());
    for(int i=1;i<=n;i++){
        int cur=0,pos=-1;
        for(int j=1;j<=m;j++)
            if(num[j]&&spf[j]>=p[i].fir&&spf[j]<=p[i].sec&&spf[j]>cur)
                cur=spf[j],pos=j;
        if(pos!=-1)ans++,num[pos]--;
    }
    wrt(ans);
    return 0;
}
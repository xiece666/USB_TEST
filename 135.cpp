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
const ll N=3e5+10;
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
int n,m,sum[N],ans=INT_MIN;
int q[N],h=1,t=1;
int main(){
    read(n,m);
    for(int i=1;i<=n;i++)
        read(sum[i]),sum[i]+=sum[i-1];
    // for(int i=1;i<=n;i++)wrt(sum[i],' ');
    // puts("");
    for(int i=1;i<=n;i++){
        while(h<=t&&i-q[h]>m)h++;
        ans=max(ans,sum[i]-sum[q[h]]);
        while(h<=t&&sum[q[t]]>=sum[i])t--;
        q[++t]=i;
        // printf("i:%d q[h]:%d\n",i,q[h]);
    }
    wrt(ans);
    return 0;
}
/*
5 3
1 2 3 -2 -2

*/
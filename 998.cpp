#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define op first
#define val second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=1e5+10;
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
int n,m,cur,ans;
pair<string,int>p[N];
int calc(int b,int f){
    int res=f;
    for(int i=1;i<=n;i++){
        int x=(p[i].val>>b)&1;
        if(p[i].op=="XOR")res^=x;
        if(p[i].op=="OR")res|=x;
        if(p[i].op=="AND")res&=x;
    }
    return res;
}
int main(){
    read(n,m);
    for(int i=1;i<=n;i++){
        int x;string s;
        cin>>s,read(x);
        p[i]={s,x};
    }
    for(int b=29;b+1;b--){
        int cur1=calc(b,1);
        int cur0=calc(b,0);
        if(cur+(1<<b)<=m&&cur0<cur1)
            cur+=(1<<b),ans+=cur1<<b;
        else ans+=cur0<<b;
    }
    wrt(ans);
    return  0;
}
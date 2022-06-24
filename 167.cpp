#include<bits/stdc++.h>
#pragma GCC optimize(2)
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
const ll N=70;
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
int p[N],n,len,tot,sum,mx;
bitset<N>vis;
bool dfs(int cnt,int cur,int pre){
    if(cnt>tot)return 1;
    if(cur==len)return dfs(cnt+1,0,1);
    int fail=-1;
    for(int i=pre;i<=n;i++)
        if(!vis[i]&&cur+p[i]<=len&&fail!=p[i]){
            vis[i]=1;
            if(dfs(cnt,cur+p[i],i+1))return 1;
            fail=p[i];
            vis[i]=0;
            if(!cur||cur+p[i]==len)return 0;
        }
    return 0;
}
int main(){
    while(read(n),n){
        sum=0,mx=0;
        for(int i=1;i<=n;i++){
            read(p[i]);
            sum+=p[i],mx=max(mx,p[i]);
        }
        sort(p+1,p+1+n,greater<int>());
        for(len=mx;len<=sum;len++){
            if(sum%len)continue;
            tot=sum/len;
            vis=0;
            if(dfs(1,0,1))break;
        }
        wrt(len,'\n');
    }
    return  0;
}
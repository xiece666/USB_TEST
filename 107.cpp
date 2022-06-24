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
const ll N=5e5+10;
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
ll n,ans,p[N];
inline void merge_sort(ll L,ll R){
    if(L==R)return;
    ll mid=(L+R)>>1;
    merge_sort(L,mid);
    merge_sort(mid+1,R);
    ll l=L,r=mid+1;
    queue<ll>q;
    while(l<=mid&&r<=R){
        if(p[l]<=p[r])q.push(p[l++]);
        else ans+=(mid-l+1),q.push(p[r++]);
    }
    while(l<=mid)q.push(p[l++]);
    while(r<=R)q.push(p[r++]);
    for(ll i=L;i<=R;q.pop(),i++)p[i]=q.front();
}
int main(){
    while(read(n),1){
        if(!n)break;
        for(ll i=1;i<=n;i++)read(p[i]);
        ans=0;
        merge_sort(1,n);
        wrt(ans,'\n');
    }
    return 0;
}
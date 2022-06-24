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
const ll N=1e5+10,K=10;
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
ll n,k,ct,p[N],trie[N<<5][K],ansl[N],mxl,ans;
struct lyl{
    ll val,num,cnt;
    bool operator<(const lyl a)const{
        return val==a.val?cnt>a.cnt:val>a.val;
    }
};
__gnu_pbds::priority_queue<lyl>q;
void dfs(ll u,ll dep){
    if(u<=n)ansl[u]=dep;
    for(ll i=0;i<k;i++){
        if(!trie[u][i])continue;
        dfs(trie[u][i],dep+1);
    }
}
int main(){
    read(n,k);
    for(ll i=1;i<=n;i++){
        read(p[i]);
        q.push({p[i],i,0});
    }
    while((q.size()-1)%(k-1)!=0)q.push({0,0,0});
    ct=n;
    while(q.size()>1){
        lyl cur=(lyl){0,++ct,0};
        for(ll i=0;i<k;i++){
            cur.val+=q.top().val;
            trie[ct][i]=q.top().num;
            cur.cnt=max(cur.cnt,q.top().cnt);
            q.pop();
        }
        cur.cnt++;
        q.push(cur);
    }
    dfs(ct,0);
    for(ll i=1;i<=n;i++)mxl=max(mxl,ansl[i]),ans+=ansl[i]*p[i];
    wrt(ans,'\n',mxl,'\n');
    return  0;
}
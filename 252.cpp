#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define mkp make_pair
#define ebk emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
using namespace __gnu_pbds;
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
const ll N=1e4+10,S=1e7+10;
int n,K,ans;
int root,mx;
int siz[N],dis[N];
bitset<N>vis;
vector<pii>g[N];
vector<int>vec;
queue<int>opt,emp;
template<typename _Tp>
class BIT{
    private:
        _Tp arr[S];
        inline _Tp lowbit(_Tp x){return x&-x;}
    public:
        inline void clear(){mem(arr,0);}
        inline void config(_Tp pos,_Tp delta){
            for(;pos<=K+2;pos+=lowbit(pos))arr[pos]+=delta;
        }
        inline _Tp prefix_sum(_Tp pos){
            if(pos<0)return 0;
            _Tp res=_Tp();
            for(;pos;pos-=lowbit(pos))res+=arr[pos];
            return res;
        }
        inline _Tp range_sum(_Tp __l,_Tp __r){
            return prefix_sum(__r)-prefix_sum(__l-1);
        }
};
BIT<int>bit;
void dfs(int u,int fa,int s){
    siz[u]=1;
    int mxp=0;
    for(auto [v,val]:g[u])if(!vis[v]&&v!=fa)
        dfs(v,u,s),siz[u]+=siz[v],mxp=max(mxp,siz[v]);
    mxp=max(mxp,s-siz[u]);
    if(mxp<mx)mx=mxp,root=u;
}
void dfs_d(int u,int fa){
    vec.ebk(dis[u]);
    for(auto [v,val]:g[u])if(!vis[v]&&v!=fa)
        dis[v]=dis[u]+val,dfs_d(v,u);
}
void calc(int u){
    dis[u]=0,opt=emp;
    for(auto [v,val]:g[u]){
        if(vis[v])continue;
        dis[v]=dis[u]+val;
        vec.clear();
        dfs_d(v,u);
        for(int &i:vec){
            opt.push(++i);
            ans+=bit.prefix_sum(K+2-i)+(i<=K+1);
        }
        for(int i:vec)bit.config(i,1);
    }
    for(;!opt.empty();opt.pop())bit.config(opt.front(),-1);
}
void solve(int u){
    vis[u]=1,calc(u);
    for(auto [v,val]:g[u]){
        if(vis[v])continue;
        mx=INT_MAX,root=0;
        dfs(v,u,siz[v]),dfs(root,0,siz[v]);
        solve(root);
    }
}
int main(){
    while(read(n,K),1){
        if(!n&&!K)break;
        ans=0,vis=0;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1,x,y,z;i<n;i++)
            read(x,y,z),g[++x].ebk(++y,z),g[y].ebk(x,z);
        root=0,mx=INT_MAX;
        dfs(1,0,n),dfs(root,0,n);
        solve(root);
        wrt(ans,'\n');
    }
    return 0;
}
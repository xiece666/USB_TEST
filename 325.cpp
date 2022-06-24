#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define num first
#define val second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=1e4+10;
template <typename T> inline void read(T &x){
	x=0;int f=1;char c=getchar();
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
int n,dis[N],dis1[N],dis2[N],rt1,rt2,mx1,mx2;
vector<pair<int,int> >g[N];
void dfs1(int u,int fa){
	if(mx1<dis[u])mx1=dis[u],rt1=u;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].num,_=g[u][i].val;
		if(v==fa)continue;
		dis[v]=dis[u]+_;
		dfs1(v,u);
	}
}
void dfs2(int u,int fa){
	if(mx2<dis1[u])mx2=dis1[u],rt2=u;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].num,_=g[u][i].val;
		if(v==fa)continue;
		dis1[v]=dis1[u]+_;
		dfs2(v,u);
	}
}
void dfs3(int u,int fa){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].num,_=g[u][i].val;
		if(v==fa)continue;
		dis2[v]=dis2[u]+_;
		dfs3(v,u);
	}
}

int main(){
//  freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(~scanf("%d",&n)){
		int x,y;
		for(int i=1;i<=n;i++)g[i].clear();
		mem(dis,0),mem(dis1,0),mem(dis2,0);
		mx1=mx2=INT_MIN;
		for(int i=2;i<=n;i++){
			read(x,y);
			g[i].pbk(mkp(x,y));
			g[x].pbk(mkp(i,y));
		}
		dfs1(1,0);
		dfs2(rt1,0);
		dfs3(rt2,0);
		for(int i=1;i<=n;puts(""),i++)wrt(max(dis1[i],dis2[i]));
	}
	return  0;
}
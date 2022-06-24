#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<limits.h>
#include<cstring>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=2e5+10;
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
int n,sum[N<<2],ans[N],P;
pair<int,int>p[N];
void push_up(int rt){sum[rt]=sum[rt<<1]+sum[rt<<1|1];}
void build(int rt,int l,int r){
	if(l==r){
		sum[rt]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
	push_up(rt);
}
void update(int rt,int l,int r){
	if(l==r){
		sum[rt]=0;
		return;
	}
	int mid=(l+r)>>1;
	if(P<=mid)update(rt<<1,l,mid);
	else update(rt<<1|1,mid+1,r);
	push_up(rt);
}
int query(int rt,int l,int r){
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(sum[rt<<1]>=P)return query(rt<<1,l,mid);
	else return P-=sum[rt<<1],query(rt<<1|1,mid+1,r);
}
int main(){
//  freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(~scanf("%d",&n)){
		mem(sum,0),mem(ans,0);
		for(int i=1,x,y;i<=n;i++)read(x,y),p[i]={x,y};
		build(1,1,n);
		for(int i=n;i;i--){
			P=p[i].first+1;
			int res=query(1,1,n);
			ans[P=res]=p[i].second;
			update(1,1,n);
		}
		for(int i=1;i<=n;i++)wrt(ans[i]),putchar(' ');
		puts("");
	}
	return  0;
}



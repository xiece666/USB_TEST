#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll M=1e5+10,N=2e4+10;
template <typename T> inline void read(T &x){
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T> void wrt(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) wrt(x/10);
	putchar(x%10+48);
}
int n,m,fa[N<<1];
pair<int,pair<int,int> >e[M];
int root(int x){return fa[x]==x?x:fa[x]=root(fa[x]);}
void un(int x,int y,int v){
	int fx=root(x),fy=root(y);
	if(root(x%n)==root(y%n))wrt(v),exit(0);
	fa[fy]=fx;
	return;
}
int main(){
	read(n),read(m);
	for(int i=1;i<=(n<<1);i++)fa[i]=i;
	for(int i=1,x,y,z;i<=m;i++){
		read(x),read(y),read(z);
		e[i]=mkp(z,mkp(x,y));
	}
	sort(e+1,e+1+m);
	for(int i=m;i>=1;i--){
		int u=e[i].second.first,v=e[i].second.second,val=e[i].first;
		un(u+n,v,val),un(u,v+n,val);
	}
	wrt(0);
	return  0;
}
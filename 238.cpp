#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=3e4+10;
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
int T,fa[N],si[N],u,v,i,siz[N];
string s;
int root(int x){
	if(fa[x]==x)return x;
	int fx=root(fa[x]);
	si[x]+=si[fa[x]];
	return fa[x]=fx;
}
void un(int x,int y){
	int fx=root(x),fy=root(y);
	si[fx]+=siz[fy];
	fa[fx]=fy;
	siz[fy]+=siz[fx];
	siz[fx]=0;
	return;
}
int ck(int x,int y){
    if(x==y)return 0;
	int fx=root(x),fy=root(y);
	if(fx!=fy)return -1;
	return abs(si[x]-si[y])-1; 
}
int main(){
	read(T);
	for(int i=1;i<=3e4;i++)fa[i]=i,siz[i]=1;
	while(T--){
		cin>>s>>u>>v;
		if(s[0]=='M')un(u,v);
		else wrt(ck(u,v)),puts("");
//		printf("%d %d\n",root(u),root(v));
  	}
	return  0;
}
#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mke make_pair
#define pbk push_back
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=5e4+10;
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
int n,T,op,x,y,fa[N*3],ans;
int root(int x){return fa[x]==x?x:fa[x]=root(fa[x]);}
void un(int x,int y){
	int fx=root(x),fy=root(y);
	fa[fx]=fy;
	return;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(T);
	for(int i=1;i<=n*3;i++)fa[i]=i;
	while(T--){
		read(op),read(x),read(y);
		if(x>n||y>n||(x==y&&op==2)){
			ans++;
			continue;
		}
		if(op==1){
			if(root(x+n)==root(y)||root(x)==root(y+n))ans++;
			else un(x,y),un(x+n,y+n),un(x+(n<<1),y+(n<<1));
		}
		if(op==2){
			if(root(x)==root(y)||root(x)==root(y+n))ans++;
			else un(x+n,y),un(x,y+n+n),un(x+n+n,y+n);
		}
	}
	wrt(ans);
	return 0;
}

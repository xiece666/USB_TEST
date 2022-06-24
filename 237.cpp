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
const ll N=1e6+10;
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
int T,n,fa[N],q[N],ct;
string ans;
struct lyl{int x,y,e;}p[N];
bool cmp(lyl a,lyl b){return a.e>b.e;}
int root(int x){return fa[x]==x?x:fa[x]=root(fa[x]);}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;i++){
			read(p[i].x),read(p[i].y),read(p[i].e);
			q[++ct]=p[i].x;
			q[++ct]=p[i].y;
		}
		sort(q+1,q+1+ct);
		ct=unique(q+1,q+1+ct)-q;
		for(int i=1;i<=n;i++){
			p[i].x=lower_bound(q+1,q+1+ct,p[i].x)-q;
			p[i].y=lower_bound(q+1,q+1+ct,p[i].y)-q;
		}
		for(int i=1;i<=ct;i++)fa[i]=i;
		sort(p+1,p+1+n,cmp);
		ans="YES";
		for(int i=1;i<=n;i++){
			int fx=root(p[i].x),fy=root(p[i].y);
			if(p[i].e)fa[fy]=fx;
			else if(fx==fy){
				ans="NO";
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
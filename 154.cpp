#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
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
int n,m,p[N],q1[N],h1=1,t1,q2[N],h2=1,t2,ans1[N],ans2[N];
int main(){
//  freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)read(p[i]);
	for(int i=1;i<=n;i++){
		while(t1>=h1&&p[q1[t1]]<=p[i])t1--;
		q1[++t1]=i;
		while(t1>=h1&&i-q1[h1]+1>m)h1++;
		ans1[i]=p[q1[h1]];
		while(t2>=h2&&p[q2[t2]]>=p[i])t2--;
		q2[++t2]=i;
		while(t2>=h2&&i-q2[h2]+1>m)h2++;
		ans2[i]=p[q2[h2]];
	}
	for(int i=m;i<=n;putchar(' '),i++)wrt(ans2[i]);
	puts("");
	for(int i=m;i<=n;putchar(' '),i++)wrt(ans1[i]);
	return  0;
}

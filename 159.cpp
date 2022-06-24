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
const ll N=1e4+10,M=85;
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
int r,c,n,m,nxt[N];
string s1[N],s2[N];
void NEXT(string s[],int l){
	mem(nxt,0);
	for(int i=2,k=0;i<=l;i++){
		while(k&&s[i]!=s[k+1])k=nxt[k];
		if(s[i]==s[k+1])k++;
		nxt[i]=k;
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n,m);
	for(int i=1;i<=n;i++)cin>>s1[i];
	NEXT(s1,n);
	r=n-nxt[n];
	for(int i=0;i<m;i++){
		string tmp;
		for(int j=1;j<=r;j++)tmp.pbk(s1[j][i]);
		s2[i+1]=tmp;
	}
	NEXT(s2,m);
	c=m-nxt[m];
	wrt(r*c);
    system("pause");
    return 0;
}


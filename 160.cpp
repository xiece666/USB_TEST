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
int n,m,Q,x,nxt[N],f[N];
char s[N],t[N];
void NEXT(){
	for(int i=2,k=0;i<=m;i++){
		while(k&&t[i]!=t[k+1])k=nxt[k];
		if(t[i]==t[k+1])k++;
		nxt[i]=k;
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n,m,Q);
	scanf("%s%s",s+1,t+1);
	NEXT();
	for(int i=1,k=0;i<=n;i++){
		while(k&&s[i]!=t[k+1])k=nxt[k];
		if(s[i]==t[k+1])k++;
		f[k]++;
	}
	for(int i=m;i;i--)f[nxt[i]]+=f[i];
	while(Q--){
		read(x);
		wrt(f[x]-f[x+1]),puts("");
	}
    system("pause");
    return 0;
}


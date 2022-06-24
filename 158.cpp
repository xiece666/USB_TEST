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
int n,ans1,ans2;
char s1[N<<1],s2[N<<1];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);
	for(int i=1;i<=n;i++)s1[n+i]=s1[i],s2[n+i]=s2[i];
	int i=1,j=2,k;
	while(i<=n&&j<=n){
		for(k=0;k<n&&s1[i+k]==s1[j+k];k++);
		if(k==n)break;
		if(s1[i+k]<s1[j+k]){
			j+=k+1;
			if(i==j)j++;
		}else{
			i+=k+1;
			if(i==j)i++;
		}
	}
	ans1=min(i,j);
	i=1,j=2;
	while(i<=n&&j<=n){
		for(k=0;k<n&&s2[i+k]==s2[j+k];k++);
		if(k==n)break;
		if(s2[i+k]<s2[j+k]){
			j+=k+1;
			if(i==j)j++;
		}else{
			i+=k+1;
			if(i==j)i++;
		}
	}
	ans2=min(i,j);
	for(k=0;k<n;k++)if(s1[ans1+k]!=s2[ans2+k])return puts("No"),0;
	puts("Yes");
	for(k=0;k<n;k++)putchar(s1[ans1+k]);
    system("pause");
    return 0;
}


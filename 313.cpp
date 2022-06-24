#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=110;
int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc, r = 0, f = 1;
    while(c < 48) { if(c == 45) f = -1; c = gc; }
    while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
    return r * f;
}
void wrt(int x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[21]; int sz = 0;
    if(x < 0) pc(45), x = -x;
    if(!x) pc(48);
    else {
        while(x) c[++sz] = x % 10 + 48, x /= 10;
        while(sz) pc(c[sz--]);
    } pc(10);
}
int V,F,p[N][N],dp[N][N],ans,l[N][N];
int* _;
void print(int i,int j){
	if(i>1)print(i-1,l[i][j]);
	printf("%d ",j);
}
int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d%d",&F,&V);
	for(int i=1;i<=F;i++)for(int j=1;j<=V;j++)scanf("%d",&p[i][j]),dp[i][j]=INT_MIN;
	for(int i=1,s=0;i<=F;i++)for(int j=1;j<=V;j++)for(int k=i-1;k<j;k++)s=dp[i][j],dp[i][j]=max(dp[i][j],dp[i-1][k]+p[i][j]),l[i][j]=(s==dp[i][j]?l[i][j]:k);
	_=max_element(dp[F]+1,dp[F]+1+V);
	ans=_-dp[F];
	printf("%d\n",*_);
	print(F,ans);
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ri int
typedef long long ll;
using namespace std;
const int N=250010;
int n,x,cnt,a[N],c[N];
ll res1,res2;
inline int lowbit(int x){return x&(-x);}
void update(int x,int k){for(;x<=n*n;c[x]+=k,x+=lowbit(x));}
int query(int x){int s=0;for(;x;s+=c[x],x-=lowbit(x));return s;}
ll calc(){
    ll ret=0;
    memset(c,0,sizeof(c)); cnt=0;
    for(ri i=1;i<=n;i++)for(ri j=1;j<=n;j++){
            scanf("%d",&x);
            if(x) a[++cnt]=x;
    }
    if(n==1) return 0;
    for(ri i=n*n-1;i>=1;i--)
        ret+=query(a[i]-1),update(a[i],1);
    return ret;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        res1=calc(),res2=calc();
        if((res1^res2)&1) printf("NIE\n");
        else printf("TAK\n");
    }
    return 0;
}
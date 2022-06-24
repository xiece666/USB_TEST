#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N=40005;
const int T=205;

struct B {int l,r;} b[T];
int n,m,siz,cnt,len,ans;
int a[N],lsh[N],bel[N],t[N];
int s[T][N],f[T][T];

int read() {
    int x=0; char c=getchar();
    while(c<'0' || c>'9') c=getchar();
    while(c>='0' && c<='9') {x=x*10+c-'0'; c=getchar();}
    return x;
}
int val(int x) {return lower_bound(lsh+1,lsh+1+len,x)-lsh;}
int raw(int x) {return lsh[x];}

void build() {
    cnt=n/siz; if(n%siz) cnt++;
    for(int i=1;i<=cnt;i++) b[i]={(i-1)*siz+1,i*siz};
    b[cnt].r=n;
    for(int i=1;i<=cnt;i++) {
        int l=b[i].l,r=b[i].r;
        for(int j=l;j<=r;j++) s[i][a[j]]++,bel[j]=i;
        for(int j=1;j<=len;j++) s[i][j]+=s[i-1][j];
    }
    for(int i=1;i<=cnt;i++)
        for(int j=i;j<=cnt;j++) {
            int maxi=f[i][j-1];
            for(int k=b[j].l;k<=b[j].r;k++) {
                int v1=s[j][a[k]]-s[i-1][a[k]],v2=s[j][maxi]-s[i-1][maxi];
                if(v1>v2) maxi=a[k];
                else if(v1==v2) maxi=min(maxi,a[k]);
            }
            f[i][j]=maxi;
        }
}

void zero(int l,int r) {for(int i=l;i<=r;i++) t[a[i]]=0;}
int getGood(int l,int r,int L,int R,int maxi) {
    for(int i=l;i<=r;i++) {
        int v1=t[a[i]]+s[bel[R]-1][a[i]]-s[bel[L]][a[i]];
        int v2=t[maxi]+s[bel[R]-1][maxi]-s[bel[L]][maxi];
        if(v1>v2) maxi=a[i];
        else if(v1==v2) maxi=min(maxi,a[i]);
    }
    return maxi;
}
int violent(int l,int r) {
    for(int i=l;i<=r;i++) t[a[i]]++;
    int maxi=a[l];
    for(int i=l+1;i<=r;i++)
        if(t[a[i]]>t[maxi]) maxi=a[i];
        else if(t[a[i]]==t[maxi]) maxi=min(maxi,a[i]);
    zero(l,r);
    return raw(maxi);
}

int cal(int l,int r) {
    if(bel[r]-bel[l]<=1) return violent(l,r);
    int maxi=f[bel[l]+1][bel[r]-1];
    for(int i=l;i<=b[bel[l]].r;i++) t[a[i]]++;
    for(int i=b[bel[r]].l;i<=r;i++) t[a[i]]++;
    maxi=getGood(l,b[bel[l]].r,l,r,maxi);
    maxi=getGood(b[bel[r]].l,r,l,r,maxi);
    zero(l,b[bel[l]].r),zero(b[bel[r]].l,r);
    return raw(maxi);
}

int main()
{
    cin>>n>>m,siz=sqrt(n);
    for(int i=1;i<=n;i++) a[i]=lsh[i]=read();
    sort(lsh+1,lsh+1+n);
    len=unique(lsh+1,lsh+1+n)-lsh-1;
    for(int i=1;i<=n;i++) a[i]=val(a[i]);
    build();
    for(int i=1;i<=m;i++) {
        int l=(read()+ans-1)%n+1,r=(read()+ans-1)%n+1;
        if(l>r) swap(l,r);
        printf("%d\n",ans=cal(l,r));
    }
    return 0;
}
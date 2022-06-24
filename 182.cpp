#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define fir first
#define sec second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
const ll N=4000;
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
template <typename T> void wrt(T x,char c){wrt(x),putchar(c);}
template <typename T> void wrt(T x,char c1,T y,char c2){wrt(x,c1),wrt(y,c2);}
int n,m,T,s,tot,ans;
bitset<N>v,f[N],usd;
struct DancingLinksX{
    int head[N],siz[N];
    // virtual_head   colunm_size
    int U[N],D[N],L[N],R[N];
    // double direriction loop list
    int row[N],col[N];
    // information of a node
    int count;
    // size of the map,node count
    void build(int r,int c){//build a map of r*c
        count=c;
        for(int i=0;i<=c;i++){
            L[i]=i-1,R[i]=i+1;
            U[i]=D[i]=i;
            siz[i]=0;
        }
        L[0]=c,R[c]=0;
        mem(head,0);
    }
    void is(int r,int c){//insert a node at (r,c)
        count++;
        col[count]=c,row[count]=r,siz[c]++;
        D[count]=D[c],U[D[c]]=count;
        U[count]=c,D[c]=count;//up-down list operation
        if(!head[r])head[r]=L[count]=R[count]=count;//no node on row r
        else{
            R[count]=R[head[r]],L[R[head[r]]]=count;
            L[count]=head[r],R[head[r]]=count;//left-right list operation
        }
        // printf("insert (%d,%d):%d\n",r,c,count);
    }
    void rm(int c){//remove a colunm
        for(int i=D[c];i!=c;i=D[i])
            L[R[i]]=L[i],R[L[i]]=R[i];
    }
    void rc(int c){//reover a colunm
        for(int i=U[c];i!=c;i=U[i])
            L[R[i]]=R[L[i]]=i;
    }
    int h(){
        int res=0;
        usd=0;
        for(int i=R[0];i!=0;i=R[i])if(!usd[i]){
            usd[i]=1,res++;
            for(int j=D[i];j!=i;j=D[j])for(int k=L[j];k!=j;k=L[k])
                usd[col[k]]=1;
        }
        // printf("res:%d\n",res);
        return res;
    }
    void dance(int dep){
        if(dep+h()>=ans)return;
        if(!R[0]){
            ans=min(ans,dep);
            return;
        }
        // printf("ok %d\n",dep);
        int nxtc=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(siz[i]<siz[nxtc])nxtc=i;
        for(int i=D[nxtc];i!=nxtc;i=D[i]){
            rm(i);
            for(int j=R[i];j!=i;j=R[j])rm(j);
            dance(dep+1);
            for(int j=L[i];j!=i;j=L[j])rc(j);
            rc(i);
        }
        return;
    }
}dlx;
bool ck(int i,int j,int l){
    // printf("ck(%d,%d,%d):\n",i,j,l);
    for(int k=0;k<l;k++){
        if(v[(i-1)*(n*2+1)+j+k])return 0;
        if(v[(i-1+l)*(n*2+1)+j+k])return 0;
        if(v[i*n+(i-1)*(n+1)+j+k*(2*n+1)])return 0;
        if(v[i*n+(i-1)*(n+1)+j+k*(2*n+1)+l])return 0;
        // printf("    v[%d]:%d v[%d]:%d v[%d]:%d v[%d]:%d\n",
        // (i-1)*(n*2+1)+j+k,int(v[(i-1)*(n*2+1)+j+k]),
        // (i-1+l)*(n*2+1)+j+k,int(v[(i-1+l)*(n*2+1)+j+k]),
        // i*n+(i-1)*(n+1)+j+k*(2*n+1),int(v[i*n+(i-1)*(n+1)+j+k*(2*n+1)]),
        // i*n+(i-1)*(n+1)+j+k*(2*n+1)+l,int(v[i*n+(i-1)*(n+1)+j+k*(2*n+1)+l])
        // );
    }
    return 1;
}
int main(){
    read(T);
    // db st,ed,sum=0;
    while(T--){
        // st=clock();
        read(n,m);
        s=2*n*(n+1);
        v=0,tot=0;
        for(int i=0;i<N;i++)f[i]=0;
        while(m--){
            int x;read(x);
            v[x]=1;
        }
        for(int l=1;l<=n;l++)
            for(int i=1;i<=n-l+1;i++)for(int j=1;j<=n-l+1;j++){
                if(!ck(i,j,l))continue;
                tot++;
                for(int k=0;k<l;k++){
                    f[(i-1)*(n*2+1)+j+k][tot]=1;
                    f[(i-1+l)*(n*2+1)+j+k][tot]=1;
                    f[i*n+(i-1)*(n+1)+j+k*(2*n+1)][tot]=1;
                    f[i*n+(i-1)*(n+1)+j+k*(2*n+1)+l][tot]=1;
                }
                // printf("i:%d j:%d l:%d\n",i,j,l);
            }
        dlx.build(s,tot);
        for(int i=1;i<=s;i++)for(int j=1;j<=tot;j++)
            if(f[i][j])dlx.is(i,j);
        ans=INT_MAX;
        dlx.dance(0);
        wrt(ans,'\n');
        // ed=clock()-st;
        // printf("%.20lf\n",ed/CLOCKS_PER_SEC);
        // sum+=ed;
    }
    // printf("sum:%.20lf\n",sum/CLOCKS_PER_SEC);
    return 0;
}
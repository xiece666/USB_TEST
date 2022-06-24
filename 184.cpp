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
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define fir first
#define sec second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=30;
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
template <typename T1,typename T2> void wrt(T1 x1,char c1,T2 x2,char c2){wrt(x1,c1),wrt(x2,c2);}
int n,p[N];
char s[3][N];
bitset<N>vis;
vector<int>g;
bool ck(){
    for(int i=1,la=0;i<=n;i++){
        int a=p[s[0][i]-'A'],b=p[s[1][i]-'A'],c=p[s[2][i]-'A'];
        if(a!=-1&&b!=-1&&c!=-1){
            if(la!=-1){
                if((a+b+la)%n!=c)return 0;
                if(i==n&&a+b+la>=n)return 0;
                la=(a+b+la)/n;
            }else{
                if((a+b)%n!=c&&(a+b+1)%n!=c)return 0;
                if(i==n&&a+b>=n)return 0;
            }
        }else la=-1;
    }
    return 1;
}
bool dfs(int pos){
    // if(pos>0&&p[8]==8)for(int i=0;i<n;i++)wrt(p[i],' ');
    // if(pos>0&&p[8]==8)puts("");
    if(pos==n)return 1;
    for(int i=0;i<n;i++){
        if(vis[i])continue;
        vis[i]=1;
        p[g[pos]]=i;
        if(ck()&&dfs(pos+1))return 1;
        p[g[pos]]=-1;
        vis[i]=0;
    }
    return 0;
}
int main(){
    read(n),mem(p,-1);
    scanf("%s%s%s",s[0]+1,s[1]+1,s[2]+1);
    reverse(s[0]+1,s[0]+1+n),reverse(s[1]+1,s[1]+1+n),reverse(s[2]+1,s[2]+1+n);
    for(int i=1;i<=n;i++)for(int j=0;j<3;j++){
        int c=s[j][i]-'A';
        if(!vis[c])g.pbk(c),vis[c]=1;
    }
    // for(int i:g)wrt(i,' ');
    // puts("");
    vis=0;
    dfs(0);
    for(int i=0;i<n;i++)wrt(p[i],' ');
    return  0;
}
/*
12
FDALHECBJKGI
LIKAEDGJBCFH
IJJAFLICDLFE

8 7 4 6 5 10 2 11 9 1 3 0

4 3 9 10 1 7 11 5 8 6 2 0
*/
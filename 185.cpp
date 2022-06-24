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
const ll N=10;
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
int mp[N][N],n;
stack<int>X,Y,O;
bitset<N>usd[N];
bool ck(){
    for(int i=0;i<7;i++)for(int j=0;j<5;j++)
        if(mp[i][j])return 0;
    return 1;
}
void drop(){
    // for(int i=0;i<7;puts(""),i++)for(int j=0;j<5;j++)
    //     wrt(mp[i][j],' ');
    // puts("    |");
    // puts("    V");
    for(int i=1;i<7;i++)for(int j=0;j<5;j++){
        int t=i;
        while(t>=0&&mp[t][j]&&!mp[t-1][j])
            swap(mp[t][j],mp[t-1][j]),t--;
    }
    // for(int i=0;i<7;puts(""),i++)for(int j=0;j<5;j++)
        // wrt(mp[i][j],' ');
    // puts("\n");
}
bool disapp(){
    int res=0;
    for(int i=0;i<7;i++)usd[i]=0;
    // for(int i=0;i<7;puts(""),i++)for(int j=0;j<5;j++)
    //     wrt(mp[i][j],' ');
    // puts("    |");
    // puts("    V");
    for(int i=0;i<7;i++)for(int j=0;j<5;j++){
        if(!mp[i][j])continue;
        if(mp[i][j]==mp[i][j+1]&&mp[i][j]==mp[i][j+2])
            usd[i][j]=usd[i][j+1]=usd[i][j+2]=1;
        if(mp[i][j]==mp[i+1][j]&&mp[i][j]==mp[i+2][j])
            usd[i][j]=usd[i+1][j]=usd[i+2][j]=1;
    }
    for(int i=0;i<7;i++)for(int j=0;j<5;j++)
        if(usd[i][j])mp[i][j]=0,res=1;
    // for(int i=0;i<7;puts(""),i++)for(int j=0;j<5;j++)
        // wrt(mp[i][j],' ');
    // puts("\n");
    return res;
}
bool dfs(int stp){
    int res=ck();
    // if(stp<3){
    //     printf("stp:%d res:%d\n",stp,res);
    //     for(int i=0;i<7;puts(""),i++)for(int j=0;j<5;j++)
    //         wrt(mp[i][j],' ');
    //     puts("");
    // }
    if(res&&stp==n+1)return 1;
    if(res&&stp!=n+1)return 0;
    if(stp>n)return 0;
    int his[N][N];
    memcpy(his,mp,sizeof(mp));
    for(int j=0;j<5;j++)for(int i=0;i<7;i++){
        for(int dir=1;dir>=-1;dir-=2){
            if(j+dir<0||j+dir>4)continue;
            if(!mp[i][j])continue;
            if(dir==-1&&mp[i][j-1])continue;
            swap(mp[i][j],mp[i][j+dir]);
            drop();
            while(disapp())drop();
            if(dfs(stp+1)){
                // memcpy(mp,his,sizeof(mp));
                X.push(j),Y.push(i),O.push(dir);
                return 1;
            }
            memcpy(mp,his,sizeof(his));
        }
    }
    // memcpy(mp,his,sizeof(his));
    return 0;
}
int main(){
    read(n);
    for(int i=0,x,p=0;i<5;p=0,i++)
        while(read(x),x)mp[p++][i]=x;
    int res=dfs(1);
    if(res)while(n--){
        wrt(X.top(),' ',Y.top(),' '),wrt(O.top(),'\n');
        X.pop(),Y.pop(),O.pop();
    }else puts("-1");
    return  0;
}
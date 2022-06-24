#include<bits/stdc++.h>
#include<bits/extc++.h>
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
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define pbk push_back
#define fir first
#define sec second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
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
const ll N=4e4+10,B=790;
int n,la,Q,p[N],t[N],most[B][B];
int bl,ct,L[B],R[B],bg[N];
vector<int>g,exi[N];
int main(){
    read(n,Q),bl=sqrt(n*1.0*log2(n))/10;
    for(int i=1;i<=n;i++)read(p[i]),g.pbk(p[i]);
    sort(g.begin(),g.end());
    g.erase(unique(g.begin(),g.end()),g.end());
    for(int i=1;i<=n;i++){
        p[i]=lower_bound(g.begin(),g.end(),p[i])-g.begin()+1;
        exi[p[i]].pbk(i);
    }
    for(int i=1;i<=n;i+=bl)L[++ct]=i,R[ct]=min(n,i+bl-1);
    // for(int i=1;i<=ct;i++)printf("\nL[%d]:%d R[%d]:%d\n",i,L[i],i,R[i]);
    for(int i=1;i<=ct;i++)for(int j=L[i];j<=R[i];j++)bg[j]=i;
    for(int i=1;i<=ct;i++){
        for(int j=L[i];j<=n;j++){
            t[p[j]]++;
            if(j==R[bg[j]]){
                int res=0;
                for(int k=1;k<=g.size();k++){
                    if(t[res]==t[k]&&k<res)res=k;
                    if(t[res]<t[k])res=k;
                }
                most[i][bg[j]]=res;
                // printf("\nmost[%d][%d]:%d cnt[%d][%d]:%d\n",i,bg[j],res,i,bg[j],t[res]);
            }
        }
        for(int j=L[i];j<=n;j++)t[p[j]]--;
    }
    while(Q--){
        int l,r,mx;
        read(l,r);
        l=(l+la-1)%n+1,r=(r+la-1)%n+1;
        if(l>r)swap(l,r);
        for(int i=1;i<=g.size();i++)t[i]=0;
        if(bg[l]==bg[r]){
            la=0;
            for(int i=l;i<=r;i++)t[p[i]]++;
            for(int i=1;i<=g.size();i++){
                if(t[la]==t[i]&&i<la)la=i;
                if(t[la]<t[i])la=i;
            }
            wrt(la=g[la-1],'\n');
            continue;
        }
        la=bg[r]-bg[l]>1?most[bg[l]+1][bg[r]-1]:0;
        t[la]=mx=upper_bound(exi[la].begin(),exi[la].end(),r)-
            lower_bound(exi[la].begin(),exi[la].end(),l);
        for(int i=l;i<=R[bg[l]];i++){
            if(t[p[i]])continue;
            t[p[i]]=upper_bound(exi[p[i]].begin(),exi[p[i]].end(),r)-
                    lower_bound(exi[p[i]].begin(),exi[p[i]].end(),l);
            if(t[p[i]]==mx&&la>p[i])la=p[i];
            if(t[p[i]]>mx)la=p[i],mx=t[p[i]];
        }
        for(int i=L[bg[r]];i<=r;i++){
            if(t[p[i]])continue;
            t[p[i]]=upper_bound(exi[p[i]].begin(),exi[p[i]].end(),r)-
                    lower_bound(exi[p[i]].begin(),exi[p[i]].end(),l);
            if(t[p[i]]==mx&&la>p[i])la=p[i];
            if(t[p[i]]>mx)la=p[i],mx=t[p[i]];
        }
        // printf("\n[%d,%d]:",l,r);
        wrt(la=g[la-1],'\n');
    }
    return  0;
}
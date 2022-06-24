#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define mkp make_pair
#define ebk emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
using namespace __gnu_pbds;
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
const ll N=510,M=2010;
int n,m,ansl;
int sta[M],u[M],v[M];
int fa[N*3],l[N];
vector<int>ans;
//(0,n]:self (n,2n]:eat (2n,3n]:eaten
inline int root(int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++)l[i]=0;
        ans.clear();
        for(int i=1;i<=m;i++){
            char ch;
            scanf("%d%c%d",&u[i],&ch,&v[i]);
            u[i]++,v[i]++;
            if(ch=='>')swap(u[i],v[i]);
            sta[i]=(ch=='='?0:1);
        }
        for(int i=1;i<=n;i++){
            iota(fa,fa+1+3*n,0);
            bool fl=1;
            for(int j=1;j<=m;j++){
                int us=root(u[j]),ue=root(u[j]+n),ut=root(u[j]+2*n);
                int vs=root(v[j]),ve=root(v[j]+n),vt=root(v[j]+2*n);
                if(sta[j]){
                    if(us==vs||us==vt){
                        l[i]=j;
                        goto CON;
                    }
                    if(u[j]==i||v[j]==i)continue;
                    fa[vs]=ut,fa[ve]=us,fa[vt]=ue;
                }else{
                    if(ue==vs||ut==vs){
                        l[i]=j;
                        goto CON;
                    }
                    if(u[j]==i||v[j]==i)continue;
                    fa[vs]=us,fa[ue]=ve,fa[ut]=vt;
                }
            }
            ans.ebk(i);
            CON:;
        }
        if(!ans.size())puts("Impossible");
        else if(ans.size()>1)puts("Can not determine");
        else{
            ansl=0;
            for(int i=1;i<=n;i++)ansl=max(ansl,l[i]);
            printf("Player %d can be determined to be the judge after %d lines\n",ans.back()-1,ansl);
        }
    }
    return 0;
}
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
const ll N=6e5+10;
int n,m,s[N];
int root[N<<5],bel[N<<5],trie[2][N<<5],tot;
void insert(int t,int pre,int rt){
    bel[rt]=t;
    for(int i=23;~i;i--){
        int v=(s[t]>>i)&1;
        if(pre)trie[v^1][rt]=trie[v^1][pre];
        trie[v][rt]=++tot,bel[tot]=t;
        rt=trie[v][rt],pre=trie[v][pre];
    }
}
int query(int rt,int lim,int stan){
    for(int i=23;~i;i--){
        int v=((stan>>i)&1)^1;
        if(bel[trie[v][rt]]>=lim)rt=trie[v][rt];
        else rt=trie[v^1][rt];
    }
    return s[bel[rt]]^stan;
}
int main(){
    read(n,m);
    bel[0]=-1,root[0]=++tot;
    insert(0,0,root[0]);
    for(int i=1;i<=n;i++){
        read(s[i]),s[i]^=s[i-1];
        root[i]=++tot;
        insert(i,root[i-1],root[i]);
    }
    while(m--){
        char ch[2];scanf("%s",ch);
        int l,r,x;
        if(ch[0]=='A'){
            read(s[++n]),s[n]^=s[n-1];
            root[n]=++tot;
            insert(n,root[n-1],root[n]);
        }else{
            read(l,r,x);
            wrt(query(root[r-1],l-1,x^s[n]),'\n');
        }
    }
    return 0;
}
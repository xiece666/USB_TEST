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
const ll N=1e5+10;
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
ll n,trie[N<<5][2],ct=1,ans;
int main(){
    read(n);
    for(ll i=1,x;i<=n;i++){
        read(x);
        ll cur=1,tmp=x,res=tmp;
        // printf("\nx:%d\n",x);
        for(ll j=32;j>=0;j--){
            // printf("    j:%d goto",j);
            if(tmp>=(1ll<<j)){
                tmp-=(1ll<<j);
                if(trie[cur][0])cur=trie[cur][0];
                else if(trie[cur][1])cur=trie[cur][1],res^=(1ll<<j);
                else goto CONTINUE;
            }else{
                if(trie[cur][1])cur=trie[cur][1],res^=(1ll<<j);
                else if(trie[cur][0])cur=trie[cur][0];
                else goto CONTINUE;
            }
        }
        ans=max(ans,res);
        CONTINUE:
        cur=1;
        for(ll j=32;j>=0;j--){
            // printf("    j:%d",j);
            if(x>=(1ll<<j)){
                x-=(1ll<<j);
                if(!trie[cur][1])trie[cur][1]=++ct;
                cur=trie[cur][1];
                // puts(" add 1");
            }else{
                if(!trie[cur][0])trie[cur][0]=++ct;
                cur=trie[cur][0];
                // puts(" add 0");
            }
        }
    }
    // printf("%d\n",trie[1][1]);
    wrt(ans);
    return  0;
}
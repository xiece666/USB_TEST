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
char s[N];
int n,ans,dp[N];
int hs(char c){
    if(c=='(')return 1;
    if(c=='[')return 2;
    if(c=='{')return 3;
    if(c==')')return -1;
    if(c==']')return -2;;
    return -3;
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=2;i<=n;i++){
        if(hs(s[i])>0)continue;
        else{
            int x=hs(s[i-1-dp[i-1]]);
            if(x+hs(s[i])==0)dp[i]=dp[i-1]+2+dp[max(0,i-2-dp[i-1])];
            ans=max(ans,dp[i]);
        }
    }
    wrt(ans);
    return  0;
}
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
const ll N=1e6+10;
constexpr ull P=131;
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
ull sum[N],fac[N];
int n,Q,l1,r1,l2,r2;
int main(){
    scanf("%s",s+1),n=strlen(s+1);
    fac[0]=1;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]*P+(s[i]-'a'+1),fac[i]=fac[i-1]*P;
    read(Q);
    while(Q--){
        read(l1,r1,l2,r2);
        ull val1=sum[r1]-sum[l1-1]*fac[r1-l1+1];
        ull val2=sum[r2]-sum[l2-1]*fac[r2-l2+1];
        puts(val1==val2?"Yes":"No");
    }
    return  0;
}
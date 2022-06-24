#include<bits/stdc++.h>
#include<bits/extc++.h>
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
lll L,phi,d,cur,ans;
inline lll pw(lll a,lll b,lll mod){
    lll res=1%mod;
    for(a%=mod;b;b>>=1ll){
        if(b&1)(res*=a)%=mod;
        (a*=a)%=mod;
    }
    return res;
}
int main(){
    for(lll task=1;;task++){
        read(L);
        if(!L)break;
        d=__gcd(L,(lll)(8));
        phi=cur=L=9*L/d;
        for(lll i=2;i*i<=cur;i++)if(cur%i==0){
            phi=phi/i*(i-1);
            while(cur%i==0)cur/=i;
        }
        if(cur>1)phi=phi/cur*(cur-1);
        // printf("\nL:%lld\tphi:%lld\n",L,phi);
        ans=LLONG_MAX;
        for(lll i=1;i*i<=phi;i++)if(phi%i==0){
            lll a=i,res=pw(10,a,L);
            if(res==1){
                ans=min(ans,a);
                break;
            }else{
                a=phi/i,res=pw(10,a,L);
                // printf("a:%lld\tpw(%lld,%lld,%lld):%lld\n",a,10,a,L,res);
                if(res==1)ans=min(ans,a);
            }
        }
        printf("Case %lld: ",task),wrt(ans%LLONG_MAX,'\n');
    }
    return  0;
}
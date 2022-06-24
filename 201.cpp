#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long double
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
template <typename T1,typename T2> void wrt(T1 x,char c1,T2 y,char c2){wrt(x,c1),wrt(y,c2);}
const ll N=1000; 
ll Q,n,sum_phi[N+10];
int main(){
    for(int i=2;i<=N;i++)sum_phi[i]=i;
    for(int i=2;i<=N;i++)if(sum_phi[i]==i)
        for(int j=i;j<=N;j+=i)sum_phi[j]=sum_phi[j]/i*(i-1);
    for(int i=2;i<=N;i++)sum_phi[i]+=sum_phi[i-1];
    read(Q);
    for(int i=1;i<=Q;i++){
        read(n);
        wrt(i,' ',n,' ');
        wrt(3+2*sum_phi[n],'\n');
    }
    return 0;
}
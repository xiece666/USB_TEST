#include<bits/stdc++.h>
#define ll long long
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
int n,p[N],ct;
stack<int>s,emp;
bool ck(){
    s=emp;
    for(int i=1,j=0;i<=n;i++){
        while(j<n&&(s.empty()||s.top()!=p[i]))s.push(++j);
        if(s.top()!=p[i])return 0;
        s.pop();
    }
    return 1;
}
int main(){
    read(n);
    for(int i=1;i<=n;i++)p[i]=i;
    do{
        if(!ck())continue;
        for(int i=1;i<=n;i++)wrt(p[i]);
        puts(""),ct++;
    }while(next_permutation(p+1,p+1+n)&&ct<20);
    return  0;
}
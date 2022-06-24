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
const ll N=1;
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
ll d1[3][3]={
    {0,3,4},
    {3,6,6},
    {4,6,6}
};
ll d2[3][3]={
    {0,3,4},
    {1,4,5},
    {2,4,5}
};
ll d3[3][3]={
    {0,1,2},
    {3,4,4},
    {4,5,5}
};
ll d4[3][3]={
    {0,1,2},
    {1,2,3},
    {2,3,4}
};
ll f(ll x,ll y){
    x=abs(x),y=abs(y);
    ll a=x/3,b=x%3;
    ll c=y/3,d=y%3;
    ll res=(a+c)*2;
    if(a==0&&c==0)res+=d1[b][d];
    if(a==0&&c)res+=d2[b][d];
    if(a&&c==0)res+=d3[b][d];
    if(a&&c)res+=d4[b][d];
    // printf("f(%d,%d):%d\n",x,y,res);
    return res;
}
ll r,c,ans;
char O;
int main(){
    while(cin>>O>>r>>c){
        ans=INT_MAX;
        if(O=='U')ans=f(r,c);
        if(O=='V'){
            ans=_min(ans,f(r-1,c-2)+3,f(r+2,c-2)+3);
            ans=_min(ans,f(r-1,c-1)+2,f(r+2,c-1)+2);
            ans=_min(ans,f(r-1, c )+1,f(r+2, c )+1);
            ans=_min(ans,f(r-1,c+1)+2,f(r+2,c+1)+2);
            ans=_min(ans,f(r-1,c+2)+3,f(r+2,c+2)+3);
        }
        if(O=='H'){
            ans=_min(ans,f(r-2,c-1)+3,f(r-2,c+2)+3);
            ans=_min(ans,f(r-1,c-1)+2,f(r-1,c+2)+2);
            ans=_min(ans,f( r ,c-1)+1,f( r ,c+2)+1);
            ans=_min(ans,f(r+1,c-1)+2,f(r+1,c+2)+2);
            ans=_min(ans,f(r+2,c-1)+3,f(r+2,c+2)+3);
        }
        wrt(ans,'\n');
    }
    return  0;
}
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
const ll N=1010;
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
int n,m,ans,p[N][N];
stack<pair<int,int>>s,emp;
//fir:h sec:w
int main(){
    read(n,m);
    for(int i=1;i<=n;i++){
        int ct=0;
        char c;
        for(int j=1;j<=m;j++){
            c=getchar(),getchar();
            if(c=='F')ct++;
            else ct=0;
            p[i][j]=ct;
            // printf("%d ",p[i][j]);
        }
        // puts("");
    }
    emp.push({-1,0});
    for(int j=1;j<=m;j++){
        s=emp;
        for(int i=1;i<=n+1;i++){
            if(p[i][j]>s.top().fir)s.push({p[i][j],1});
            else{
                int sum=0;
                while(p[i][j]<=s.top().fir){
                    int h=s.top().fir,w=s.top().sec;
                    s.pop();
                    sum+=w;
                    ans=max(ans,sum*h);
                }
                s.push({p[i][j],sum+1});
            }
        }
    }
    wrt(ans*3);
    return  0;
}
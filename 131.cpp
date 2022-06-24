#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define h first
#define w second
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
ll n,p[N],ans;
stack<pair<ll,ll>>s,emp;
int main(){
    emp.push({0,0});
    while(read(n),1){
        if(!n)break;
        p[n+1]=ans=0,s=emp;
        for(ll i=1;i<=n;i++)read(p[i]);
        for(ll i=1;i<=n+1;i++){
            if(p[i]>s.top().h)s.push({p[i],1});
            else{
                ll sum=0;
                while(!s.empty()&&p[i]<=s.top().h){
                    sum+=s.top().w;
                    ans=max(ans,sum*s.top().h);
                    s.pop();
                    // printf("ans:%d\n",ans);
                }
                s.push({p[i],sum+1});
                // printf("ans:%d\n",ans);
            }
            // printf("s.top():{%d,%d} s.size():%d\n",s.top().h,s.top().w,s.size());
            // printf("ans:%d i:%d\n",ans,i);
        }
        wrt(ans,'\n'); 
    }
    return  0;
}
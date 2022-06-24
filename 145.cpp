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
const ll N=1e4+10;
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
int n,ans;
priority_queue<int,vector<int>,greater<int>>q;
pair<int,int>p[N];
int main(){
    while(~scanf("%d",&n)){
        ans=0;
        for(int i=1;i<=n;i++)read(p[i].sec,p[i].fir);
        sort(p+1,p+1+n);
        q.push(0);
        for(int i=1;i<=n;i++){
            swap(p[i].fir,p[i].sec);
            if(int(q.size())<p[i].sec)q.push(p[i].fir);
            else if(!q.empty()&&int(q.size())==p[i].sec&&q.top()<p[i].fir){
                q.pop();
                q.push(p[i].fir);
            }
            // printf("p[%d]:{%d,%d} size():%d top():%d\n",i,p[i].fir,p[i].sec,q.size(),q.empty()?-1:q.top());
        }
        while(!q.empty())ans+=q.top(),q.pop();
        wrt(ans,'\n');
    }
    return  0;
}
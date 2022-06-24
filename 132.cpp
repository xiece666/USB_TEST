#include<bits/stdc++.h>
#include<bits/extc++.h>
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
using namespace __gnu_pbds;
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
int n,T;
gp_hash_table<int,int>f;
queue<int>q[N],emp;
int main(){
    while(read(n),1){
        if(!n)break;
        f.clear(),q[0]=emp;
        for(int i=1,x,y;i<=n;i++){
            read(x),q[i]=emp;
            while(x--)read(y),f[y]=i;
        }
        printf("Scenario #%d\n",++T);
        string op;
        while(cin>>op){
            if(op=="STOP")break;
            if(op=="ENQUEUE"){
                int x;
                read(x);
                if(q[f[x]].empty())q[0].push(f[x]);
                q[f[x]].push(x);
            }
            if(op=="DEQUEUE"){
                wrt(q[q[0].front()].front(),'\n');
                q[q[0].front()].pop();
                if(q[q[0].front()].empty())q[0].pop();
            }
        }
        puts("");
    }
    return  0;
}
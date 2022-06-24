#include<bits/stdc++.h>
#include<bits/extc++.h>
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
using namespace __gnu_pbds;
const ll N=2010;
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
int T,n,m,f,p[2][N],tmp[N],ct;
struct lyl{
    int u,d;
    bool la;
    bool operator<(const lyl a)const{
        return p[f][u]+p[f^1][d]>=p[f][a.u]+p[f^1][a.d];
    }
};
__gnu_pbds::priority_queue<lyl>q,emp;
int main(){
    read(T);
    while(T--){
        read(m,n);
        for(int i=1;i<=n;i++)read(p[0][i]);
        sort(p[0]+1,p[0]+1+n);
        f=0;
        for(int _=2;_<=m;f^=1,_++){
            for(int i=1;i<=n;i++)read(p[f^1][i]);
            sort(p[f^1]+1,p[f^1]+1+n);
            q=emp,ct=0;
            q.push((lyl){1,1,0});
            for(int i=1;i<=n;i++){
                lyl cur=q.top();q.pop();
                tmp[++ct]=p[f][cur.u]+p[f^1][cur.d];
                if(!cur.la)q.push((lyl){cur.u+1,cur.d,0});
                q.push((lyl){cur.u,cur.d+1,1});
            }
            for(int i=1;i<=n;i++)p[f^1][i]=tmp[i];
        }
        for(int i=1;i<=n;i++)wrt(p[f][i],' ');
        puts("");
    }
    return  0;
}
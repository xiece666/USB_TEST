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
template <typename T> void wrt(T x,char c1,T y,char c2){wrt(x,c1),wrt(y,c2);}
int n,T;
db ans;
struct lyl{
    db x,y;
    int tp;
    bool operator<(const lyl a)const{
        return y==a.y?x<a.x:y<a.y;
    }
}p[N<<1];
bool cmp(lyl a,lyl b){return a.x==b.x?a.y<b.y:a.x<b.x;}
multiset<lyl>s[2];
int main(){
    read(T);
    while(T--){
        read(n),ans=1e12,s[0].clear(),s[1].clear();
        for(int i=1,a,b;i<=(n<<1);i++){
            read(a,b);
            p[i]=(lyl){a*1.0,b*1.0,i>n};
        }
        n<<=1;
        sort(p+1,p+1+n,cmp);
        for(int i=1,la=1;i<=n;i++){
            lyl u=p[i];
            // printf("i:%d (%lf,%lf) tp:%d\n",i,u.x,u.y,u.tp);
            while(la<i&&u.x-p[la].x>ans)s[p[la].tp].erase(s[p[la].tp].find(p[la++]));
            for(auto j=s[u.tp^1].lower_bound((lyl){u.x,u.y-ans,u.tp^1});j!=s[u.tp^1].end()&&fabs((j->y)-u.y)<ans;j++)
                ans=min(ans,sqrt(((j->y)-u.y)*((j->y)-u.y)+((j->x)-u.x)*((j->x)-u.x)));
            s[u.tp].insert(u);
            // puts("    s[0]:");
            // for(auto j=s[0].begin();j!=s[0].end();j++)printf("      (%lf,%lf) tp:%d\n",j->x,j->y,j->tp);
            // puts("    s[1]:");
            // for(auto j=s[1].begin();j!=s[1].end();j++)printf("      (%lf,%lf) tp:%d\n",j->x,j->y,j->tp);
            // printf("    ans:%lf\n\n\n",ans);
        }
        printf("%.3lf",ans);
    }
    return 0;
}
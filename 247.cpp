#include<bits/stdc++.h>
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
const ll N=2e5+10;
int n,m,L,R,D;
int lazy[N<<2];
db sum[N<<2],y[2][N],ans;
struct lyl{
    int yl,yr,del;
    db x;
    bool operator<(const lyl a)const{
        return x<a.x;
    }
}p[N<<1];
vector<db>g;
inline void __update(int rt,int l,int r){
    if(lazy[rt])sum[rt]=g[r]-g[l-1];
    else sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    // printf("sum[%d,%d]:%lf\n",l,r,sum[rt]);
}
inline void update(int rt,int l,int r){
    if(L<=l&&r<=R){
        lazy[rt]+=D;
        __update(rt,l,r);
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid)update(rt<<1,l,mid);
    if(R>mid)update(rt<<1|1,mid+1,r);
    __update(rt,l,r);
}
int main(){
    for(int task=1;;task++){
        read(n);
        if(!n)break;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%lf%lf",&p[i*2-1].x,&y[0][i],&p[i<<1].x,&y[1][i]);
            g.pbk(y[0][i]),g.pbk(y[1][i]);
            p[i*2-1].del=1,p[i*2].del=-1;
        }
        sort(g.begin(),g.end());
        g.erase(unique(g.begin(),g.end()),g.end());
        for(int i=1;i<=n;i++){
            p[i*2-1].yl=p[i<<1].yl=lower_bound(g.begin(),g.end(),y[0][i])-g.begin()+1;
            p[i*2-1].yr=p[i<<1].yr=lower_bound(g.begin(),g.end(),y[1][i])-g.begin()+1;
        }
        m=g.size()-1;
        sort(p+1,p+1+n*2);
        ans=0.0;
        for(int i=1;i<=n*2;i++){
            L=p[i].yl,R=p[i].yr-1,D=p[i].del;
            // printf("X:%lf L:%d R:%d D:%d\n",p[i].x,L,R,D);
            update(1,1,m);
            if(i<n*2)ans+=(p[i+1].x-p[i].x)*sum[1];
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",task,ans);
    }
    return  0;
}
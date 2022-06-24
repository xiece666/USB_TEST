#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long double
#define ebk emplace_back
#define mkp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
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
const ll N=5010,S=2e5+10,SL=-1e4,SR=1e4;
int n,m,ans;
int L,R,D;
int sx[N],sy[N],ex[N],ey[N];
int cnt[S<<2],len[S<<2];
struct lyl{
    int l,r,y,del;
    bool operator<(const lyl a)const{return y==a.y?del>a.del:y<a.y;}
}ma[N<<1];
void push_up(int rt,int l,int r){
    if(cnt[rt])len[rt]=r-l+1;
    else len[rt]=len[rt<<1]+len[rt<<1|1];
}
void cover(int rt,int l,int r){
    if(L<=l&&r<=R){
        cnt[rt]+=D,push_up(rt,l,r);
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid)cover(rt<<1,l,mid);
    if(R>mid)cover(rt<<1|1,mid+1,r);
    push_up(rt,l,r);
}
void solve(){
    mem(len,0),mem(cnt,0);
    sort(ma+1,ma+1+m);
    for(int i=1;i<=m;i++){
        int pre=len[1];
        i--;
        do{
            i++;
            L=ma[i].l,R=ma[i].r-1,D=ma[i].del;
            cover(1,SL,SR);
            // printf("{%d,%d,%d,%d}\n",ma[i].l,ma[i].r,ma[i].y,ma[i].del);
        }while(ma[i].y==ma[i+1].y&&ma[i].del==ma[i+1].del);
        ans+=abs(pre-len[1]);
        // printf("%d->%d ans:%d\n",pre,len[1],ans);
    }    
}
int main(){
    read(n);
    for(int i=1,a,b,c,d;i<=n;i++){
        read(a,b,c,d);
        sx[i]=a,sy[i]=b,ex[i]=c,ey[i]=d;
        ma[++m]=(lyl){a,c,b,1};
        ma[++m]=(lyl){a,c,d,-1};
    }
    ma[2*n+1]=(lyl){0,0,0,2};
    solve();
    m=0;
    for(int i=1,a,b,c,d;i<=n;i++){
        a=sx[i],b=sy[i],c=ex[i],d=ey[i];
        ma[++m]=(lyl){b,d,a,1};
        ma[++m]=(lyl){b,d,c,-1};
    }
    solve();
    wrt(ans);
    return 0;
}
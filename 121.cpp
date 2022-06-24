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
const ll N=510;
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
int n,c,l=0,r=1e4,h,w,ans,s[N][N],x[N],y[N];
vector<int>X,Y;
vector<int>::iterator px,py;
inline bool ck(int md){
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
        int rx=max(X[i-1]-md+1,0),ry=max(Y[j-1]-md+1,0);
        int _x=lower_bound(X.begin(),px,rx)-X.begin()+1;
        int _y=lower_bound(X.begin(),py,ry)-Y.begin()+1;
        if(X[_x-1]<rx)_x++;
        if(Y[_y-1]<ry)_y++;
        if(s[i][j]-s[i][_y-1]-s[_x-1][j]+s[_x-1][_y-1]>=c)return 1;
    }
    return 0;
}
int main(){
    read(c,n);
    for(int i=1;i<=n;i++)
        read(x[i],y[i]),X.pbk(x[i]),Y.pbk(y[i]);
    sort(X.begin(),X.end()),sort(Y.begin(),Y.end());
    X.erase(unique(X.begin(),X.end()),X.end()),px=X.end();
    Y.erase(unique(Y.begin(),Y.end()),Y.end()),py=Y.end();
    // px=unique(X.begin(),X.end()),py=unique(Y.begin(),Y.end());
    for(int i=1;i<=n;i++){
        x[i]=lower_bound(X.begin(),px,x[i])-X.begin()+1;
        y[i]=lower_bound(Y.begin(),py,y[i])-Y.begin()+1;
        s[x[i]][y[i]]++;
    }
    h=px-X.begin(),w=py-Y.begin();
    for(int i=1;i<=500;i++)for(int j=1;j<=500;j++)
        s[i][j]+=(s[i-1][j]+s[i][j-1]-s[i-1][j-1]);
    while(l<=r){
        int mid=(l+r)>>1;
        if(ck(mid))r=mid-1,ans=mid;
        else l=mid+1;
        // printf("l:%d r:%d ans:%d ck(%d):%d\n",l,r,ans,mid,ck(mid));
    }
    // printf("ck(3):%d\n",ck(3));
    wrt(ans);
    return 0;
}
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
#define pii pair<ll,ll>
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
namespace IO{
#define MAXSIZE (1<<20)
char *p1=NULL,*p2=NULL,buf[MAXSIZE];
inline char gchar(){
    return
#ifdef DEBUG
    getchar();
#else
    p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXSIZE,stdin),p1==p2)?EOF:*p1++;
#endif
}
template<typename _Tp>inline void read(_Tp &x){
    x=0;char ch=gchar();
    for(;!isdigit(ch);ch=gchar());
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
}
template<typename _Tp>inline void nread(_Tp &x){
    x=0;_Tp f=1;char ch=gchar();
    for(;!isdigit(ch);ch=gchar())ch=='-'&&(f=-1);
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
    x*=f;
}
template<typename _Tp,typename ...Args>
inline void read(_Tp &x,Args &...args){read(x),read(args...);}
template<typename _Tp,typename ...Args>
inline void nread(_Tp &x,Args &...args){nread(x),nread(args...);}
template<typename _Tp>inline void wrt(_Tp x){
    if(x<0)x=-x,putchar('-');
    if(x>9)wrt(x/10);
    putchar(x%10+48);
}
inline void wrt(char ch){putchar(ch);}
template<typename _Tp,typename ...Args>
inline void wrt(_Tp x,Args ...args){wrt(x),wrt(args...);}
#undef MAXSIZE
}
using IO::read,IO::nread,IO::wrt,IO::gchar;
const ll N=1e5+10,L=17;
ll n,Q,h[N],X,S,ans;
ldb ansk=1e18;
ll nxt[2][L][N],dis[2][2][L][N];
// nxt[A/B][2^j days][start] dis[A/B][start person(A/B)][2^j days][start]
struct cmp{bool operator()(const ll a,const ll b)const{return h[a]<h[b];}};
set<ll,cmp>s;
pii calc(ll p){
    ll sa=0,sb=0;
    // printf("calc(%lld,%lld):",p,X);
    for(ll i=L-1;~i&&p;i--){
        if(!nxt[0][i][p])continue;
        ll na=sa+dis[0][0][i][p];
        ll nb=sb+dis[1][0][i][p];
        if(na+nb<=X)sa=na,sb=nb,p=nxt[0][i][p];
    }
    // printf("{%lld,%lld}\n",sa,sb);
    return mkp(sa,sb);
}
signed main(){
    read(n);
    for(ll i=1;i<=n;i++)nread(h[i]);
    s.emplace(0),h[0]=-2e9-1;
    s.emplace(n+1),h[n+1]=2e9+1;
    for(ll i=n;i;i--){
        auto itr=s.upper_bound(i);
        auto itl=--itr;itr++;
        // printf("{%lld,%lld}\n",*itl,*itr);
        if(h[i]-h[*itl]<=h[*itr]-h[i]){
            nxt[1][0][i]=*itl;
            if(itl!=s.begin()){
                itl--;
                nxt[0][0][i]=h[i]-h[*itl]<=h[*itr]-h[i]?*itl:*itr;
            }else nxt[0][0][i]=*itr;
        }else{
            nxt[1][0][i]=*itr;
            if(++itr!=s.end())
                nxt[0][0][i]=h[i]-h[*itl]<=h[*itr]-h[i]?*itl:*itr;
            else nxt[0][0][i]=*itl;
        }
        dis[0][0][0][i]=abs(h[i]-h[nxt[0][0][i]]);
        dis[1][1][0][i]=abs(h[i]-h[nxt[1][0][i]]);
        if(nxt[0][0][i]>n)nxt[0][0][i]=0;
        if(nxt[1][0][i]>n)nxt[1][0][i]=0;
        // printf("%lld:{%lld,%lld}\n",i,nxt[0][0][i],nxt[1][0][i]);
        s.emplace(i);
    }
    for(ll j=1;j<L;j++)for(ll k=1;k<=n;k++)for(ll i=0;i<2;i++){
        nxt[i][j][k]=nxt[i^(j==1)][j-1][nxt[i][j-1][k]];
        for(ll l=0;l<2;l++)
            dis[i][l][j][k]=dis[i][l][j-1][k]+dis[i][l^(j==1)][j-1][nxt[l][j-1][k]];
    }
    // printf("%lld %lld %lld %lld\n",dis[1][0][1][7],dis[0][0][1][7],dis[1][1][0][9],dis[1][0][0][7]);
    read(X);
    // printf("{%lld,%lld} {%lld,%lld} %lld\n",calc(30).fir,calc(30).sec,calc(96).fir,calc(96).sec,abs(h[27]-h[26]));
    for(ll i=1;i<=n;i++){
        auto [sa,sb]=calc(i);
        ldb k=sb?(ldb)sa/(ldb)sb:1e18;
        if(k<ansk)ansk=k,ans=i;
        else if(k==ansk&&h[i]>h[ans])ans=i;
    }
    wrt(ans,'\n');
    read(Q);
    while(Q--){
        read(S,X);
        auto [sa,sb]=calc(S);
        wrt(sa,' ',sb,'\n');
    }
    return 0;
}
/*
100
-26380932 -22679357 -21366282 -13457591 -4887741 -441955 -629701 -48147959 -44988819 -37008287 -34553007 -32822530 -27440485 -26059840 -86550374 -80274487 -75151274 -66571940 -58312018 -57173400 -55555547 -111966819 -104762441 -104608922 -99638934 -94599754 -93271105 -87375061 -128943461 -125372919 -123410299 -120968152 -120929135 -117800008 -112442669 -156065934 -154165771 -150118917 -146319072 -138129923 -133682386 -128784580 -185451666 -182685268 -177544527 -177041658 -175084161 -170619454 -164167578 -191341425 0 5619921 12969090 13988019 20386542 20775622 23031319 29731499 30210691 37940743 38101204 37597555 41663154 46851680 49215536 48414077 51683125 52580132 59145190 64803261 69924361 69319336 70891891 75970471 80855020 87204420 90887962 98109753 102829029 110901208 118467298 124039154 124687803 124126019 128076565 128878805 129973370 129956203 132552256 131774312 134229618 133502905 140711479 144743353 151543993 153134235 153874703 154049876 162175525 166135681
153905588
1
26 3798496

*/

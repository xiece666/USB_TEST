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
const ll N=55;
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
int n,D,p[N],is[N],ds[N];
bool dfs(int pos,int ti,int td){
    if(ti+td>D)return 0;
    if(pos>n)return 1;
    int res=-1,m=p[pos];
    for(int i=1;i<=ti;i++)
        if(m>p[pos]-is[i]&&p[pos]>is[i])
            m=p[pos]-is[i],res=i;
    if(res==-1){
        is[ti+1]=p[pos];
        bool k=dfs(pos+1,ti+1,td);
        is[ti+1]=0;
        if(k)return 1;
    }else{
        int tmp=is[res];
        is[res]=p[pos];
        bool k=dfs(pos+1,ti,td);
        is[res]=tmp;
        if(k)return 1;
    }
    res=-1,m=1e9-p[pos];
    for(int i=1;i<=td;i++)
        if(m>ds[i]-p[pos]&&p[pos]<ds[i])
            m=ds[i]-p[pos],res=i;
    if(res==-1){
        ds[td+1]=p[pos];
        bool k=dfs(pos+1,ti,td+1);
        ds[td+1]=0;
        if(k)return 1;
    }else{
        int tmp=ds[res];
        ds[res]=p[pos];
        bool k=dfs(pos+1,ti,td);
        ds[res]=tmp;
        if(k)return 1;
    }
    return 0;
}
int main(){
    while(read(n),n){
        for(int i=1;i<=n;i++)read(p[i]);
        mem(is,0),mem(ds,0);
        is[0]=1e9;
        for(D=1;D<n;D++)
            if(dfs(1,0,0))break;
        wrt(D,'\n');
    }
    return  0;
}
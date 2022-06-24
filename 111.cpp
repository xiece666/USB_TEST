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
const ll N=5e4+10;
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
int n,anst=1,ans[N],la[N];
struct lyl{
    int l,r,num;
    bool operator<(const lyl a)const{
        return l<a.l;
    }
}p[N];
int main(){
    read(n);
    for(int i=1;i<=n;i++)read(p[i].l,p[i].r),p[i].num=i;
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++){
        bool fl=0;
        for(int j=1;j<=anst;j++)
            if(la[j]<p[i].l){
                la[j]=p[i].r,fl=1;
                ans[p[i].num]=j;
                break;
            }
        if(!fl){
            la[++anst]=p[i].r;
            ans[p[i].num]=anst;
        }
        
    }
    wrt(anst,'\n');
    for(int i=1;i<=n;i++)wrt(ans[i],'\n');
    return 0;
}
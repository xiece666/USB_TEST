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
const ll N=20;
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
int T,D,n,p[N];
bool fl;
int h(){
    int res=0;
    for(int i=1;i<n;i++)
        if(p[i+1]!=p[i]+1)res++;
    return int(ceil(res*1.0/3.0));
}
bool IDA_star(int dep){
    int ht=h();
    // printf("D:%d dep:%d ht:%d\n",D,dep,ht);
    // for(int i=1;i<=n;i++)wrt(p[i],' ');
    // puts("");
    if(!ht)return 1;
    // puts("1");
    if(dep+ht-1>D)return 0;
    // puts("2");
    int his[N];
    memcpy(his,p,sizeof(p));
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            for(int k=r+1;k<=n;k++){
                int pos=0;
                for(int i=1;i<l;i++)p[++pos]=his[i];
                for(int i=r+1;i<=k;i++)p[++pos]=his[i];
                for(int i=l;i<=r;i++)p[++pos]=his[i];
                for(int i=k+1;i<=n;i++)p[++pos]=his[i];
                if(IDA_star(dep+1)){
                    for(int i=1;i<=n;i++)p[i]=his[i];
                    return 1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)p[i]=his[i];
    return 0;
}
int main(){
    read(T);
    while(T--){
        read(n);
        for(int i=1;i<=n;i++)read(p[i]);
        fl=0;
        for(D=0;D<=4&&!fl;D++)
            if(IDA_star(1))fl=1;
        D--;
        if(fl)wrt(D,'\n');
        else puts("5 or more");
    }
    return  0;
}
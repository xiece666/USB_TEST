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
const ll N=1e6+10;
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
class lyl{
    private:
        int head=1,tail=0;
        int S[N],sum[N],mx[N];
        stack<int>_S;
        void update(int pos){
            sum[pos]=sum[pos-1]+S[pos];
            mx[pos]=max(mx[pos-1],sum[pos]);
        }
    public:
        void init(){mx[0]=INT_MIN;}
        void D(){if(tail>=head)tail--;}
        void L(){if(tail>=head)_S.push(S[tail--]);}
        void R(){
            if(_S.empty())return;
            S[++tail]=_S.top(),_S.pop();
            update(tail);
        }
        void I(int x){
            S[++tail]=x;
            update(tail);
        }
        int Q(int x){return mx[x];}
}s;
int Q;
int main(){
    read(Q);
    s.init();
    while(Q--){
        char c;int x;
        cin>>c;
        if(c=='D')s.D();
        if(c=='L')s.L();
        if(c=='R')s.R();
        if(c=='I')read(x),s.I(x);
        if(c=='Q')read(x),wrt(s.Q(x),'\n');
    }
    return  0;
}
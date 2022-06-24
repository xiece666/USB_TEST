#include<bits/stdc++.h>
#include<bits/extc++.h>
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
const ll N=8e5+10,W=2e6+10;
int w,n,ctq,ans[N];
struct lyl{
    int x,y,a,tp,id;
    bool operator<(const lyl b)const{return x==b.x?y<b.y:x<b.x;}
}op[N];
template<typename _Tp>
class BIT{
    private:
        _Tp array[W];
        inline _Tp lowbit(_Tp x){return x&-x;}
    public:
        inline void config(_Tp pos,_Tp delta){
            for(;pos<=w;pos+=lowbit(pos))array[pos]+=delta;
        }
        inline _Tp prefix_sum(_Tp pos){
            if(pos<0)return 0;
            _Tp res=_Tp();
            for(;pos;pos-=lowbit(pos))res+=array[pos];
            return res;
        }
};
BIT<int>bit;
inline void CDQ_solve(int L,int R){
    if(L==R)return;
    int mid=(L+R)>>1,l=L,r=mid+1;
    CDQ_solve(L,mid),CDQ_solve(mid+1,R);
    sort(op+L,op+1+mid),sort(op+mid+1,op+1+R);
    for(;r<=R;r++){
        for(;l<=mid&&op[l].x<=op[r].x;l++)
            if(op[l].tp)bit.config(op[l].y,op[l].a);
        if(!op[r].tp)ans[op[r].id]+=op[r].a*bit.prefix_sum(op[r].y);
    }
    for(l--;l>=L;l--)if(op[l].tp)bit.config(op[l].y,-op[l].a);
}
int main(){
    read(w,w),w++;
    while(1){
        int opt,h,j,k,l;
        read(opt);
        if(opt==3)break;
        if(opt==1){
            read(h,j,k),n++,h++,j++;
            op[n]=(lyl){h,j,k,1,0};
        }else{
            read(k,l,h,j),h++,j++,ctq++;
            n++,op[n]=(lyl){h,j, 1,0,ctq};
            n++,op[n]=(lyl){k,l, 1,0,ctq};
            n++,op[n]=(lyl){h,l,-1,0,ctq};
            n++,op[n]=(lyl){k,j,-1,0,ctq};
        }
    }
    // for(int i=1;i<=n;i++)printf("op[%d]:{%d,%d,%d,%d,%d}\n",i,op[i].x,op[i].y,op[i].a,op[i].tp,op[i].id);
    CDQ_solve(1,n);
    for(int i=1;i<=ctq;i++)wrt(ans[i],'\n');
    return 0;
}
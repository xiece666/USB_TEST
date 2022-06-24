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
const ll N=15;
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
deque<pair<int,bool>>q[N];
int ct[N],ans;
//front:up back:down
int H(char c){
    if(c>'0'&&c<='9')return c^48;
    if(c==48)return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
    return 1;
}
int main(){
    for(int i=1;i<=13;i++)for(int j=1;j<=4;j++){
        char c=getchar();getchar();
        q[i].pbk({H(c),0});
        // printf("%d ",H(c));
    }
    while(!q[13].empty()){
        int cur=q[13].front().fir;
        q[13].pop_front();
        // printf("start from cur:%d\n",cur);
        while(cur!=13){
            q[cur].push_front({cur,1});
            int tmp=cur;
            cur=q[cur].back().fir;
            // printf("come to heap %d,go to heap %d\n",tmp,cur);
            q[tmp].pop_back();
        }
    }
    for(int i=1;i<=12;i++)while(!q[i].empty())
        ct[q[i].front().fir]+=q[i].front().sec,q[i].pop_front();
    for(int i=1;i<=12;i++)if(ct[i]==4)ans++;
    wrt(ans);
    return 0;
}
/*
8 5 A A
K 5 3 2
9 6 0 6
3 4 3 4
3 4 4 5
5 6 7 6
8 7 7 7
9 9 8 8
9 0 0 0
K J J J
Q A Q K
J Q 2 2
A K Q 2

*/
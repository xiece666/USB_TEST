#include<queue>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define num first
#define val second
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=3e4+10;
template <typename T> inline void read(T &x){
    x=0;int f=1;char c=getchar();
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
int n,m,u[N],p[N],siz,pos=1;
priority_queue<int>qx;
priority_queue<int,vector<int>,greater<int> >qi;
int main(){
    read(m,n);
    for(int i=1;i<=m;i++)read(p[i]);
    for(int i=1;i<=n;i++)read(u[i]);
    for(int i=1;i<=m;i++){
        if(i==1)qx.push(p[i]);
        else if(p[i]>qx.top())qi.push(p[i]);
        else qx.push(p[i]);
        // printf("qx.top():%d qx.size():%d qi.top():%d qi.size():%d u[%d]:%d\n",qx.top(),qx.size(),qi.size()>0?qi.top():-1,qi.size(),pos,u[pos]);
        while(qi.size()+qx.size()==u[pos]){
            while(!qx.empty()&&qx.size()>pos)qi.push(qx.top()),qx.pop();
            while(!qi.empty()&&qx.size()<pos)qx.push(qi.top()),qi.pop();
            wrt(qx.top()),puts("");
            pos++;
        }
    }
    system("pause");
    return  0;
}
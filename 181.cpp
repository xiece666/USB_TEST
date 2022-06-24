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
const ll N=30;
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
int p[N],ct[4],D;
bool fl;
stack<int>ans;
int cen[8]={7,8,9,12,13,16,17,18};
int opp[8]={5,4,7,6,1,0,3,2};
int pos[8][7]={
    {1,3,7,12,16,21,23},
    {2,4,9,13,18,22,24},
    {11,10,9,8,7,6,5},
    {20,19,18,17,16,15,14},
    {24,22,18,13,9,4,2},
    {23,21,16,12,7,3,1},
    {14,15,16,17,18,19,20},
    {5,6,7,8,9,10,11}
};
int h(){
    mem(ct,0);
    for(int i=0;i<8;i++)ct[p[cen[i]]]++;
    int mx=0;
    for(int i=1;i<=3;i++)mx=max(mx,ct[i]);
    return 8-mx;
}
bool IDA_star(int dep,int pre){
    int ht=h();
    if(!ht)return 1;
    if(dep+ht-1>D)return 0;
    int his[N];
    memcpy(his,p,sizeof(p));
    for(int i=0;i<8;i++){
        if(i==pre)continue;
        int tmp=p[pos[i][0]];
        for(int j=1;j<7;j++)
            p[pos[i][j-1]]=p[pos[i][j]];
        p[pos[i][6]]=tmp;
        if(IDA_star(dep+1,opp[i])){
            ans.push(i);
            return 1;
        }
        memcpy(p,his,sizeof(p));
    }
    return 0;
}
int main(){
    while(read(p[1]),p[1]){
        for(int i=2;i<=24;i++)read(p[i]);
        fl=0;
        for(D=0;D<=1e4&&!fl;D++)
            if(IDA_star(1,-1))fl=1;
        if(ans.empty())puts("No moves needed");
        else{
            while(!ans.empty())putchar(ans.top()+'A'),ans.pop();
            puts("");
        }
        wrt(p[cen[0]],'\n');
    }
    return  0;
}
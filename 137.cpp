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
const ll N=1e5+10;
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
int n;
set<vector<int>>s;
int main(){
    read(n);
    for(int i=1;i<=n;i++){
        vector<int>tmp(0);
        int p[15]={0};
        for(int j=1;j<=6;j++)
            read(p[j]),p[j+6]=p[j];
        int l=1,r=2,k;
        while(l<=6&&r<=6){
            for(k=0;k<6&&p[l+k]==p[r+k];k++);
            if(k==6)break;
            if(p[l+k]<p[r+k]){
                r+=k+1;
                if(l==r)r++;
            }else{
                l+=k+1;
                if(l==r)l++;
            }
        }
        for(int j=0;j<6;j++)tmp.pbk(p[j+min(l,r)]);
        reverse(p+1,p+13);
        l=1,r=2;
        while(l<=6&&r<=6){
            for(k=0;k<6&&p[l+k]==p[r+k];k++);
            if(k==6)break;
            if(p[l+k]<p[r+k]){
                r+=k+1;
                if(l==r)r++;
            }else{
                l+=k+1;
                if(l==r)l++;
            }
        }
        for(int j=0;j<6;j++)if(p[j+min(l,r)]<tmp[j]){
            for(k=0;k<6;k++)tmp[k]=p[k+min(l,r)];
            break;
        }else if(p[j+min(l,r)]>tmp[j])break;
        // for(int j=0;j<6;j++)printf("%d ",tmp[j]);
        // puts("");
        s.insert(tmp);
    }
    if(s.size()!=n)puts("Twin snowflakes found.");
    else puts("No two snowflakes are alike.");
    return  0;
}
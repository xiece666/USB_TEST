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
const ll N=2e6+10;
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
int n,l,r,ans,T,d[N];
char S[N];
string s;
int main(){
    while(scanf("%s",S+1),1){
        if(S[1]=='E')break;
        s.clear();
        for(int i=1;S[i];i++)s+='#',s+=S[i];
        s+='#',n=s.length(),l=0,r=-1,ans=1;
        for(int i=0;i<n;i++){
            int k=(i>r?1:min(r-i+1,d[l+(r-i)]));
            while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
            d[i]=--k;
            if(i+d[i]>r)r=i+d[i],l=i-d[i];
            ans=max(ans,d[i]);
        }
        printf("Case %d: %d\n",++T,ans);
    }
    return  0;
}
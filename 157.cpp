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
const ll N=3010;
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
string s[2];
int T;
string dfs(int fl,int &pos){
    pos++;
    vector<string>g(0);
    while(s[fl][pos]=='0')g.pbk(dfs(fl,pos));
    pos++;
    sort(g.begin(),g.end());
    string res="0";
    for(string i:g)res+=i;
    return res+"1";
}
int main(){
    read(T);
    while(T--){
        cin>>s[0]>>s[1];
        s[0]="0"+s[0]+"1",s[1]="0"+s[1]+"1";
        int p1=0,p2=0;
        puts(dfs(0,p1)==dfs(1,p2)?"same":"different");
    }
    return  0;
}
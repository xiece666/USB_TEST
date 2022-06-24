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
const ll N=6;
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
bool p[N][N],vis[N][N];
vector<pair<int,int>>vec,ans;
inline void change(int x,int y){
    for(int i=0;i<4;i++)
        p[i][y]^=1,p[x][i]^=1;
    p[x][y]^=1;
}
inline void dfs(int x,int y){
    if(x==3&&y==4){
        bool fl=0;
        for(int i=0;i<4;i++)for(int j=0;j<4;j++)
            if(p[i][j]){
                fl=1;
                goto BREAK;
            }
        BREAK:
        if(!fl&&(ans.empty()||ans.size()>vec.size()))ans=vec;
        return;
    }
    if(y==4)x++,y=0;
    change(x,y);
    vec.pbk({x,y});
    dfs(x,y+1);
    vec.pop_back();
    change(x,y);
    dfs(x,y+1);
}
int main(){
    char c;
    for(int i=0;i<4;getchar(),i++)for(int j=0;j<4;j++)
        c=getchar(),p[i][j]=(c=='+');
    // for(int i=0;i<4;puts(""),i++)for(int j=0;j<4;j++)printf("%d",p[i][j]);
    dfs(0,0);
    wrt(ans.size(),'\n');
    for(auto i:ans)wrt(i.fir+1,' ',i.sec+1,'\n');
    return 0;
}
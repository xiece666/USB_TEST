#include<bits/stdc++.h>
#define ll long long
#define lll __int128
#define db double
#define ldb long double
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
template <typename T> void wrt(T x,char c1,T y,char c2){wrt(x,c1),wrt(y,c2);}
const ll N=5;
int T,D;
int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1,1,2,2,1,-1,-2};
char mp[N][N];
char tar[N][N]={
    {'1','1','1','1','1'},
    {'0','1','1','1','1'},
    {'0','0','*','1','1'},
    {'0','0','0','0','1'},
    {'0','0','0','0','0'}
};
int h(){
    int res=0;
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)
        if(mp[i][j]!='*')res+=(mp[i][j]!=tar[i][j]);
    return res;
}
bool IDA_star(int dep){
    int ht=h();
    if(!ht)return 1;
    if(dep+ht>D)return 0;
    int ux,uy;
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)
        if(mp[i][j]=='*'){
            ux=i,uy=j;
            break;
        }
    for(int i=0;i<8;i++){
        int vx=ux+dx[i],vy=uy+dy[i];
        if(vx<0||vx>4||vy<0||vy>4)continue;
        swap(mp[vx][vy],mp[ux][uy]);
        if(IDA_star(dep+1))return 1;
        swap(mp[vx][vy],mp[ux][uy]);
    }
    return 0;
}
int main(){
    read(T);
    while(T--){
        for(int i=0;i<5;i++)scanf("%s",mp[i]);
        for(D=0;D<=15;D++)
            if(IDA_star(0))break;
        if(D>15)puts("-1");
        else wrt(D,'\n');
    }
    return 0;
}
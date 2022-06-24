#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long double
#define ebk emplace_back
#define mkp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
namespace IO{
#define MAXSIZE (1<<20)
char *p1=NULL,*p2=NULL,buf[MAXSIZE];
#ifdef DEBUG
#define gchar() getchar()
#else
#define gchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXSIZE,stdin),p1==p2)?EOF:*p1++)
#endif
inline void read(char *x){
    char ch=gchar();
    while(ch==' '||ch=='\n'||ch=='\r')ch=gchar();
    do *x++=ch,ch=gchar(); while(ch!=' '&&ch!='\n'&&ch!='\r');
    *x='\0';
}
template<typename _Tp>inline void read(_Tp &x){
    x=0;char ch=gchar();
    for(;!isdigit(ch);ch=gchar());
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
}
template<typename _Tp>inline void nread(_Tp &x){
    x=0;_Tp f=1;char ch=gchar();
    for(;!isdigit(ch);ch=gchar())ch=='-'&&(f=-1);
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
    x*=f;
}
template<typename _Tp,typename ...Args>
inline void read(_Tp &x,Args &...args){read(x),read(args...);}
template<typename _Tp,typename ...Args>
inline void nread(_Tp &x,Args &...args){nread(x),nread(args...);}
template<typename _Tp>inline void wrt(_Tp x){
    if(x<0)x=-x,putchar('-');
    if(x>9)wrt(x/10);
    putchar(x%10+48);
}
inline void wrt(char ch){putchar(ch);}
inline void wrt(char *s){while(*s!='\0')putchar(*s++);}
inline void wrt(const char *s){while(*s!='\0')putchar(*s++);}
template<typename _Tp,typename ...Args>
inline void wrt(_Tp x,Args ...args){wrt(x),wrt(args...);}
#undef MAXSIZE
}using IO::read,IO::nread,IO::wrt;
const ll N=110;
int n;
int nxt[N];
int dp[N][N],pre[N][N],p[N][N];
char s[N];
pii zip(int l,int r){
    nxt[0]=-1;
    for(int i=1,j=-1;i<=r-l;i++){
        while(~j&&s[l+i]!=s[l+j+1])j=nxt[j];
        if(s[l+i]==s[l+j+1])j++;
        nxt[i]=j;
    }
    for(int i=1;i<=r-l;i++)nxt[i]++;
    int res=r-l+1,t=1,mn=r-l+1-nxt[r-l];
    // if(l==1&&r==6)printf("->%d %d\n",res,mn);
    for(int i=1;i*mn<=r-l;i++){
        if((r-l+1)%(mn*i))continue;
        int len=dp[l][l+mn*i-1];
        int cnt=(r-l+1)/(mn*i),tot=log10(cnt)+3+len;
        // if(l==1&&r==6)printf("-->%d:%d %d %d (%d,%d)\n",i,len,cnt,tot,res,t);
        if(res>tot)res=tot,t=cnt;
    }
    return mkp(res,t);
}
void print(int l,int r){
    if(pre[l][r]==r){
        if(p[l][r]==1)for(int i=l;i<=r;i++)wrt(s[i]);
        else{
            wrt(p[l][r],'('),print(l,l+(r-l+1)/p[l][r]-1),wrt(')');
        }
        return;
    }
    print(l,pre[l][r]),print(pre[l][r]+1,r);
}
signed main(){
    read(s+1),n=strlen(s+1);
    for(int i=1;i<=n;i++)dp[i][i]=1,pre[i][i]=i,p[i][i]=1;
    for(int _=2;_<=n;_++)for(int i=1,j=_;j<=n;i++,j++){
        auto [x,y]=zip(i,j);
        // if(y>1)printf("zip(%d,%d):{%d,%d}\n",i,j,x,y);
        dp[i][j]=x,pre[i][j]=j,p[i][j]=y;
        for(int k=i;k<j;k++)if(dp[i][k]+dp[k+1][j]<dp[i][j])
            dp[i][j]=dp[i][k]+dp[k+1][j],pre[i][j]=k;
        // if(_<=26)printf("[%d,%d]:{%d,%d,%d}\n",i,j,dp[i][j],p[i][j],pre[i][j]);
    }
    print(1,n);
    return 0;
}
/*
ABABABXYZXYZXYZXYZNASANASAABABABXYZXYZXYZXYZNASANASA
1234567890123456789012345678901234567890123456789012
0000000001111111111222222222233333333334444444444555
*/
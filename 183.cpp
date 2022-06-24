#include<bits/stdc++.h>
#pragma GCC optimize(2)
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
const int N=9;
const int SIZE=2e5+10;
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
int ans=-1;
int f(int r,int c){
    if(r==5&&c==5)return 10;
    if(r<=6&&r>=4&&c<=6&&c>=4)return 9;
    if(r<=7&&r>=3&&c<=7&&c>=3)return 8;
    if(r<=8&&r>=2&&c<=8&&c>=2)return 7;
    return 6;
}
struct DancingLinksX{
    int s[SIZE];
    int head[SIZE],siz[SIZE];
    int U[SIZE],D[SIZE],L[SIZE],R[SIZE];
    int col[SIZE],row[SIZE];
    int n,m,count;
    void build(int r,int c){
        n=r,m=count=c;
        for(int i=0;i<=c;i++){
            L[i]=i-1,R[i]=i+1;
            siz[i]=0;
            U[i]=D[i]=i;
        }
        L[0]=c,R[c]=0;
        mem(head,0);
    }
    void is(int r,int c){
        count++;
        row[count]=r,col[count]=c;
        D[count]=D[c],U[D[c]]=count;
        U[count]=c,D[c]=count;
        siz[c]++;
        if(!head[r])head[r]=L[count]=R[count]=count;
        else{
            R[count]=R[head[r]],L[R[head[r]]]=count;
            L[count]=head[r],R[head[r]]=count;
        }
        // printf("count:%d\n",count);
    }
    void rm(int c){
        L[R[c]]=L[c],R[L[c]]=R[c];
        for(int i=D[c];i!=c;i=D[i])for(int j=R[i];j!=i;j=R[j])
            U[D[j]]=U[j],D[U[j]]=D[j],siz[col[j]]--;
    }
    void rc(int c){
        for(int i=U[c];i!=c;i=U[i])for(int j=L[i];j!=i;j=L[j])
            D[U[j]]=U[D[j]]=j,siz[col[j]]++;
        L[R[c]]=R[L[c]]=c;
    }
    void dance(int dep){
        // puts("ok");
        if(!R[0]){
            int res=0;
            // puts("ok");
            for(int i=1;i<dep;i++){
                int cur=s[i]-1;
                int r=cur/N/N+1;
                int c=cur/N%N+1;
                int p=cur%N+1;
                res+=f(r,c)*p;
            }
            ans=max(ans,res);
            return;
        }
        int nxtc=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(siz[i]<siz[nxtc])nxtc=i;
        // printf("nxtc:%d\n",nxtc);
        rm(nxtc);
        for(int i=D[nxtc];i!=nxtc;i=D[i]){
            for(int j=R[i];j!=i;j=R[j])rm(col[j]);
            s[dep]=row[i];
            // printf("row[%d]:%d\n",i,row[i]);
            dance(dep+1);
            for(int j=L[i];j!=i;j=L[j])rc(col[j]);
        }
        rc(nxtc);
    }
}dlx;
void insert(int r,int c,int p){
    int nr=(r-1)*N*N+(c-1)*N+p;
    int _x=(r-1)/3+1,_y=(c-1)/3+1;
    int gri=(_x-1)*3+_y;
    int t1=(r-1)*N+p;
    int t2=N*N+(c-1)*N+p;
    int t3=N*N*2+(gri-1)*N+p;
    int t4=N*N*3+(r-1)*N+c;
    dlx.is(nr,t1),dlx.is(nr,t2);
    dlx.is(nr,t3),dlx.is(nr,t4);
}
int main(){
    dlx.build(N*N*N,N*N*4);
    for(int i=1,x;i<=N;i++)for(int j=1;j<=N;j++){
        read(x);
        if(x)insert(i,j,x);
        else for(int p=1;p<=N;p++)
            insert(i,j,p);
    }
    dlx.dance(1);
    wrt(ans);
    return  0;
}
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const int N=16,NN=256;
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
int ans[N+10][N+10];
char s[N+10][N+10];
struct DancingLinksX{
    stack<int>s;
    int head[SIZE],siz[SIZE];
    // virtual_head   colunm_size
    int U[SIZE],D[SIZE],L[SIZE],R[SIZE];
    // double direriction loop list
    int row[SIZE],col[SIZE];
    // information of a node
    int n,m,count;
    // size of the map,node count
    void build(int r,int c){//build a map of r*c
        n=r,m=count=c;
        for(int i=0;i<=m;i++){
            L[i]=i-1,R[i]=i+1;
            U[i]=D[i]=i;
            siz[i]=0;
        }
        L[0]=c,R[c]=0;
        mem(head,0);
    }
    void is(int r,int c){//insert a node at (r,c)
        count++;
        col[count]=c,row[count]=r,siz[c]++;
        D[count]=D[c],U[D[c]]=count;
        U[count]=c,D[c]=count;//up-down list operation
        if(!head[r])head[r]=L[count]=R[count]=count;//no node on row r
        else{
            R[count]=R[head[r]],L[R[head[r]]]=count;
            L[count]=head[r],R[head[r]]=count;//left-right list operation
        }
    }
    void rm(int c){//remove a colunm
        L[R[c]]=L[c],R[L[c]]=R[c];
        for(int i=D[c];i!=c;i=D[i])for(int j=R[i];j!=i;j=R[j])
            U[D[j]]=U[j],D[U[j]]=D[j],siz[col[j]]--;
    }
    void rc(int c){//reover a colunm
        for(int i=U[c];i!=c;i=U[i])for(int j=L[i];j!=i;j=L[j])
            D[U[j]]=U[D[j]]=j,siz[col[j]]++;
        L[R[c]]=R[L[c]]=c;
    }
    bool dance(){
        if(!R[0]){
            while(!s.empty()){
                int cur=s.top()-1;s.pop();
                int x=cur/N/N+1;
                int y=cur/N%N+1;
                int p=cur%N+1;
                ans[x][y]=p;
            }
            return 1;
        }
        int nxtc=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(siz[i]<=siz[nxtc])nxtc=i;
        rm(nxtc);
        for(int i=D[nxtc];i!=nxtc;i=D[i]){
            for(int j=R[i];j!=i;j=R[j])rm(col[j]);
            s.push(row[i]);
            if(dance())return 1;
            s.pop();
            for(int j=L[i];j!=i;j=L[j])rc(col[j]);
        }
        rc(nxtc);
        return 0;
    }
}dlx;
void insert(int r,int c,int p){
    int nr=(r-1)*NN+(c-1)*N+p;
    int _x=(r-1)/4+1,_y=(c-1)/4+1;
    int gri=(_x-1)*4+_y;
    int t1=(r-1)*N+p;//write p in row r
    int t2=NN+(c-1)*N+p;//write p in colunm c
    int t3=NN*2+(gri-1)*N+p;//write p in grid gri
    int t4=NN*3+(r-1)*N+c;//write a number in (r,c)
    dlx.is(nr,t1);
    dlx.is(nr,t2);
    dlx.is(nr,t3);
    dlx.is(nr,t4);
}
int main(){
    bool fl=0;
    while(~scanf("%s",s[1]+1)){
        if(fl)puts("");
        fl=1;
        dlx.build(NN*N,NN*4);
        for(int i=2;i<=N;i++)scanf("%s",s[i]+1);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                int t=(s[i][j]=='-'?0:s[i][j]-'A'+1);
                ans[i][j]=t;
                if(t)insert(i,j,t);
                else for(int p=1;p<=N;p++)
                    insert(i,j,p);
            }
        }
        dlx.dance();
        for(int i=1;i<=N;puts(""),i++)for(int j=1;j<=N;j++)
            putchar(ans[i][j]+'A'-1);
    }
    return  0;
}
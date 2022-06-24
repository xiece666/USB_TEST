#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
#define _max(aaa,bbb,ccc) max(aaa,max(bbb,ccc))
#define _min(aaa,bbb,ccc) min(aaa,min(bbb,ccc))
using namespace std;
const ll N=1e6+10;
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
int n,T,nxt[N];
char s[N];
void NEXT(){
    mem(nxt,0);
    for(int i=2,k=0;i<=n;i++){
        while(k&&s[i]!=s[k+1])k=nxt[k];
        nxt[i]=(k+=(s[i]==s[k+1]));
    }
}
int main(){
    while(read(n),n){
        scanf("%s",s+1);
        NEXT();
        printf("Test case #%d\n",++T);
        for(int i=2;i<=n;i++){
            int k=i-nxt[i];
            if(i%k==0&&i/k>1)wrt(i),putchar(' '),wrt(i/k),puts("");
        }
        puts("");
    }
    system("pause");
    return  0;
}
#include<bits/stdc++.h>
#define ll long long
#define ldb long double
#define db double
#define mkp make_pair
#define pbk push_back
#define end en
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
int n,m,tire[N][26],end[N],tot;
char s[N],t[N];
void insert(char *c){
    int len=strlen(c+1),p=0;
    for(int i=1;i<=len;i++){
        int ch=c[i]-'a';
        if(!tire[p][ch])tire[p][ch]=++tot;
        p=tire[p][ch];
    }
    end[p]++;
}
int search(char *c){
    int len=strlen(c+1),p=0,res=0;
    for(int i=1;i<=len;i++){
        int ch=c[i]-'a';
        if(!tire[p][ch])break;
        p=tire[p][ch];
        res+=end[p];
    }
    return res;
}
int main(){
    read(n,m);
    for(int i=1;i<=n;i++)scanf("%s",s+1),insert(s);
    while(m--){
        scanf("%s",t+1);
        wrt(search(t)),puts("");
    }
    system("pause");
    return  0;
}
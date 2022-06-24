#include<bits/stdc++.h>
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
const int N=3e5+10,P=131;
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
string s;
int n,sa[N],hight[N];
ull sum[N],fac[N];
int p[N];

bool cmp(int a,int b){
    // return s.substr(a)<s.substr(b);
    int l=1,r=min(n-a,n-b),res=0;
    // cout<<"s1:"<<s1<<" s2:"<<s2<<endl;
    // printf("a:%d b:%d\n",a,b);
    while(l<=r){
        int mid=(l+r)>>1;
        ull val1=sum[a+mid-1]-sum[a-1]*fac[mid];
        ull val2=sum[b+mid-1]-sum[b-1]*fac[mid];
        if(val1==val2)l=mid+1,res=mid;
        else r=mid-1;
        // printf("l:%d r:%d res:%d\n",l,r,res);
    }
    if(res==n-a)return 1;
    if(res==n-b)return 0;
    return s[a+res]<s[b+res];
}
int main(){
    ios::sync_with_stdio(0);
    cin>>s;
    n=s.length();
    fac[0]=1,sum[0]=s[0]-'a'+1;
    for(int i=1;i<n;i++)sum[i]=sum[i-1]*P+(s[i]-'a'+1),fac[i]=fac[i-1]*P;
    for(int i=0;i<n;i++)p[i]=i;
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)sa[i]=p[i];
    for(int i=1;i<n;i++){
        int l=1,r=min(n-p[i],n-p[i-1]),res=0;
        int l1=p[i],l2=p[i-1];
        // cout<<"s1:"<<s1<<" s2:"<<s2<<endl;
        // printf("l1:%d l2:%d\n",l1,l2);
        while(l<=r){
            int mid=(l+r)>>1;
            ull val1=sum[l1+mid-1]-sum[l1-1]*fac[mid];
            ull val2=sum[l2+mid-1]-sum[l2-1]*fac[mid];
            if(val1==val2)l=mid+1,res=mid;
            else r=mid-1;
            // printf("l:%d r:%d res:%d\n",l,r,res);
        }
        hight[i]=res;
    }
    for(int i=0;i<n;i++)wrt(sa[i],' ');
    puts("");
    for(int i=0;i<n;i++)wrt(hight[i],' ');
    return  0;
}
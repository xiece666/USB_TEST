#include<bits/stdc++.h>
#include<bits/extc++.h>
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
const ll N=30;
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
string s,t,trans[2][N];
int n,ans=11;
__gnu_pbds::gp_hash_table<string,int>dis[2];
queue<string>q[2];
int main(){
    cin>>s>>t;
    while(cin>>trans[0][++n]>>trans[1][n]);
    q[0].push(s),q[1].push(t);
    dis[0][s]=1,dis[1][t]=1;
    for(int _=1,f=0;_<=10;f^=1,_++){
        while(!q[f].empty()){
            string u=q[f].front();
            // printf("_:%d f:%d u:%s dis:%d\n",(_+1)>>1,f,u.c_str(),dis[f][u]-1);
            if(dis[f][u]-1==(_+1)>>1)break;
            q[f].pop();
            for(int i=1;i<=n;i++){
                string nxt,fr=trans[f][i],to=trans[f^1][i];
                for(int j=0;j+fr.length()-1<u.length();j++)
                    if(u.substr(j,fr.length())==fr){
                        nxt=u;
                        nxt.replace(j,fr.length(),to);
                        if(dis[f][nxt])continue;
                        dis[f][nxt]=dis[f][u]+1;
                        q[f].push(nxt);
                    }
            }
        }
    }
    // for(int f=0;f<2;f++)for(auto i=dis[f].begin();i!=dis[f].end();i++)
        // printf("dis[%d][%s]:%d\n",f,(i->fir).c_str(),(i->sec)-1);
    for(auto i=dis[0].begin();i!=dis[0].end();i++)
        if(dis[1][i->fir]>0)
            ans=min(ans,(i->sec)+dis[1][i->fir]-2);
    if(ans==11)puts("NO ANSWER!");
    else wrt(ans);
    return  0;
}
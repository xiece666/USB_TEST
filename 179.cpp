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
const ll N=10,SI=5e5+10;
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
vector<int>U,V,P,_mp[SI];
int ct,tot,ed;
int dx[]={-3,3,-1,1};
int fac[N];
char hs[]={'u','d','l','r'};
string ans[SI];
bitset<N>usd;
bitset<SI>vis;
map<vector<int>,int>mp;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int encode(vector<int>x){
    if(mp.find(x)==mp.end()){
        mp[x]=++tot;
        _mp[tot]=x;
    }
    return mp[x];
}
vector<int>decode(int x){
    return _mp[x];
}
void merge_sort(int L,int R){
    if(L>=R)return;
    int mid=(L+R)>>1;
    merge_sort(L,mid);
    merge_sort(mid+1,R);
    int l=L,r=mid+1;
    queue<int>qq;
    while(l<=mid&&r<=R){
        if(P[l]<P[r])qq.push(P[l++]);
        else ct+=(mid-l+1),qq.push(P[r++]);
    }
    while(l<=mid)qq.push(P[l++]);
    while(r<=R)qq.push(P[r++]);
    for(int i=L;i<=R;qq.pop(),i++)
        P[i]=qq.front();
    // printf("ct:%d [%d,%d]:\n",ct,L,R);
    // for(int i=L;i<=R;i++)wrt(P[i],' ');
    // puts("");
}
int h(vector<int>v){
    int res=0;
    for(int i=0;i<9;i++){
        int r=i/3,c=i%3;
        if(v[i]==9)continue;
        res+=abs(r-(v[i]-1)/3)+abs(c-(v[i]-1)%3);
    }
    return res;
}
void A_star(){
    int st=encode(U);
    q.push({h(U),st});
    while(!q.empty()){
        int u=q.top().sec;
        int d=q.top().fir;
        q.pop();
        if(u==ed)return;
        if(vis[u])continue;
        vis[u]=1;
        vector<int>cur=decode(u);
        d-=h(cur);
        int pos=-1;
        for(int i=0;i<9&&pos==-1;i++)
            if(cur[i]==9)pos=i;
        // printf("come :");
        // for(int i:cur)wrt(i,' ');
        // puts("");
        // assert(pos!=-1);
        // printf("pos:%d\n",pos);
        for(int i=0;i<4;i++){
            int np=pos+dx[i];
            if((np/3!=pos/3&&np%3!=pos%3)||np<0||np>8)
                continue;
            swap(cur[pos],cur[np]);
            int tmp=encode(cur);
            // printf("    ->");
            // for(int j:cur)wrt(j,' ');
            // puts("");
            if(vis[tmp]){
                swap(cur[pos],cur[np]);
                continue;
            }
            // puts("    ok");
            ans[tmp]=ans[u]+hs[i];
            q.push({d+1+h(cur),tmp});
            swap(cur[pos],cur[np]);
        }
        // puts("");
    }
}
int main(){
    fac[0]=1;
    for(int i=1;i<=9;i++)fac[i]=fac[i-1]*i;
    int _p=0;
    for(int i=0;i<9;i++){
        char c=getchar();getchar();
        if(isdigit(c))U.pbk(c^48);
        else U.pbk(9),_p=i;
        V.pbk(i+1);
    }
    ed=encode(V);
    P=U,P.erase(_p+P.begin());
    // for(int i:U)wrt(i,' ');
    // puts("");
    merge_sort(0,7);
    // printf("\nct:%d\n",ct);
    if(ct&1)puts("unsolvable");
    else{
        A_star();
        puts(ans[1].c_str());
    }
    return  0;
}
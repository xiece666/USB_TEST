#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define p u/v
#define fir(i,a,b) for(ll i=a;i<=b;i++)
const int N=1e7+10;
queue<ll> p1,p2,p3;
ll n,m,q,u,v,t,a[N],data;
int cmp(int a,int b){
    return a>b;
}
int calc(ll t){
    ll x=-1,a=-1,b=-1,c=-1;
    if (!p1.empty())
        a=p1.front()+t*q;
    if (!p2.empty())
        b=p2.front()+t*q;
    if (!p3.empty())
        c=p3.front()+t*q;
    x=max(a,max(b,c));
    if (x==a)
        p1.pop();
    else
    if (x==b)
        p2.pop();
    else
    if (x==c)
        p3.pop();
    return x;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>q>>u>>v>>t;
    fir(i,1,n)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    fir(i,1,n)
        p1.push(a[i]);
    fir(i,1,m)
    {
        ll x=calc(i-1);
        if (!(i%t))
            cout<<x<<" ";
        ll now1=x*p;
        ll now2=x-now1;
        p2.push(now1-i*q);
        p3.push(now2-i*q);
    }
    cout<<endl;
    fir(i,1,(n+m))
    {
        ll x=calc(m);
        if (i%t==0)
            cout<<x<<" ";
    }
}
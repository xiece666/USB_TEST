#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize (2)
#pragma G++ optimize (2)
#define fir(i,a,b) for (int i=a;i<=b;i++)
#define pii pair<int,int>
const int N=200100;
int n,m,sc[N],lan;
unordered_map<int,int> p,q;
pii mv[N],mv_ans[N];
int cmp(pii a,pii b)
{
    if (a.first==b.first)
        return a.second>b.second;
    return a.first>b.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    fir(i,1,n)
    {
        cin>>sc[i];
        if (p[sc[i]]==0)
        {
            p[sc[i]]=(++lan);
            sc[i]=lan;
        }
        else
            sc[i]=p[sc[i]];
        q[sc[i]]++;
    }
    cin>>m;
    fir(i,1,m)
    {
        cin>>mv[i].first;
        mv[i].first=q[p[mv[i].first]];
    }
    fir(i,1,m)
    {
        cin>>mv[i].second;
        mv[i].second=q[p[mv[i].second]];
        mv_ans[i]=mv[i];
    }
    sort(mv+1,mv+1+m,cmp);
    fir(i,1,m)
        if (mv_ans[i]==mv[1])
        {
            cout<<i;
            break;
        }
    return 0;
}
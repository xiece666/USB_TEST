#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
const int N = 100010;

int n,m,l[N],a[N],r[N];
bool st[N];
priority_queue<PII,vector<PII>,greater<PII> > heap;

void remove(int x)
{
    l[r[x]]=l[x];
    r[l[x]]=r[x];

    st[x]=1;
}

int main()
{
    cin>>n>>m;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        int xi;
        scanf("%d",&xi);
        if(!xi)continue;

        if(!k ||(long long) a[k] * xi < 0 )a[++k]+=xi;
        else a[k]+=xi;
    }
    // for(int i=1;i<=k;i++)printf("%d ",a[i]);
    // puts("");
    int res=0,cnt=0;
    for(int i=1;i<=k;i++)
    {
        l[i]=i-1;
        r[i]=i+1;
        heap.push( {abs(a[i]), i });
        if(a[i]>0)res+=a[i],cnt++;
    }

    while( cnt>m )
    {
        PII u=heap.top() ;
        heap.pop() ;

        if(st[u.second])continue;

        if(a[u.second]>0 || (l[u.second]!=0 && r[u.second]!=k+1) )
        {
            // printf("%d\n",u.first);
            res-=u.first;
            a[u.second]+=a[ l[u.second] ] + a[ r[u.second] ];
            heap.push( { abs(a[u.second]) , u.second } );
            remove(r[u.second]);
            remove(l[u.second]);   
            cnt--;
        }

    }

    cout<<res;
}
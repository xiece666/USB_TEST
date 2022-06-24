#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int n,cnt,t,m,p,ans;
queue<PII> waits; 
set<PII> runs;     
priority_queue<PII, vector<PII>, greater<PII>> endts;    
bool give(int t, int m, int p)
{
    for(auto it=runs.begin();it!=runs.end();it++)
    {
        auto jt=it;
        jt++;
        if (jt!=runs.end())
        {
            int start=it->first+it->second;
            if (m<=jt->first-start)
            {
                runs.insert({start,m});
                endts.push({t+p,start});
                return true;
            }
        }
    }
    return false;
}
void finish(int t)
{
    while (endts.size() && endts.top().first<=t)
    {
        int f=endts.top().first;
        while (endts.size() && endts.top().first==f)
        {
            auto top=endts.top();
            endts.pop();
            auto it=runs.lower_bound({top.second, 0});
            runs.erase(it);
        }
        ans=f;
        while (waits.size())
        {
            auto front=waits.front();
            if (give(f,front.first,front.second))
                waits.pop();
            else
                break;
        }
    }
}
void init()
{
    ios::sync_with_stdio(false);
    cin>>n;
    runs.insert({-1, 1}),runs.insert({n, 1});
    while (cin>>t>>m>>p,t || m || p)
    {
        finish(t);
        if (!give(t,m,p))
        {
            waits.push({m,p});
            cnt++;
        }
    }
    finish(2e9);
    cout<<ans<<endl<<cnt<<endl;
}
int main()
{
    init();
    return 0;
}
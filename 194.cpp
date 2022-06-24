#include<bits/stdc++.h>
using namespace std;
int n,limit,arr[11][11],flag,Vis[11],vis[11][11];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int Get()
{
    int res=0;
    memset(Vis,0,sizeof(Vis));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vis[i][j]!=1&&!Vis[arr[i][j]])
            {
                Vis[arr[i][j]]=1;
                res++;
            }
        }
    }
    return res;
}
void paint(int x,int y,int c)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int X=x+dx[i],Y=y+dy[i];
        if(X>n||X<1||Y>n||Y<1)
            continue;
        if(vis[X][Y]==1)
            continue;
        if(arr[X][Y]!=c)
        {
            vis[X][Y]=2;
            continue;
        }
        paint(X,Y,c);
    }
}
void IDAstar(int D,int las)
{
    if(flag)
        return;
    int pr=Get();
    if(!pr)
    {
        cout<<D<<endl;
        flag=1;
        return;
    }
    if(D>limit||D+pr>limit)
        return;
    for(int c=0;c<=5;c++)
    {
        int tmp[10][10];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                tmp[i][j]=vis[i][j];
        int FLG=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(vis[i][j]==2&&arr[i][j]==c)
                {
                    paint(i,j,c);
                    FLG=1;
                }
            }
        }
        if(!FLG)
            continue;
        IDAstar(D+1,c);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                vis[i][j]=tmp[i][j];
    }
}
int main()
{
    while(cin>>n&&n)
    {
        flag=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                cin>>arr[i][j];
            }
        if(!Get())
        {
            cout<<0<<endl;
            continue;
        }
        paint(1,1,arr[1][1]);
        for(limit=Get();!flag;limit++)
            IDAstar(0,10);
    }
}
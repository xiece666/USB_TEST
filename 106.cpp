#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int main(){
    int T;                                                      
    scanf("%d",&T);
    while(T--){
        int id, n;
        scanf("%d%d",&id,&n);
        printf("%d %d\n",id,n+1>>1);
        priority_queue<int>down;                               
        priority_queue<int,vector<int>,greater<int>>up;
        int cnt=0;                                            
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d", &x);
            if (down.empty() || x <= down.top()) down.push(x);  
            else up.push(x);
            if (down.size() > up.size() + 1) up.push(down.top()), down.pop();   
            if (up.size() > down.size()) down.push(up.top()), up.pop();         
            if (i&1){
                printf("%d ",down.top());
                if(++cnt%10==0)puts("");
            }
        }
        if(cnt%10)puts("");                                 
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 3e5 + 10;

int n;
LL S, sc[N], st[N], f[N], que[N];

int main()
{
    scanf("%d%lld", &n, &S);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%lld%lld", &st[i], &sc[i]);
        st[i] += st[i - 1], sc[i] += sc[i - 1];
    }
    int tt = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int l = 0, r = tt;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (f[que[mid + 1]] - f[que[mid]] > 
               (S + st[i]) * (sc[que[mid + 1]] - sc[que[mid]])) r = mid;
            else l = mid + 1;
        }
        f[i] = f[que[r]] + S * (sc[n] - sc[que[r]]) + st[i] * (sc[i] - sc[que[r]]);
        while (tt && (double)(f[que[tt]] - f[que[tt - 1]]) * (sc[i] - sc[que[tt]]) >= 
                     (double)(f[i] - f[que[tt]]) * (sc[que[tt]] - sc[que[tt - 1]]))
            tt -- ;
        que[ ++ tt] = i;
    }
    printf("%lld\n", f[n]);
    return 0;
}
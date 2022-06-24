#include <bits/stdc++.h>
#define For(i, a, b) for(int i = (a); i <= (b); ++i)
#define Rof(i, a, b) for(int i = (a); i >= (b); --i)
#define LL long long
#define MaxN 100002
#define INF 0x3f3f3f3f
using namespace std;
int N, M, C, Len, GPS[MaxN], A[MaxN], l, r , S[325][MaxN], P[325][325], Vis[MaxN], x;
void Init() {
    Len = sqrt(N); For(i, 1, N) GPS[i] = (i - 1) / Len + 1;
    For(i, 1, GPS[N]) {
        For(j, 1, C) S[i][j] = S[i - 1][j];
        For(j, (i - 1) * Len + 1, min(N, i * Len)) S[i][A[j]]++;
    }
    Rof(i, GPS[N], 1) For(j, i, GPS[N]) {
        if(i == j) {
            For(k, (i - 1) * Len + 1, min(N, i * Len))
                if((S[i][A[k]] - S[i - 1][A[k]]) && !(S[i][A[k]] - S[i - 1][A[k]] & 1) && !Vis[A[k]])
                    ++P[i][j], Vis[A[k]] = 1;
            For(k, (i - 1) * Len + 1, min(N, i * Len)) Vis[A[k]] = 0;
            continue;
        }
        P[i][j] = P[i][j - 1];
        For(k, (j - 1) * Len + 1, min(N, j * Len)) ++Vis[A[k]];
        For(k, (j - 1) * Len + 1, min(N, j * Len)) if(Vis[A[k]]) {
            if((Vis[A[k]] & 1) && (S[j - 1][A[k]] - S[i - 1][A[k]] & 1)) ++P[i][j];
            if(!(Vis[A[k]] & 1) && !(S[j - 1][A[k]] - S[i - 1][A[k]])) ++P[i][j];
            if((S[j - 1][A[k]] - S[i - 1][A[k]]) && !(S[j - 1][A[k]] - S[i - 1][A[k]] & 1))
                if(Vis[A[k]] & 1) --P[i][j];
            Vis[A[k]] = 0;
        }
    }
}
int Query(int l, int r) {
    int Ret = 0;
    if(GPS[r] - GPS[l] <= 1) {
        For(k, l, r) ++Vis[A[k]];
        For(k, l, r) if(Vis[A[k]]) {
            Ret += !(Vis[A[k]] & 1);
            Vis[A[k]] = 0;
        }
        return Ret;
    }
    int i = GPS[l] + 1, j = GPS[r];
    Ret = P[GPS[l] + 1][GPS[r] - 1];
    For(k, l, GPS[l] * Len) ++Vis[A[k]];
    For(k, (GPS[r] - 1) * Len + 1, r) ++Vis[A[k]];
    For(k, l, GPS[l] * Len) if(Vis[A[k]]) {
        if((Vis[A[k]] & 1) && (S[j - 1][A[k]] - S[i - 1][A[k]] & 1)) ++Ret;
        if(!(Vis[A[k]] & 1) && !(S[j - 1][A[k]] - S[i - 1][A[k]])) ++Ret;
            if((S[j - 1][A[k]] - S[i - 1][A[k]]) && !(S[j - 1][A[k]] - S[i - 1][A[k]] & 1))
            if(Vis[A[k]] & 1) --Ret;
        Vis[A[k]] = 0;
    }
    For(k, (GPS[r] - 1) * Len + 1, r) if(Vis[A[k]]) {
        if((Vis[A[k]] & 1) && (S[j - 1][A[k]] - S[i - 1][A[k]] & 1)) ++Ret;
        if(!(Vis[A[k]] & 1) && !(S[j - 1][A[k]] - S[i - 1][A[k]])) ++Ret;
            if((S[j - 1][A[k]] - S[i - 1][A[k]]) && !(S[j - 1][A[k]] - S[i - 1][A[k]] & 1))
            if(Vis[A[k]] & 1) --Ret;
        Vis[A[k]] = 0;
    }
    return Ret;
}
int main() {
    scanf("%d%d%d", &N, &C, &M); For(i, 1, N) scanf("%d", &A[i]); Init();
    while(M--) {
        scanf("%d%d", &l, &r);
        l = (l + x) % N + 1, r = (r + x) % N + 1;
        if(l > r) swap(l, r);
        printf("%d\n", x = Query(l, r));
    }
    return 0;
}
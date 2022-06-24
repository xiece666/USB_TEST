#include <bits/stdc++.h>
using namespace std;

int a[1005], f[1005];
bool v[1005];

int main() {
    string s; int n, k = 1; cin >> n; stack<int> x, y; x.push(1e9); y.push(1e9);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n, j = a[i] - 1; i; v[a[i]] = 1, j = a[--i] - 1) {
        if (!v[j]) f[j + 1] = 0;
        else {
            bool g = 0; f[j + 1] = f[j];
            for (int k = i + 1; a[k] != j; ++k) f[j + 1] = max(f[j + 1], max(f[a[k]], a[k]));
        }
    }
    for (int i = 1, c = a[1]; i <= n; c = a[++i]) {
        while (x.top() == k) ++k, s += 'b', x.pop();
        if (x.top() > c && f[c] < y.top()) s += 'a', x.push(c);
        else if (y.top() == k) s += 'd', ++k, y.pop(), --i;
        else {
            if (y.top() > c) s += 'c', y.push(c);
            else { s = ""; break; }
        }
    }
    if (s.empty()) return cout << 0, 0;
    while (x.top() == k || y.top() == k)
        if (x.top() == k) ++k, s += 'b', x.pop();
        else ++k, s += 'd', y.pop();
    for(int i=0;i<s.length();i++)for(int j=i+1;j<s.length();j++)
        if((s[j]=='a'&&s[j-1]=='d')||(s[j]=='b'&&s[j-1]=='c'))swap(s[j],s[j-1]);
    for (auto c : s) cout << c << ' ';
    return 0;
}
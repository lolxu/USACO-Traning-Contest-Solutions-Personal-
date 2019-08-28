/*
 ID: lolxuda1
 TASK: shell
 LANG: C++
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

const int maxn = 2333;

int x[maxn], y[maxn], z[maxn];

int main() {
    int n;
    
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
        x[i] -= 1;
        y[i] -= 1;
        z[i] -= 1;
    }
    int a[3], ans = 0;
    for (int st = 0; st < 3; ++st) {
        memset(a, 0, sizeof(a));
        a[st] = 1;
        int guess = 0;
        for (int i = 1; i <= n; ++i) {
            swap(a[x[i]], a[y[i]]);
            guess += a[z[i]];
        }
        ans = max(ans, guess);
    }
    cout << ans << endl;
    
    return 0;
}

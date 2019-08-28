/*
 ID: lolxuda1
 TASK: planting
 LANG: C++
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 100070;
int f[MAXN];
int N;

int main() {
    
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    
    int x, y;
    scanf("%d", &N);
    memset(f, 0, sizeof(f));
    for (int i = 0; i < N-1; ++i) {
        scanf("%d%d", &x, &y);
        f[x]++;
        f[y]++;
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans = max(ans, f[i] + 1);
    }
    cout << ans << endl;
    return 0;
}

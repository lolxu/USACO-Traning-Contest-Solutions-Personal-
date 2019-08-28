/*
 ID: lolxuda1
 TASK: sleepy
 LANG: C++
 */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 2333;
int a[maxn];

int getAns(int l, int r) {
    if (l >= r) return 0;
    int mx = -1, mx_id = -1;
    for (int i = l; i <= r; ++i) {
        if (a[i] > mx) {
            mx = a[i];
            mx_id = i;
        }
    }
    if (mx_id == r) {
        return getAns(l, r - 1);
    } else {
        int val = mx_id - l + 1;
        return val + getAns(mx_id + 1, r);
    }
}

int main() {
    int n;
    
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cout << getAns(1, n) << endl;
    return 0;
}

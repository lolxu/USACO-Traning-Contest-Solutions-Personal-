/*
 ID: lolxuda1
 TASK: guess
 LANG: C++
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int n;

int getAns(const vector<string>& a, const vector<string>& b) {
    set<string> s(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (s.find(b[i]) != s.end()) {
            ans += 1;
        }
    }
    return ans;
}

int main() {
    
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    
    vector<vector<string> > vec;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        int k;
        cin >> k;
        vec.push_back(vector<string>());
        for (int j = 0; j < k; ++j) {
            string p_s;
            cin >> p_s;
            vec[i].push_back(p_s);
        }
        sort(vec[i].begin(), vec[i].end());
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, getAns(vec[i], vec[j]) + 1);
        }
    }
    cout << ans << endl;
    return 0;
}

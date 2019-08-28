/*
 ID: lolxuda1
 TASK: mountains
 LANG: C++
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> doit(vector<pair<int, int> >ps_) {
    sort(ps_.begin(), ps_.end());
    vector<pair<int, int> > ps;
    for (int i = 0; i < ps_.size(); ++i) {
        if (i + 1 < ps_.size() && ps_[i].first == ps_[i + 1].first) {
            continue;
        }
        ps.push_back(ps_[i]);
    }
    vector<int> res(ps.size(), 0);
    int ans = 0;
    stack<pair<int, int> > last_vec;
    for (int i = 0; i < ps.size(); ++i) {
        int x = ps[i].first, y = ps[i].second;
        while (last_vec.size() > 0 && last_vec.top().second <= y) {
            last_vec.pop();
        }
        if (last_vec.size() == 0) {
            last_vec.push(ps[i]);
            ans += 1;
            res[i] = 1;
        } else {
            int x_ = last_vec.top().first, y_ =last_vec.top().second;
            if (x - x_ > y_ - y) {
                ans += 1;
                last_vec.push(ps[i]);
                res[i] = 1;
            }
        }
    }
    return res;
}

int main() {
    
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    
    int n, x, y;
    scanf("%d", &n);
    vector<pair<int, int> > ps_, ps;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        ps_.push_back(make_pair(x, y));
    }
    vector<int> res1 = doit(ps_);
    for (int i = 0; i < n; ++i) {
        ps_[i].first = -ps_[i].first;
    }
    vector<int> res2 = doit(ps_);
    reverse(res2.begin(), res2.end());
    int ans = 0;
    for (int i = 0; i < res1.size(); ++i) {
        if (res1[i] == 1 && res2[i] == 1) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
 ID: lolxuda1
 TASK: perimeter
 LANG: C++
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1111;
char a[maxn][maxn];
int visited[maxn][maxn];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;

void calc(int x, int y, int& area, int& p) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    vector<pair<int,int> > ps;
    while (!q.empty()) {
        ps.push_back(q.front());
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x_ = x + dx[i], y_ = y + dy[i];
            if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) {
                continue;
            }
            if (visited[x_][y_] || a[x_][y_] == '.') continue;
            visited[x_][y_] = true;
            q.push(make_pair(x_, y_));
        }
    }
    area = static_cast<int>(ps.size());
    p = 0;
    for (int i = 0; i < area; ++i) {
        int x = ps[i].first, y = ps[i].second;
        for (int d = 0; d < 4; ++d) {
            int x_ = x + dx[d], y_ = y + dy[d];
            if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) {
                p++;
            } else {
                if (a[x_][y_] == '.') p++;
            }
        }
    }
}


int main() {
    
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    
    scanf("%d\n", &n);
    m = n;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    int ans_area = 0, ans_p = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#' && !visited[i][j]) {
                int area = 0, p = 0;
                calc(i, j, area, p);
                if (area > ans_area) {
                    ans_area = area;
                    ans_p = p;
                } else if (area == ans_area) {
                    if (p < ans_p) {
                        ans_p = p;
                    }
                }
            }
        }
    }
    cout << ans_area << ' ' << ans_p << endl;
    return 0;
}

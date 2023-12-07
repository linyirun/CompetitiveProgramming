#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

#define int ll
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INF = 1e15;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(4)));
    queue<pair<pii, int>> q;
    // {{x, y}, direction}
    for (int i = 0; i < 4; i++) {
        q.push({{1, 1}, i});
    }

    // if next block is wall, push all 4 directions
    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        int x = p.first.first, y = p.first.second, dir = p.second;
        if (vis[x][y][dir]) continue;
        vis[x][y][dir] = true;

        int nxt_x = x + dx[dir], nxt_y = y + dy[dir];
        if (grid[nxt_x][nxt_y] == '#') {
            for (int i = 0; i < 4; i++) {
                q.push({{x, y}, i});
            }
            continue;
        } else if (grid[nxt_x][nxt_y] == '.') {
            q.push({{nxt_x, nxt_y}, dir});
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j][0] || vis[i][j][1] || vis[i][j][2] || vis[i][j][3]) cnt++;
        }
    }
    cout << cnt << '\n';
}

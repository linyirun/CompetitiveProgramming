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

vector<vector<char>> grid;
int h, w;
bool is_safe(int row, int col) {
    return 0 <= row && row < h && 0 <= col && col < w && grid[row][col] != '#';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> h >> w >> t;

    grid = vector<vector<char>>(h, vector<char>(w));
    vector<pii> pos_important;
    pii start = {-1, -1}, end = {-1, -1};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') start = {i, j};
            if (grid[i][j] == 'G') end = {i, j};
            if (grid[i][j] == 'o') pos_important.push_back({i, j});
        }
    }

    pos_important.push_back(end);
    pos_important.insert(pos_important.begin(), start);

    // Find shortest path between these important squares
    vector<vector<int>> shortest_path(pos_important.size(), vector<int>(pos_important.size(), INF));

    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    for (int curr = 0; curr < pos_important.size(); curr++) {
        int start_x = pos_important[curr].first, start_y = pos_important[curr].second;
        vector<vector<int>> dist(h, vector<int>(w, INF));

        dist[start_x][start_y] = 0;
        queue<pii> q;
        q.push({start_x, start_y});
        while (!q.empty()) {
            int curr_x = q.front().first, curr_y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int dest_x = curr_x + dx[i], dest_y = curr_y + dy[i];
                if (is_safe(dest_x, dest_y) && dist[dest_x][dest_y] > dist[curr_x][curr_y] + 1) {
                    dist[dest_x][dest_y] = dist[curr_x][curr_y] + 1;
                    q.push({dest_x, dest_y});
                }
            }
        }

        for (int i = 0; i < pos_important.size(); i++) {
            int dest_x = pos_important[i].first, dest_y = pos_important[i].second;
            shortest_path[curr][i] = shortest_path[i][curr] = dist[dest_x][dest_y];
        }
    }

    int n = pos_important.size();
    n--;
    int MX_MASK = (1 << n);
    vector<vector<int>> dp(n, vector<int>(MX_MASK, INF));

    dp[0][1] = 0;
    int best = -1;
    for (int mask = 0; mask < MX_MASK; mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            for (int dest = 0; dest < n; dest++) {
                if (!(mask & (1 << dest))) {
                    dp[dest][mask | (1 << dest)] = min(dp[dest][mask | (1 << dest)], dp[i][mask] + shortest_path[i][dest]);
                }
            }

            // What would be the best cost if you just went to the end from now
            if (dp[i][mask] + shortest_path[i][n] <= t) {
                best = max(best, (int) __builtin_popcount(mask) - 1);
            }
        }
    }

    cout << best;

}

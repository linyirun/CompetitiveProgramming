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

vector<vector<int>> grid(3, vector<int>(3));

ld recur(vector<vector<int>> &curr, vector<vector<bool>> &vis, int left) {
    // Check if it's valid
    for (vector<int> &v : curr) {
        if (v.size() >= 3 && v[0] == v[1] && v[1] != v[2]) return 0;
    }
    if (left == 0) return 1;
    // Pick one
    ld curr_prob = 0;
    ld prob = (ld) 1 / left;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (vis[i][j]) continue;
//            vector<vector<int>> cpy = curr;
//            vector<vector<bool>> cpy_vis = vis;

            vector<int> to_pop;
            vis[i][j] = true;
            curr[i].push_back(grid[i][j]);
            curr[3 + j].push_back(grid[i][j]);
            to_pop.push_back(i);
            to_pop.push_back(3 + j);
            if (i == j) {
                curr[6].push_back(grid[i][j]);
                to_pop.push_back(6);
            }

            if ((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 0)) {
                curr[7].push_back(grid[i][j]);
                to_pop.push_back(7);
            }
            curr_prob += prob * recur(curr, vis, left - 1);

            for (int k : to_pop) curr[k].pop_back();
            vis[i][j] = false;
        }
    }
    return curr_prob;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<bool>> vis(3, vector<bool>(3));
    vector<vector<int>> curr(8);
    cout.precision(10);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> grid[i][j];
    }
    cout << fixed << recur(curr, vis, 9) << '\n';
}

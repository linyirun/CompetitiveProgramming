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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> grid(n, vector<bool>(m));
    vector<vector<int>> rows(n), cols(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            grid[i][j] = x;
            if (x) {
                rows[i].push_back(j);
                cols[j].push_back(i);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) continue;

            // check right
            if (std::lower_bound(rows[i].begin(), rows[i].end(), j) != rows[i].end()) {
//                cout << i << ", " << j << " 1\n";
                cnt++;
            }
            // check left
            if (std::lower_bound(rows[i].begin(), rows[i].end(), j) != rows[i].begin()) {
//                cout << i << ", " << j << " 2\n";
                cnt++;
            }

            if (std::lower_bound(cols[j].begin(), cols[j].end(), i) != cols[j].end()) {
//                cout << i << ", " << j << " 3\n";
                cnt++;
            }
            // check down
            if (std::lower_bound(cols[j].begin(), cols[j].end(), i) != cols[j].begin()) {
//                cout << i << ", " << j << " 4\n";
                cnt++;
            }

        }
    }
    cout << cnt << '\n';
}

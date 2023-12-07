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

int mex(int m, vector<int> &v) {
    vector<bool> vis(m + 1);

    for (int i : v) vis[i] = true;
    for (int i = 0; i <= m; i++) {
        if (!vis[i]) return i;
    }
    return m;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
//        vector<set<int>> untaken(n);
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                untaken[j].insert(i);
//            }
//        }
        for (int curr = 0; curr < m; curr++) {
            for (int i = 0; i < min(n, m - 1) - curr && i + curr < n; i++) {
                a[i + curr][i] = curr;
            }
        }

        for (int i = 0; i < min(n, m - 1); i++) {
            int curr_elem = m - 1;
            for (int j = i + 1; j < m; j++) {
                a[i][j] = curr_elem--;
            }
        }
        for (int i = min(n, m - 1); i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = a[0][j]; // waste rows
            }
        }

        vector<int> curr(m);
        for (int col = 0; col < m; col++) {
            vector<int> curr_col;
            for (int row = 0; row < n; row++) {
                curr_col.push_back(a[row][col]);
            }
            curr[col] = mex(m, curr_col);
        }

        cout << mex(m, curr) << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
}

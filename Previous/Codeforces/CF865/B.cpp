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

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                grid[i][0] = 2 * n - i;
                grid[i][1] = i + 1;
            } else {
                grid[i][0] = i + 1;
                grid[i][1] = 2 * n - i;
            }
        }

        swap(grid[n - 1][1], grid[1][1]);
        for (int row = 0; row < 2; row++) {
            for (int i = 0; i < n; i++) {
                cout << grid[i][row] << ' ';
            }
            cout << '\n';
        }
    }
}

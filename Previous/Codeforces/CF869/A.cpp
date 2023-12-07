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
        int n, k;
        cin >> n >> k;

        vector<vector<char>> grid(n, vector<char>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> grid[i][j];
        }
        vector<bool> can(n, true);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (grid[i][j] != grid[0][j]) can[i] = false;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += can[i];
        cout << cnt << '\n';
    }
}

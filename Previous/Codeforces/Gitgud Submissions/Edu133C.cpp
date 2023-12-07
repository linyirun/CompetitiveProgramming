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

        vector<vector<int>> a(2, vector<int>(n + 1));
        vector<vector<int>> waited(2, vector<int>(n + 1));
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < n; col++) cin >> a[row][col];
        }

        for (int col = n - 1; col >= 0; col--) {
            for (int row = 0; row < 2; row++) {
                if (col == n) {
                    waited[row][col] = max(a[row][col], a[!row][col]);
                } else {
                    waited[row][col] = max({a[row][col], a[row][col + 1], waited[row][col + 1] - 1, a[!row][col] - (n - col - 1) * 2});
                }
            }
        }

        int best = LLONG_MAX;
        int curr_row = 0;
        int curr_time = 0;
        for (int col = 0; col < n; col++) {
            int walk_time = (n - col) * 2 - 1;
            int wait = max(0LL, waited[curr_row][col] - curr_time);
            best = min(best, curr_time + wait + walk_time);

            curr_time = max(curr_time + 1, a[!curr_row][col] + 1);
            curr_time = max(curr_time + 1, a[!curr_row][col + 1] + 1);
            curr_row = !curr_row;
        }
        cout << best << '\n';

    }
}

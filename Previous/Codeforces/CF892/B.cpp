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

        vector<vector<int>> a(n);
        int mn = INT_MAX, mn_idx = -1;
        int curr_mn2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            a[i].resize(m);
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                curr_mn2 = min(curr_mn2, a[i][j]);
            }
            sort(a[i].begin(), a[i].end());
            int curr_mn = a[i][1];
            if (curr_mn < mn) {
                mn_idx = i;
                mn = curr_mn;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i == mn_idx) sum += curr_mn2;
            else sum += a[i][1];
        }
        cout << sum << '\n';

    }
}

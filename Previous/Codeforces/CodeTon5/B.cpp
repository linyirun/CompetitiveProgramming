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
        int n, x;
        cin >> n >> x;

        vector<vector<int>> a(3, vector<int>(n));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int curr = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                if ((a[i][j] | x) != x) break;
                curr |= a[i][j];
            }
        }
        if (curr == x) cout << "YES\n";
        else cout << "NO\n";
    }
}

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

    freopen("a.txt", "r", stdin);
    freopen("a_out.txt", "w", stdout);

    int tt;
    cin >> tt;

    for (int it = 1; it <= tt; it++) {
        int n;
        cin >> n;

        vector<ld> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        ld best = a[n - 2] + (a[n - 1] - a[n - 2]) / 2 - (a[0] + (a[1] - a[0]) / 2);
        if (n == 5) {
            best = max(a[n - 3] + (a[n - 1] - a[n - 3]) / 2 - (a[0] + (a[1] - a[0]) / 2), a[n - 2] + (a[n - 1] - a[n - 2]) / 2 - (a[0] + (a[2] - a[0]) / 2));
        }
        cout.precision(10);
        cout << "Case #" << it << ": " << fixed << best << '\n';
    }
}

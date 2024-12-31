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

    cout.precision(10);

    int tt;
    cin >> tt;

    for (int iteration = 0; iteration < tt; iteration++) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

        ld total_mn = 0, total_mx = 1e9;


        for (int i = 0; i < n; i++) {
            ld a_time = ((ld) a[i]) / (i + 1);
            ld b_time = ((ld) b[i]) / (i + 1);

            // Get to pos b before time i
            total_mn = max(b_time, total_mn);
            // Don't pass b before i time
            total_mx = min(a_time, total_mx);
        }

        cout << "Case #" << iteration + 1 << ": ";
//        cout << total_mn << ", " << total_mx << '\n';
        if (total_mx < total_mn) {
            cout << "-1\n";
        } else {
            cout << fixed << total_mn << '\n';
        }
    }
}

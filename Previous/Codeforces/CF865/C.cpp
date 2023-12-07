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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i < n - 1; i++) {
            if (a[i - 1] > a[i]) {
                a[i + 1] += a[i - 1] - a[i];
                a[i] += a[i - 1] - a[i];
            }
        }

        for (int i = n - 1; i >= 2; i--) {
            if (a[i - 1] > a[i]) {
                a[i - 2] -= a[i - 1] - a[i];
                a[i - 1] -= a[i - 1] - a[i];
            }
        }

        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());
        if (a == sorted) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}

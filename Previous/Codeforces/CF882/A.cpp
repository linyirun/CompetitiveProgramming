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

        vector<int> a(n);
        int total = 0;
        vector<int> diff(n - 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i) {
                diff[i - 1] = abs(a[i] - a[i - 1]);
                total += abs(a[i] - a[i - 1]);
            }
        }

        sort(diff.begin(), diff.end(), greater<int>());
        for (int i = 0; i < k - 1; i++) {
            total -= diff[i];
        }
        cout << total << '\n';
    }
}

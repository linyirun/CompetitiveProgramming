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
        vector<int> a(n), b(n);
        int sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum_a += a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sum_b += b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        cout << min(sum_a + n * b[0], sum_b + n * a[0]) << '\n';
    }
}

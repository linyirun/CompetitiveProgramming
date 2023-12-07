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

        vector<int> a(n, -1000);
        int i = 0;
        for (; i < n; i++) {
            if ((i + 1) * (i + 2) / 2 > k) {
                break;
            }
            a[i] = 2 * (i + 1);
        }
        k -= i * (i + 1) / 2;

        int need_index = k - 1;
        if (need_index >= 0) {
            int sum = 0;
            for (int j = need_index; j < i; j++) {
                sum += a[j];
            }
            a[i] = -sum + 1;
        }
        for (int j : a) cout << j << ' ';
        cout << '\n';
    }
}

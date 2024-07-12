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

        vector<int> a(n), suff(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            suff[i] = a[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            suff[i] += suff[i + 1];
        }

        int best = suff[0];
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += a[i];
            best = max(best, abs(curr) + suff[i + 1]);
        }

        cout << best << '\n';

    }
}

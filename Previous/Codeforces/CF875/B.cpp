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
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        map<int, int> mx_chain_a, mx_chain_b;

        int chain_a = 1, chain_b = 1;
        for (int i = 1; i <= n; i++) {
            if (i != n && a[i] == a[i - 1]) chain_a++;
            else {
                mx_chain_a[a[i - 1]] = max(mx_chain_a[a[i - 1]], chain_a);
                chain_a = 1;
            }

            if (i != n && b[i] == b[i - 1]) {
                chain_b++;
            } else {
                mx_chain_b[b[i - 1]] = max(mx_chain_b[b[i - 1]], chain_b);
                chain_b = 1;
            }
        }

        int best = 1;
        for (auto p : mx_chain_a) best = max(best, p.second + mx_chain_b[p.first]);
        for (auto p : mx_chain_b) best = max(best, p.second + mx_chain_a[p.first]);
        cout << best << '\n';
    }
}

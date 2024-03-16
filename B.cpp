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

    int n, t;
    cin >> n >> t;

    int curr_best = INT_MAX, idx = -1;
    for (int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;

        int earliest = max(s, s + (t - s + d - 1) / d * d);
        if (earliest < curr_best) {
            curr_best = earliest;
            idx = i + 1;
        }
    }
    cout << idx << '\n';
}

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

    int n, m, k;
    cin >> n >> m >> k;

    int l = 1, r = n * m;
    int ans = 1;

    while (l <= r) {
        int mp = (l + r) / 2;

        int cnt_leq = 0;
        for (int i = 1; i <= min(n, mp); i++) {
            cnt_leq += min(m, mp / i);
        }

        if (cnt_leq >= k) {
            ans = mp;
            r = mp - 1;
        } else l = mp + 1;
    }
    cout << ans << '\n';

}

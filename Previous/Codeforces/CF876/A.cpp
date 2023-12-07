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
        int l = 1, r = n;
        int cnt = 2;
        while (l < r) {
            l += k;
            if (r <= l) break;
            cnt++;
            r -= k;
            if (r <= l) break;
            cnt++;
        }
        cout << cnt << '\n';
    }
}

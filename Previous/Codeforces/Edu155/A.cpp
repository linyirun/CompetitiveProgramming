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

        bool can = true;
        int w, e;
        cin >> w >> e;

        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            if (w <= x && y >= e) can = false;
        }
        if (!can) cout << "-1\n";
        else cout << w << '\n';
    }
}

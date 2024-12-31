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

    int n;
    cin >> n;

    cout.precision(10);
    ld mn = 1e15;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2 == x1) continue;

        ld m = (ld) (y2 - y1) / (x2 - x1);

        ld intersect = (ld) y1 - m * x1;

        if (min(y1, y2) <= intersect && intersect <= max(y1, y2) && min(x1, x2) < 0 && max(x1, x2) > 0 && intersect > 0) {
            // On line segment
            mn = min(mn, intersect);
        }
    }

    if (mn >= 1e14) {
        cout << "-1.0\n";
    } else {
        cout << fixed << mn << '\n';
    }
}

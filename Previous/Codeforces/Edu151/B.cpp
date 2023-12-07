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
        int xa, ya, xb, yb, xc, yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;

        xb -= xa;
        xc -= xa;
        yb -= ya;
        yc -= ya;
        int total = 1;
        if ((xb > 0 && xc > 0) || (xb < 0 && xc < 0)) total += min(abs(xb), abs(xc));
        if ((yb > 0 && yc > 0) || (yb < 0 && yc < 0)) total += min(abs(yb), abs(yc));

        cout << total << '\n';
    }
}

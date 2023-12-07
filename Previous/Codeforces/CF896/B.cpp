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

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        a--, b--;

        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        int to_major = INF, to_b = INF;
        for (int i = 0; i < k; i++) {
            to_major = min(to_major, dist(x[i], y[i], x[a], y[a]));
            to_b = min(to_b, dist(x[i], y[i], x[b], y[b]));
        }

        cout << min(dist(x[a], y[a], x[b], y[b]), to_major + to_b) << '\n';

    }
}

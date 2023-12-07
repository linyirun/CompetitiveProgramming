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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    if (a == 0) return b;
    return gcd(b, a % b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        map<int, int> pos;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<bool> vis(n + 1);

        int curr_gcd = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            int curr = i;
            while (!vis[curr] && a[curr] != curr) {
                vis[curr] = true;
                curr_gcd = gcd(curr_gcd, abs(curr - a[curr]));
                curr = a[curr];
            }
        }

        cout << curr_gcd << '\n';

    }
}

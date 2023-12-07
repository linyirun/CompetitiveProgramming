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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<int> nxt1(n, n), prev0(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') nxt1[i] = i;
            if (i != n - 1) nxt1[i] = min(nxt1[i], nxt1[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') prev0[i] = i;
            if (i) prev0[i] = max(prev0[i], prev0[i - 1]);
        }

        set<pii> seen;

        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            l--, r--;

            l = nxt1[l];
            r = prev0[r];

            if (l >= r) seen.insert({-1, -1});
            else seen.insert({l, r});

        }
        cout << seen.size() << '\n';
    }
}

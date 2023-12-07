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

        vector<int> xi(n), pi(n);
        set<int> important;
        for (int i = 0; i < n; i++) {
            cin >> xi[i] >> pi[i];

            int l = xi[i] - pi[i], r = xi[i] + pi[i];
            important.insert(l);
            important.insert(r);
//            important.insert(r + 1);
            important.insert(xi[i]);
        }

        // Coordinate compress
        map<int, int> compress, uncompress;
        int cnt = 0;
        for (int i : important) {
            compress[i] = cnt;
            uncompress[cnt++] = i;
        }

        vector<int> slope(cnt);
        for (int i = 0; i < n; i++) {
            int l = compress[xi[i] - pi[i]], r = compress[xi[i] + pi[i]];
            slope[l]++;
//            cout << "Added 1 to " << uncompress[l] << '\n';

            slope[compress[xi[i]]] -= 2;
//            cout << "Sub 2 to " << uncompress[xi[i]] << '\n';

            slope[r]++;
//            cout << "Added 1 to " << uncompress[r] << '\n';
        }
        for (int i = 1; i < cnt; i++) {
            slope[i] += slope[i - 1];
        }
        vector<pii> mx_vals;
        int curr = 0;
        for (int i = 0; i < cnt - 1; i++) {
            int l = uncompress[i], r = uncompress[i + 1];
            if (slope[i] <= 0) {
                if (curr > m) mx_vals.push_back({l, curr});
                curr += (r - l) * slope[i];
            } else {
                curr += (r - l) * slope[i];
                if (curr > m) mx_vals.push_back({r, curr});
            }
        }

        if (mx_vals.empty()) {
            for (int i = 0; i < n; i++) cout << "1";
            cout << '\n';
            continue;
        }

        int mn_l = mx_vals[0].first, mx_r = mx_vals[mx_vals.size() - 1].first;
        for (int i = 0; i < n; i++) {
            bool can = true;
            int l = xi[i] - pi[i], r = xi[i] + pi[i];
            if (l > mn_l || r < mx_r) {
                can = false;
                goto done;
            }

            for (pii &p : mx_vals) {
                if (p.second - (pi[i] - abs(p.first - xi[i])) > m) {
                    can = false;
                    goto done;
                }
            }

            done:;
            if (can) cout << "1";
            else cout << "0";
        }
        cout << '\n';
    }
}

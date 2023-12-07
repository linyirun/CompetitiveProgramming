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
        vector<map<int, int>> cnt(2 * n + 1);
        vector<vector<int>> v(2 * n + 1);

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            cnt[a[i]][b[i]] += 1;
            v[a[i]].push_back(b[i]);
        }
        int total = 0;
        int SQRT = sqrt(n);
        for (int ai = 1; ai <= n; ai++) {
            for (int aj = 1; ai * aj <= 2 * n; aj++) {
                if (ai < SQRT) {

                } else {
                    // O(n) at most
                    for (int bi: v[ai]) {
                        int need = ai * aj - bi;
                        if (cnt[aj].count(need)) total += cnt[aj][need];
                    }
                }
            }
        }

        int to_add = 0;
        set<pii> done;
        for (int i = 0; i < n; i++) {
            if (a[i] * a[i] == 2 * b[i] && !done.count({a[i], b[i]})) {
                done.insert({a[i], b[i]});
                int c = cnt[a[i]][b[i]];
                total -= c * c;
                to_add += c * (c - 1) / 2;
            }
        }

        cout << total / 2 + to_add << '\n';
    }
}

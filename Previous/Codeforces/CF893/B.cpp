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

int calc(int s1, int s2, int d) {
    return (s2 - s1 - 1 + d) / d - 1;
}

int calc_end(int s1, int s2, int d) {
    return max(0LL, (s2 - s1 + d) / d - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m, d;
        cin >> n >> m >> d;

        vector<int> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];

        bool added = false;
        if (a[0] != 1) {
            a.insert(a.begin(), 1);
            m++;
            added = true;
        }

        vector<int> suff(m);
        suff[m - 1] = calc_end(a[m - 1], n, d);

        for (int i = m - 2; i >= 0; i--) {
            suff[i] = calc(a[i], a[i + 1], d);
            suff[i] += suff[i + 1];
        }

        // remove last one
        int best = suff[0] - suff[m - 2] + calc_end(a[m - 2], n, d), best_cnt = 1;

        // remove first
        if (!added) best = min(best, suff[1] + calc(a[0], a[1], d));

        for (int i = 1; i < m - 1; i++) {
            int curr = suff[0] - suff[i - 1] + calc(a[i - 1], a[i + 1], d) + suff[i + 1];
//            if (calc(a[i - 1], a[i + 1], d) < 0) {
//                cout << 'a';
//            }

            if (curr < best) {
                best = curr;
                best_cnt = 1;
            } else if (curr == best) best_cnt++;
        }

        cout << best + m - 1 << ' ' << best_cnt << '\n';

    }
}

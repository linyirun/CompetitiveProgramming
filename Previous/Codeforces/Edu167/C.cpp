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

// Only cases are (-1, -1) or (1, 1)


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        int score_a = 0, score_b = 0;

        int negs = 0, pos = 0;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
//a[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
//            b[i] = 1;

            if (a[i] > b[i]) {
                score_a += a[i];
            } else if (a[i] < b[i]) {
                score_b += b[i];
            }
            else {
                if (a[i] == 1) pos++;
                else if (a[i] == -1) negs++;
            }
        }

        int best_score = INT_MIN;

        int l = -2e6, r = 2e6;
        while (l <= r) {
            int mp = (l + r) / 2;
            // Determine if this is possible
            int leftover = max(0LL, score_a - mp) + max(0LL, score_b - mp);
            int need = max(0LL, mp - score_a) + max(0LL, mp - score_b);

            if (need + max(0LL, negs - leftover) <= pos) {
                best_score = mp;
                l = mp + 1;
            } else r = mp - 1;

        }
        cout << best_score << '\n';

    }
}

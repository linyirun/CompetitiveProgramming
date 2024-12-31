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
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        vector<char> edges(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) cin >> edges[i];

        set<int> mex;
        for (int i = 0; i <= n; i++) mex.insert(i);

        vector<int> allowed_lr(n);

        for (int i = 0; i < n; i++) {
            mex.erase(a[i]);
            if (*mex.begin() == i + 1) {
                allowed_lr[i] = true;
            }
        }

        int bad_lrs = 0;
        for (int i = 0; i < n - 1; i++) {
            if (edges[i] == 'L' && edges[i + 1] == 'R' && !allowed_lr[i]) {
                bad_lrs++;
            }
        }

        for (int it = 0; it < q; it++) {
            int i;
            cin >> i;
            i--;

            if (edges[i] == 'L') {
                // Change from L -> R;
                if (edges[i - 1] == 'L' && !allowed_lr[i - 1]) {
                    bad_lrs++;
                }

                if (edges[i + 1] == 'R' && !allowed_lr[i]) {
                    bad_lrs--;
                }

                edges[i] = 'R';

            } else {
                // Change from R -> L
                if (edges[i - 1] == 'L' && !allowed_lr[i - 1]) {
                    bad_lrs--;
                }
                if (edges[i + 1] == 'R' && !allowed_lr[i]) {
                    bad_lrs++;
                }
                edges[i] = 'L';
            }

            if (bad_lrs == 0) {
                cout << "YES\n";
            } else cout << "NO\n";
        }
    }
}

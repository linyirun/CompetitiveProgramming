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

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n == 1) {
            cout << "1\n";
            continue;
        } else if (n == 2) {
            if (a[0] == a[1]) cout << "1\n";
            else cout << "2\n";
            continue;
        }

        // Now n >= 3
        int prev_2 = a[0], prev = -1;
        int removed = 0;
        for (int i = 1; i < n; i++) {
            if (prev == -1) {
                if (a[i] == prev_2) {
                    removed++;
                    continue;
                } else {
                    prev = a[i];
                    continue;
                }
            }
            if (a[i] == prev) {
                removed++;
                continue;
            }

            if ((prev_2 < prev && prev < a[i]) || (prev_2 > prev && prev > a[i])) {
                prev_2 = prev;
                prev = a[i];
                removed++;
            } else {
                prev_2 = prev;
                prev = a[i];
            }
        }

        cout << n - removed << '\n';

    }
}

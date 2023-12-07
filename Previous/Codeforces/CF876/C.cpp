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

        if (a[n - 1] == 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        int cnt_0 = 1, cnt_1 = 0;
        for (int i = n - 2; i >= -1; i--) {
            if (i == -1 || (cnt_1 && a[i] == 0)) {
                // this is a chain
                for (int j = 0; j < cnt_0 + cnt_1 - 1; j++) {
                    cout << "0 ";
                }
                cout << cnt_1 << ' ';
                cnt_0 = 0, cnt_1 = 0;
            }

            if (a[i]) cnt_1++;
            else cnt_0++;

        }
        cout << '\n';

    }
}

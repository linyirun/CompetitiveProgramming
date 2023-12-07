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
        int x, y, n;
        cin >> x >> y >> n;

        vector<int> a(n);
        a[0] = x;
        int curr = y;
        for (int i = 0; i < n - 1; i++) {
            a[n - i - 1] = curr;
            curr -= i + 1;
        }

        vector<int> b(n - 1);
        bool can = true;
        for (int i = 1; i < n; i++) {
            b[i - 1] = a[i] - a[i - 1];
            if (i > 1 && b[i - 2] <= b[i - 1]) can = false;
        }
        if (a[0] >= a[1]) can = false;
        if (can) {
            for (int i : a) cout << i << ' ';
            cout << '\n';
        } else cout << "-1\n";

    }
}

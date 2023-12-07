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

        if (n == 1) {
            cout << "1\n";
        } else if (n == 2) {
            cout << "2 1\n";
        } else {
            vector<int> a(n);

            a[0] = 3;
            a[n - 1] = 2;
            a[n / 2] = 1;
            int cnt = 4;
            for (int i = 0; i < n; i++) {
                if (!a[i]) a[i] = cnt++;
                cout << a[i] << ' ';
            }
            cout << '\n';
        }

    }
}

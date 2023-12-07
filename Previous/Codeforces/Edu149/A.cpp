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
        int n, k;
        cin >> n >> k;

        if (n % k != 0) {
            cout << "1\n";
            cout << n << '\n';
        } else {
            cout << "2\n";
            cout << n - 1 << ' ' << 1 << '\n';
        }
    }
}

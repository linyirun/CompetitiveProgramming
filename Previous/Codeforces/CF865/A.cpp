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
        int a, b;
        cin >> a >> b;

        if (a == 1) {
            cout << "1\n";
            cout << a << ' ' << b << '\n';
            continue;
        }

        cout << "2\n";
        cout << a - 1 << ' ' << a - 2 << '\n';
        cout << a << ' ' << b << '\n';
    }
}

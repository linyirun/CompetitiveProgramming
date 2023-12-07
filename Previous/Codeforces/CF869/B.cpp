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
            continue;
        }

        if (n % 2 == 1) {
            cout << "-1\n";
            continue;
        }


        for (int i = 0; i < n; i += 2) {
            cout << i + 2 << ' ' << i + 1 << ' ';
        } cout << '\n';

    }
}

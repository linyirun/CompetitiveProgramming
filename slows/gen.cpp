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

    freopen("tests.txt", "w", stdout);

    int tests = 1000;

    cout << tests << '\n';
    for (int i = 0; i < tests; i++) {
        int n = 4;
        cout << n << '\n';
        for (int j = 0; j < n; j++) {
            cout << rand() % 5 + 1 << ' ';
        }
        cout << '\n';
    }
}

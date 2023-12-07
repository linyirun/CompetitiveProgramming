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

    vector<int> fib(40);
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < 40; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    while (tt--) {
        int n, k;
        cin >> n >> k;

        if (k >= 30) {
            cout << "0\n";
            continue;
        }

        int cnt = 0;
        for (int a = 0; a <= n; a++) {
            int tmp = fib[k - 2] * a;
            int b = (n - tmp) / fib[k - 1];
            if (a <= b && tmp + fib[k - 1] * b == n) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}

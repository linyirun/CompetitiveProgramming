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

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == i + 1) cnt++;
        }
        cout << (cnt + 1) / 2 << '\n';

    }
}

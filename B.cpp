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

        string s;
        cin >> s;

        int rmost_b = -1;
        int first_a = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') rmost_b = i;
            else first_a = min(first_a, i);
        }

        cout << max(0LL, rmost_b - first_a) << '\n';
    }
}

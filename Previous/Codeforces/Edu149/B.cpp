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

        int chain = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (!i || s[i] == s[i - 1]) chain++;
            else {
                mx = max(chain + 1, mx);
                chain = 1;
            }
        }
        mx = max(chain + 1, mx);

        cout << mx << '\n';

    }
}

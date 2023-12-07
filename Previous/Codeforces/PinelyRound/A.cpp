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
        int n, a, q;
        cin >> n >> a >> q;

        int curr = a, best = a, best_once = a;
        string s;
        cin >> s;
        for (int i = 0; i < q; i++) {
            if (s[i] == '-') {
                curr--;
            } else {
                curr++;
                best++;
                best_once = max(best_once, curr);
            }
        }

        if (best_once >= n) cout << "YES\n";
        else if (best >= n) cout << "MAYBE\n";
        else cout << "NO\n";
    }
}

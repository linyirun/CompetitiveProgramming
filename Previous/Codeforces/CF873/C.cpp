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

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ptr = 0; // [0:ptr] < a[i]
        int curr = 1;
        for (int i = 0; i < n; i++) {
            while (ptr < n && b[ptr] < a[i]) ptr++;
            if (ptr < i) curr = 0;
            else {
                curr = (curr * (ptr - i)) % MOD;
            }
        }
        cout << curr << '\n';

    }
}

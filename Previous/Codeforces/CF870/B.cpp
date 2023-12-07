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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    if (a == 0) return b;
    return gcd(b, a % b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr = gcd(curr, max(a[i], a[n - i - 1]) - min(a[i], a[n - i - 1]));
        }
        cout << curr << '\n';
    }
}

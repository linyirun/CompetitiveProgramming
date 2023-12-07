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

        vector<int> a(101);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x]++;
        }

        bool can = true;
        for (int i = 0; i < 100; i++) {
            if (a[i] < a[i + 1]) can = false;
        }
        if (can) cout << "YES\n";
        else cout << "NO\n";
    }
}

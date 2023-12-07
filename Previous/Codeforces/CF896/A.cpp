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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << "4\n";
        int pick = n;
        if (n % 2 == 1) pick--;
        for (int i = 0; i < 2; i++) cout << "1 " << pick << '\n';
        for (int i = 0; i < 2; i++) cout << n - 1 << ' ' << n << '\n';

    }
}

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

    int n = 8;
    vector<int> a(n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 25 != 0 || a[i] > 675 || a[i] < 100) flag = false;
        if (i && a[i - 1] > a[i]) flag = false;
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
}

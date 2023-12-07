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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
        if (i == n - 1) break;
        if (a[i] < a[i + 1]) {
            for (int j = a[i] + 1; j < a[i + 1]; j++) cout << j << ' ';
        } else {
            for (int j = a[i] - 1; j > a[i + 1]; j--) cout << j << ' ';
        }
    }
    cout << '\n';
}

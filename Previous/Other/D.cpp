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

    vector<int> a(n), bef(n), aft(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bef[i] = aft[i] = a[i];
        if (i) bef[i] = min(bef[i], bef[i - 1]);
        if (i != n - 1) aft[i] = min(aft[i], aft[i + 1]);
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        int mn = a[i] - 1;
        if (i) mn = min(mn, )
    }
}

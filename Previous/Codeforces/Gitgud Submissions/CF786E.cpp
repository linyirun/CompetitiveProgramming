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


int calc(int a, int b) {
    if (a > b) swap(a, b);
    int l = 0, r = a;
    int ans = 0;
    while (l <= r) {
        int mp = (l + r) / 2;
        if (a - mp * 2 <= (b - mp + 1) / 2) {
            ans = mp;
            r = mp - 1;
        } else l = mp + 1;
    }

    return ans + (b - ans + 1) / 2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    int best = (sorted[0] + 1) / 2 + (sorted[1] + 1) / 2;

    for (int i = 0; i < n - 1; i++) {
        // Adjacent case:
        best = min(best, calc(a[i], a[i + 1]));

        if (i + 2 < n) {
            int add = 0;
            if (a[i] % 2 == 1 || a[i + 2] % 2 == 1) add = 1;
            best = min(best, a[i] / 2 + a[i + 2] / 2 + add);
        }

    }

    cout << best << '\n';

}

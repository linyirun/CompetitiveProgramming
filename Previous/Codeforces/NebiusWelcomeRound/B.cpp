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
        int n, k, d, w;
        cin >> n >> k >> d >> w;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int cnt = 0; // Number of packs used
        int left = 0, end_time = 0;
        for (int i = 0; i < n; i++) {
            if (!left || end_time < a[i]) {
                cnt++;
                left = k - 1;
                end_time = a[i] + d + w;
            } else left--;
        }
        cout << cnt << '\n';

    }

}

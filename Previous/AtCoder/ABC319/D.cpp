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

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int l = mx, r = 1e15;
    int ans = r;
    while (l <= r) {
        int w = (l + r) / 2;
        int curr_line = 1, curr_pos = 0;
        for (int i = 0; i < n; i++) {
            if (!curr_pos) {
                curr_pos = a[i];
            } else {
                if (curr_pos + 1 + a[i] <= w) {
                    curr_pos += 1 + a[i];
                } else {
                    curr_line++;
                    curr_pos = a[i];
                }
            }
        }

        if (curr_line > m) {
            l = w + 1;
        } else {
            ans = w;
            r = w - 1;
        }
    }
    cout << ans << '\n';

}

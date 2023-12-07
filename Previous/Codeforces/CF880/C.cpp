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
        int A, B, C, k;
        cin >> A >> B >> C >> k;

        int mn_A = 1, mn_B = 1, mn_C = 1;
        for (int i = 0; i < A - 1; i++) mn_A *= 10;
        for (int i = 0; i < B - 1; i++) mn_B *= 10;
        for (int i = 0; i < C - 1; i++) mn_C *= 10;

        int mx_A = mn_A * 10 - 1;
        int mx_B = mn_B * 10 - 1;
        int mx_C = mn_C * 10 - 1;

        int ans_a = -1, ans_b = -1, ans_c = -1;
        for (int a = mn_A; a <= mx_A; a++) {
            int l = max(mn_B, mn_C - a), r = min(mx_B, mx_C - a);
            int range = r - l + 1;
            if (k <= range) {
                ans_a = a, ans_b = l + k - 1, ans_c = ans_a + ans_b;
                break;
            } else {
                k -= max(0LL, range);
            }
        }
        if (ans_a == -1) cout << "-1\n";
        else cout << ans_a << " + " << ans_b << " = " << ans_c << '\n';


    }
}

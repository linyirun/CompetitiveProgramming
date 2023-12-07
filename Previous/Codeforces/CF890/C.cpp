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

int get(int idx, int target, vector<int> &a) {
    // What is the min num of operations to make a[idx] = target
    if (a[idx] >= target) return 0;
    if (idx == (int) a.size() - 1) {
        return -1;
    }
    int res = get(idx + 1, target - 1, a);
    if (res == -1) return -1;
    return res + max(0LL, target - a[idx]);


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int l = 0, r = 1e9;
        int ans = 0;
        while (l <= r) {
            int mp = (l + r) / 2;
            bool can = false;
            for (int i = 0; i < n; i++) {
                vector<int> cpy = a;
                int res = get(i, mp, cpy);
                if (res != -1 && res <= k) {
                    can = true;
                    break;
                }
            }

            if (can) {
                ans = mp;
                l = mp + 1;
            } else r = mp - 1;
        }
        cout << ans << '\n';
    }
}

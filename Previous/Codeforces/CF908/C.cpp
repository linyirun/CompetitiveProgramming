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

int n;
int sub(int a, int b) {
    int res = (a - b) % n;
    if (res < 0) res += n;
    return res;

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> vis_offset(n + 1);

        bool can = true;
        int offset = 0;
        while (k > 0) {
            if (vis_offset[offset]) {
                break;
            }
            vis_offset[offset] = true;

            if (a[sub(n - 1, offset)] > n) {
                can = false;
                break;
            }
            offset += a[sub(n - 1, offset)];
            offset %= n;
            k--;
        }

        if (can) cout << "Yes\n";
        else cout << "No\n";


    }
}

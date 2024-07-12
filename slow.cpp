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

const int MAX = 10000;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    vector<bool> has_p(MAX), has_g(MAX);
    has_g[0] = has_p[0] = true;

    int ptr_p = 0, ptr_g = 0;
    while (q--) {
        char op;
        int k;
        cin >> op >> k;

        if (op == 'P') {
            for (int i = ptr_p; i <= ptr_p + k; i++) {
                has_p[i] = true;
            }
            ptr_p += k;
        } else {

            for (int i = ptr_g; i <= ptr_g + k; i++) {
                if (has_p[i]) has_g[i] = true;
            }
            ptr_g += k;
        }
    }
    int cnt = 0;
    for (int i = 0; i < MAX; i++) {
        cnt += has_p[i] && has_g[i];
    }
    cout << cnt << '\n';
}

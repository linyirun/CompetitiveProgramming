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

int k;

pii recur(int sz) {
    if (sz < k) {
        return {0, 0};
    }
    int mp = sz / 2;
    pii res = recur(mp);
    int split = mp;
    if (sz % 2 == 1) split = (sz + 1) / 2;

    int ret = 2 * res.first + split * res.second;
    int odd_cnt = res.second * 2;

    if (sz % 2 == 1) {
        odd_cnt++;
        ret += split;
    }
    return {ret, odd_cnt};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n >> k;

        pii res = recur(n);
        cout << res.first << '\n';

    }
}

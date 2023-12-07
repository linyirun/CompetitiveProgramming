#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

#define int ll
const int MOD = 998244353;
//const int MOD = 1000000007;
const int INF = 1e15;

const int MAX = 2e5 + 1;
ll fac[MAX + 1];
ll inv[MAX + 1];
// binexp
ll binpow(ll base, ll exp) {
    if (exp == 0) return 1;
    ll tmp = binpow(base, exp / 2);
    if (exp % 2 == 1) return (tmp * tmp) % MOD * base % MOD;
    else return (tmp * tmp) % MOD;
}

ll nCr(int n, int k) {
    return fac[n] * inv[n - k] % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    fac[0] = inv[0] = 1;
    for (ll i = 1; i <= MAX; i++) {
        fac[i] = i * fac[i - 1];
        fac[i] %= MOD;
        inv[i] = binpow(fac[i], MOD - 2);
    }

    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();

        vector<int> sz;

        int curr_chain = 0;
        for (int i = 0; i < n; i++) {
            if (!i || s[i] == s[i - 1]) curr_chain++;
            else {
                if (curr_chain >= 1) sz.push_back(curr_chain);
                curr_chain = 1;
            }
        }
        if (curr_chain >= 1) sz.push_back(curr_chain);

        int mn_op = 0, total = 1;
        for (int i : sz) mn_op += i - 1;

        int so_far = 0;
        for (int i : sz) {
            total = total * (i) % MOD * nCr(mn_op - so_far, i - 1) % MOD;
            so_far += i - 1;
        }
        cout << mn_op << ' ' << total << '\n';


    }
}
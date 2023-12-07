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

const int MAX = 1001 * 1001;

vector<int> fac(MAX), inv_fac(MAX);

int binexp(int base, int exp) {
    if (exp == 0) return 1;
    int tmp = binexp(base, exp / 2);
    tmp *= tmp;
    tmp %= MOD;
    if (exp % 2 == 1) tmp = tmp * base % MOD;
    return tmp;
}

int nCr(int n, int k) {
    if (k > n) return 0;
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}

int add(int &a, int b) {
    a = (a + b) % MOD;
}

int sub(int &a, int b) {
    a = (a - b) % MOD;
    if (a < 0) a += MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = inv_fac[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv_fac[i] = binexp(fac[i], MOD - 2);
    }

    int h, w, k;
    cin >> h >> w >> k;

    int total = 0;
    for (int r = 1; r <= h; r++) {
        for (int c = 1; c <= w; c++) {
            int combinations = nCr(r * c, k);
            sub(combinations, nCr((r - 1) * c, k));
            sub(combinations, nCr(r * (c - 1), k));
            add(combinations, nCr((r - 1) * (c - 1), k));
            combinations = combinations * (h - r + 1) % MOD;
            combinations = combinations * (w - c + 1) % MOD;
            combinations = combinations * r * c % MOD;
            total = (total + combinations) % MOD;
        }
    }

    total *= binexp(nCr(h * w, k), MOD - 2);
    total %= MOD;
    cout << total << '\n';
}

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

const int MAX = 61;

vector<vector<vector<int>>> dp(MAX, vector<vector<int>>(MAX, vector<int>(MAX, -1)));

// binexp
ll binpow(ll base, ll exp) {
    if (exp == 0) return 1;
    ll tmp = binpow(base, exp / 2);
    if (exp % 2 == 1) return (tmp * tmp) % MOD * base % MOD;
    else return (tmp * tmp) % MOD;
}



int memo(int i, int j, int k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];

    int curr = binpow(5, MOD - 2);
    int sum = memo(i - 1, j, k) + memo(i, j - 1, k) + memo(i - 2, j, k) + memo(i, j, k - 1) + memo(i - 1, j - 1, k);
    sum %= MOD;

    return dp[i][j][k] = curr * sum % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int fac = n;
    int cnt2 = 0, cnt3 = 0, cnt5 = 0;
    while (fac % 2 == 0) {
        cnt2++;
        fac /= 2;
    }
    while (fac % 3 == 0) {
        cnt3++;
        fac /= 3;
    }
    while (fac % 5 == 0) {
        cnt5++;
        fac /= 5;
    }

    if (fac > 1) {
        cout << "0\n";
        return 0;
    }

    dp[0][0][0] = 1;
    cout << memo(cnt2, cnt3, cnt5) << '\n';

}

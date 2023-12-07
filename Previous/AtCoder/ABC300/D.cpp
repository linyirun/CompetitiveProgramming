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

const int MAX = 1e6 + 1;

vector<int> pref(MAX);
int get_range(int l, int r) {
    if (l >= r) return 0;
    return max(0LL, pref[r] - pref[l]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Sieve
    vector<bool> is_prime(MAX, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX; i++) {
        pref[i] += pref[i - 1];
        if (!is_prime[i]) continue;
        for (int j = i * i; j < MAX; j += i) {
            is_prime[j] = false;
        }
        pref[i] += is_prime[i];
    }

    int cnt = 0;
    for (int a = 1; a < MAX; a++) {
        if (!is_prime[a]) continue;
        int k = n / (a * a);
        for (int c = a + 2; c * c <= k; c++) {
            if (!is_prime[c]) continue;
            int r = n / (a * a * c * c);
            cnt += get_range(a, min(c - 1, r));
        }
    }
    cout << cnt << '\n';
}

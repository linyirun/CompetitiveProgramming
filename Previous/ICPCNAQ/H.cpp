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

vector<int> get_factors(int n) {
    vector<int> fac;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            fac.push_back(i);
            if (i * i != n) fac.push_back(n / i);
        }
    }

    return fac;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, p;
    cin >> n >> k >> p;

    vector<int> fac = get_factors(n);

    vector<int> possible;
    for (int f : fac) {
        if (f <= k && n / f <= p) possible.push_back(f);
    }

    sort(possible.begin(), possible.end());
    cout << possible.size() << '\n';
    for (int i : possible) cout << i << '\n';
}

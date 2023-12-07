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

map<int, int> factors;

map<int, int> factor(int n) {

    map<int, int> facs;
    while (n > 1) {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                facs[i]++;
                n /= i;
                break;
            }
        }
    }
    return facs;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> fac(10);
    fac[0] = 1;
    for (int i = 1; i < 10; i++) {
        fac[i] = fac[i - 1] * i;
    }

    int n;
    string s;
    cin >> n >> s;

    int prod = 1;
    for (char c : s) {
        int num = c - '0';
        prod *= fac[num];
        map<int, int> fact = factor(fac[num]);
        for (pii p : fact) factors[p.first] += p.second;
    }

    vector<int> primes = {7, 5, 3, 2};
    string ans;
    while (true) {
        bool done = true;

        for (int i : primes) {
            bool works = true;
            map<int, int> prime_fac = factor(fac[i]);
            for (pii p : prime_fac) {
                if (prime_fac[p.first] > factors[p.first]) {
                    works = false;
                    break;
                }
            }

            if (works) {
                for (pii p : prime_fac) {
                    factors[p.first] -= prime_fac[p.first];
                }
                ans += to_string(i);
                done = false;
                break;
            }
        }

        if (done) break;
    }
    cout << ans << '\n';





}

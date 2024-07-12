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

int BITS = 32;

void f(vector<int> &v) {
    for (int i = 0; i < BITS -1; i++) {
        if (v[i] == 2) {
            v[i + 1] += 1;
            v[i] = 0;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;


    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(BITS);

        for (int i = BITS - 1; i >= 0; i--) {
            if (n >= (1LL << i)) {
                n -= 1LL << i;
                a[i] = 1;
            }
        }

        for (int i = 0; i < BITS - 1; i++) {
            if (a[i] == 1 && a[i + 1] == 1) {
                a[i] = -1;
                a[i + 1] = 0;
                a[i + 2]++;
                f(a);
            }
        }

        cout << BITS << '\n';
        for (int i = 0; i < BITS; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';

    }
}

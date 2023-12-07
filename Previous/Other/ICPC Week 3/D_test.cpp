#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

const int mod = 998244353;
int p, q, k, x, y, z;

//int MAX = 1e7 + 1;
//vector<vector<int>> factors(MAX);

const int MAX = 200;
void solve() {
//    cin >> p >> q;

    for (int a = 1; a <= MAX; a++) {
        for (int b = 1; b <= MAX; b++) {
            if ((a * a + b * b) * q == p * a * b) {
                cout << "p: " << p << ", " << "q: " << q << '\n';
                cout << a << ' ' << b << '\n';
                return;
            }
        }
    }
//    cout << "0 0\n";
}

signed main() {
    cout << fixed << setprecision(10);
    // cout << boolalpha;
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

    int T = 1;
//    cin >> T;
//    for (int i = 1; i <= T; i++) {
    for (p = 1; p <= 50; p++) {
        for (q = 1; q <= 50; q++) {
            solve();
        }
    }

//    }
}
#include <bits/stdc++.h>
//#define int long long
#define f first
#define s second
using namespace std;

const int mod = 998244353;
int n, m, k, x, y, z;

int MAX = 1e7 + 1;
vector<vector<int>> factors(MAX);

void solve() {
    cin >> n >> m;
    for (int i : factors[m]) {
            int j = m / i;
            if (i * i + j * j == n) {
                cout << i << " " << j << "\n";
                return;
            }
    }
    cout << "0 0\n";
}

signed main() {
    cout << fixed << setprecision(10);
    // cout << boolalpha;
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            factors[j].push_back(i);
//            factors[j].push_back(j / i);
        }
    }

    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
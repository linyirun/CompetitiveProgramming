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

int n;

int best = INT_MAX;

void recur(vector<int> a, vector<int> col, int curr) {
    bool done = true;
    for (int i = 0; i < n; i++) {
        if (!col[i]) done = false;
    }
    if (done) {
        best = min(best, curr);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i]) {
            // spend 1 to color i
            col[i] = 1;
            recur(a, col, curr + 1);
            col[i] = 0;
        }

        if (col[i] && a[i]) {
            if (i && !col[i - 1]) {
                a[i]--;
                col[i - 1] = 1;
                recur(a, col, curr);
                col[i - 1] = 0;
                a[i]++;
            }

            if (i != n - 1 && !col[i + 1]) {
                a[i]--;
                col[i + 1] = 1;
                recur(a, col, curr);
                col[i + 1] = 0;
                a[i]++;
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("tests.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    int tt;
    cin >> tt;
//tt = 1;
    while (tt--) {
        best = INT_MAX;

        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> col(n);

        recur(a, col, 0);
        cout << best << '\n';
    }

}

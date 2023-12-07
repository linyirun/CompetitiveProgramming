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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    string s;
    cin >> s;

    vector<vector<int>> m(n, vector<int>(8)), e = m;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') m[i][1 << a[i]]++;
            if (i) {
            for (int msk = 0; msk < 8; msk++) {
                m[i][msk] += m[i - 1][msk];
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            e[i][j] += e[i - 1][j];
            if (s[i] == 'E') {
                for (int prev_msk = 0; prev_msk < 8; prev_msk++) {
                    if ((prev_msk | (1 << a[i])) == j) {
                        e[i][j] += m[i - 1][prev_msk];
                    }
                }
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'X') {
            for (int msk = 0; msk < 8; msk++) {
                int curr_msk = (msk | (1 << a[i]));
                int mex = 3;
                for (int j = 0; j < 3; j++) {
                    if (!(curr_msk & (1 << j))) {
                        mex = j;
                        break;
                    }
                }
                sum += mex * e[i - 1][msk];
            }
        }
    }
    cout << sum << '\n';

}

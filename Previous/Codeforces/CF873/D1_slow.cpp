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

bool is_sorted(vector<int> a) {
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    return a == sorted;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("tests.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int total = 0;
        for (int l = 0; l < n; l++) {
            vector<int> curr;
            for (int r = l; r < n; r++) {
                curr.push_back(a[r]);
                int best = INT_MAX;
                for (int i = 0; i < curr.size(); i++) {
                    for (int j = i + 1; j <= curr.size(); j++) {
                        vector<int> cpy = curr;
                        sort(cpy.begin() + i, cpy.begin() + j);
                        if (is_sorted(cpy)) {
                            best = min(best, j - i - 1);
                        }
                    }
                }
                total += best;
            }


        }
        cout << total << '\n';
    }
}

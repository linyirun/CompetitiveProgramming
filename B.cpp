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

    int tt;
    cin >> tt;

    vector<int> to_check;
    int curr = 2;
    for (int i = 1; curr <= 1e17; i++) {
        to_check.push_back(curr);
        curr *= 2;
    }
    to_check.push_back(3);

    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int k : to_check) {
            set<int> s;
            for (int i = 0; i < n; i++) {
                s.insert(a[i] % k);
            }

            if (s.size() == 2) {
                cout << k << '\n';
                break;
            }
        }
    }
}

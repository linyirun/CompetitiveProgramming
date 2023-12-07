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

    freopen("tests.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    int tt;
    cin >> tt;
    while (tt--) {

        int n;
        cin >> n;

        vector<int> a(n);
        set<pii > s; // {value, ind}
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        while (true) {
            bool changed = false;
            int l = -1, r = -1;

            for (int i = 0; i < a.size(); i++) {
                for (int j = i + 1; j < a.size(); j++) {
                    if (a[i] == a[j] && (l == -1 || a[i] < a[l])) {
                        l = i, r = j;
                        break;
                    }
                }
            }

            if (l == -1) break;
            else {
                a[r] *= 2;
                a.erase(a.begin() + l);
            }
        }
        cout << a.size() << '\n';
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}

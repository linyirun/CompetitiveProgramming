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

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> se;
        int picked = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            se.insert(a[i]);
            if (i && a[i] == a[i - 1]) picked = i;
        }

        if (se.size() == 1 || (picked == -1 && se.size() == 2)) {
            cout << "NO\n";
        } else {
            if (picked == -1) picked = 0;
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (i == picked) cout << 'R';
                else cout << 'B';
            }
            cout << '\n';
        }

    }
}

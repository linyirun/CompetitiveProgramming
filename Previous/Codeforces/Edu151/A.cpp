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
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> s;
        if (k == 1) {
            cout << "NO\n";
        } else if (k == 2) {
            if (x == 1 && n % 2 == 1) cout << "NO\n";
            else {
                if (x != 2) {
                    while (n >= 2) {
                        n -= 2;
                        s.push_back(2);
                    }
                } else {
                    while (n >= 1) {
                        n -= 1;
                        s.push_back(1);
                    }
                }
                cout << "YES\n";
                cout << s.size() << '\n';
                for (int i : s) cout << i << ' ';
                cout << '\n';
            }
        } else {
            if (x == 1 && n == 1) {
                cout << "NO\n";
                continue;
            }

            if (x == 1) {
                if (n % 2 == 1) {
                    s.push_back(3);
                    n -= 3;
                }
                while (n != 0) {
                    n -= 2;
                    s.push_back(2);
                }
            } else {
                while (n) {
                    n--;
                    s.push_back(1);
                }
            }
            cout << "YES\n";
            cout << s.size() << '\n';
            for (int i : s) cout << i << ' ';
            cout << "\n";
        }

    }
}

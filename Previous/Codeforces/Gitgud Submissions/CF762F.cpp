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
        int n, m, k;
        cin >> n >> m >> k;

        int leftover = n % m;
        int big_table_sz = (n + m - 1) / m;
        int small_table_sz = n / m;

        int curr_pos = 0;

        for (int game = 0; game < k; game++) {
            for (int i = 0; i < leftover; i++) {
                cout << big_table_sz << ' ';
                for (int j = 0; j < big_table_sz; j++) {
                    cout << curr_pos % n + 1 << ' ';
                    curr_pos++;
                }
                cout << '\n';
            }
            int rem = curr_pos;
            for (int i = 0; i < m - leftover; i++) {
                cout << small_table_sz << ' ';
                for (int j = 0; j < small_table_sz; j++) {
                    cout << rem % n + 1 << ' ';
                    rem++;
                }
                cout << '\n';
            }
        }

        cout << '\n';


    }
}

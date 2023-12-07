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

    int n, m;
    cin >> n >> m;

    int total_mn = 0, total_mx = 0;

    for (int floor = 0; floor < n; floor++) {
        vector<bool> a(m);
        int curr_mn = 0, curr_mx = 0;
        for (int i = 0; i < m; i++) {
            char c;
            cin >> c;
            a[i] = c == '1';
        }

        // Find maximum:
        int left = m / 4;
        vector<bool> taken(m);
        for (int i = 0; i < m - 1; i++) {
            if (!left) break;
            if (!a[i] || !a[i + 1]) {
                left--;
                taken[i] = taken[i + 1] = true;
                if (a[i] || a[i + 1]) curr_mx++;
                i++;

            }
        }

        for (int i = 0; i < m; i++) {
            if (!taken[i]) curr_mx += a[i];
        }

        curr_mx -= left;

        total_mx += curr_mx;


        // Minimum
        // Take 11s if possible
        left = m / 4;
        taken = vector<bool>(m);
        for (int i = 0; i < m - 1; i++) {
            if (!left) break;
            if (a[i] && a[i + 1]) {
                left--;
                taken[i] = taken[i + 1] = true;
                curr_mn++;
                i++;
            }
        }


        // Take 0/1 or 1/0
//        for (int i = 0; i < m - 1; i++) {
//            if (taken[i] || taken[i + 1]) continue;
//            if (!left) break;
//            if (a[i] || a[i + 1]) {
//                left--;
//                taken[i] = taken[i + 1] = true;
//                curr_mn++;
//                i++;
//            }
//        }

        for (int i = 0; i < m; i++) {
            if (!taken[i]) curr_mn += a[i];
        }
        total_mn += curr_mn;

//        cout << curr_mn << '\n';

    }
    cout << total_mn << ' ' << total_mx << '\n';
}

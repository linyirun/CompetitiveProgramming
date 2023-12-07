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
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
        }

        for (vector<int> &v : a) sort(v.begin(), v.end(), greater<int>());

        int total = 0;
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            for (int item : a[i]) {
                total += item;
                q.push(i);
                if (q.size() == i) {
                    while (!q.empty()) q.pop();
                    break;
                }
                while (!q.empty() && q.front() == q.size()) q.pop();
            }
        }
        cout << total << '\n';

    }
}

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

vector<vector<int>> pref;
int h, w;

int get(int row, int col, int sz) {
    if (sz == 0) return 0;
    int top_x = row + sz - 1, top_y = col + sz - 1;

    if (top_x >= h || top_y >= w) return 1;

    int sum = pref[top_x][top_y];
    if (row > 0) sum -= pref[row - 1][top_y];
    if (col > 0) sum -= pref[top_x][col - 1];
    if (row > 0 && col > 0) sum += pref[row - 1][col - 1];
    return sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> h >> w >> n;

    pref = vector<vector<int>>(h, vector<int>(w));

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        pref[x][y] = 1;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i - 1 >= 0) pref[i][j] += pref[i - 1][j];
            if (j - 1 >= 0) pref[i][j] += pref[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0) pref[i][j] -= pref[i - 1][j - 1];
        }
    }

    int total = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int l = 0, r = max(h, w) + 1;
            int ans = 0;
            while (l <= r) {
                int mp = (l + r) / 2;
                if (!get(i, j, mp)) {
                    ans = mp;
                    l = mp + 1;
                } else r = mp - 1;
            }
            total += ans;
        }
    }
    cout << total << '\n';
}

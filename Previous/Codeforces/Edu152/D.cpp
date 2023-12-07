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

int n;
vector<int> a, col;

void col_left(int idx) {
    col[idx] = 1;
    if (!a[idx]) return;
    a[idx]--;
    if (idx > 0) col_left(idx - 1);
}

void col_right(int idx) {
    col[idx] = 1;
    if (!a[idx]) return;
    a[idx]--;
    if (idx < n - 1) col_right(idx + 1);
}

int cnt_arr(int l, int r) {
    int cnt_0 = 0;
    int group_1 = 0;
    for (int i = l; i <= r; i++) {
        cnt_0 += a[i] == 0;
        if (a[i] == 1 && (i == l || a[i - 1] != 1)) {
            group_1++;
        }
    }
    return max(cnt_0, group_1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("tests.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int tt;
//    cin >> tt;
tt = 1;

    while (tt--) {
        cin >> n;
        a = col = vector<int>(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 2 && !col[i]) {
                ans++;
                col_left(i);
                col_right(i);
            }
        }
        int l = -1;
        for (int i = 0; i < n; i++) {
            if (!col[i] && l == -1) {
                l = i;
            } else if (col[i] && l != -1) {
                ans += cnt_arr(l, i - 1);
                l = -1;
            }
        }
        if (l != -1) ans += cnt_arr(l, n - 1);
        cout << ans << '\n';

    }
}

/*
 * 5
1 1 0 1 1
Expected: 2
Got: 1
 */
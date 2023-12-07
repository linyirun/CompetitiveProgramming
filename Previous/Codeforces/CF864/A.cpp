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

int n, m;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
bool is_safe(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int check(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int dest_x = x + dx[i], dest_y = y + dy[i];
        if (is_safe(dest_x, dest_y)) cnt++;
    }
    return cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int  x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        cout << min(check(x1, y1), check(x2, y2)) << '\n';
    }

}

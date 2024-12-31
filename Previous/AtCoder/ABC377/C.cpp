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

bool is_valid(int row, int col, int n) {
    return row >= 1 && col >= 1 && row <= n && col <= n;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2, 0};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1, 0};

    int n, m;
    cin >> n >> m;

    set<pii> s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        for (int j = 0; j < 9; j++) {
            int dest_x = x + dx[j], dest_y = y + dy[j];
            if (is_valid(dest_x, dest_y, n)) {
                s.insert({dest_x, dest_y});
            }
        }

    }

    cout << n * n - s.size() << '\n';
}

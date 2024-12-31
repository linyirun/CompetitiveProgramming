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

vector<vector<char>> grid(8, vector<char>(8));
vector<vector<bool>> can(8, vector<bool>(8, true));

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                for (int k = 0; k < 8; k++) {
                    can[i][k] = can[k][j] = false;
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cnt += can[i][j];
        }
    }
    cout << cnt << '\n';


}

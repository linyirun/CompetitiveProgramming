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

    int n;
    cin >> n;

    int MX = 101;
    vector<vector<bool>> grid(MX, vector<bool>(MX));

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int row = a; row < b; row++) {
            for (int col = c; col < d; col++) {
                grid[row][col] = true;
            }
        }
    }



    int total = 0;
    for (int i = 0; i < MX; i++) {
        for (int j = 0; j < MX; j++) {
//            cout << grid[i][j] << ' ';
            total += grid[i][j];
        }
//        cout << '\n';
    }
    cout << total << '\n';
}

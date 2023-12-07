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
        int n, k;
        cin >> n >> k;

        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i * 2 < n; i++) {
            int num_moves = 2 * (n - 2 * i) - 1;

            int first_row = i, first_col = i;
            int second_row = n - i - 1, second_col = n - i - 1;
            for (int j = 0; j < num_moves - 1; j++) {
                if (grid[first_row][first_col] != grid[second_row][second_col]) k--;
                if (first_col != n - i - 1) {
                    first_col++;
                    second_col--;
                } else {
                    first_row++;
                    second_row--;
                }
            }
        }

        if (k < 0 || (n % 2 == 0 && k % 2 == 1)) cout << "NO\n";
        else cout << "YES\n";
    }
}
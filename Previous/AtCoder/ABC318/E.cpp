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

    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < pos[i].size(); j++) {
            int curr = pos[i][j] - pos[i][j - 1] - 1;
            cnt += (j * (pos[i].size() - j)) * curr;
        }
    }
    cout << cnt << '\n';
}

/*
6
1 2 1 3 4 1

 anything before * anything after

 13
9 7 11 7 3 8 1 13 11 11 11 6 13
7: 1
11: 15
13:
 */
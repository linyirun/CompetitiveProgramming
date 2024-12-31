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
int solve(vector<int> &a) {
    vector<int> ind(n);
    for (int i = 0; i < n; i++) {
        ind[a[i] - 1] = i;
    }
    int curr_pos = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (ind[i] < curr_pos) {
            cnt++;
        }
        curr_pos = ind[i];
    }
    return cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        swap(a[x - 1], a[y - 1]);
        cout << solve(a) << '\n';
    }

}

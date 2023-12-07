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

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m), sorted(n + m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        sorted[i + n] = b[i];
    }
    sort(sorted.begin(), sorted.end());
    map<int, int> pos;
    for (int i = 0; i < n + m; i++) {
        pos[sorted[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) cout << pos[a[i]] << ' ';
    cout << '\n';
    for (int i = 0; i < m; i++) cout << pos[b[i]] << ' ';
    cout << '\n';
}


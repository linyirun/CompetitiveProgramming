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

vector<pair<pii, int>> a;
int cmp(pair<pii, int> &p1, pair<pii, int> &p2) {
    int n1 = p1.first.first, d1 = p1.first.second;
    int n2 = p2.first.first, d2 = p2.first.second;

    if (n1 * d2 == n2 * d1) return p1.second < p2.second;
    else return n1 * d2 > n2 * d1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    a = vector<pair<pii, int>>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].first.second += a[i].first.first;
        a[i].second = i;
    }

    sort(a.begin(), a.end(), cmp);
//    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) cout << a[i].second + 1 << ' ';
    cout << '\n';




}

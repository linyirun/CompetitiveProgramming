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

    map<int, int> freq;

    for (int i = 0; i < 10 * n; i++) {
        for (int j = 0; j < 5; j++) {
            int c;
            cin >> c;
            freq[c]++;
        }
    }

    vector<int> cnt;
    for (pii p : freq) {
        if (p.second > 2 * n) {
            cnt.push_back(p.first);
        }
    }
    sort(cnt.begin(), cnt.end());
    if (cnt.size() == 0) {
        cout << "-1\n";
    } else {
        for (int i : cnt) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

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

    vector<int> a(n), sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = i + 1;
    }

    if (n == 2) {
        if (a[0] == 1 && a[1] == 2) {
            cout << "Yes\n";
            cout << "0\n";
        } else {
            cout << "No\n";
        }
        return 0;
    }

    vector<pii> moves;
    for (int i = n; i >= 1; i--) {
        int pos = -1;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) pos = j;
        }
        if (pos + 1 == i) continue;

        if (!pos) {
            swap(a[0], a[1]);
            swap(a[1], a[2]);
            moves.push_back({0, 1});
            pos = 1;
        }
        
        moves.push_back({pos - 1, n - 2});
        int first = a[pos - 1], second = a[pos];
        a.erase(a.begin() + pos - 1);
        a.erase(a.begin() + pos - 1);

        a.insert(--a.end(), first);
        a.insert(--a.end(), second);
    }

    if (a == sorted) {
        cout << "Yes\n";
        cout << moves.size() << '\n';
        for (pii p : moves) cout << p.first << ' ' << p.second << '\n';
    } else {
        cout << "No\n";
    }

}

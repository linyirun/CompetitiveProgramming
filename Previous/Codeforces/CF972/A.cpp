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
    vector<char> ch = {'a', 'e', 'i', 'o', 'u'};
    while (tt--) {
        int n;
        cin >> n;

        for (int i = 0; i < 5; i++) {
            int take = n / 5;
            if (i < n % 5) take++;
            for (int j = 0; j < take; j++) {
                cout << ch[i];
            }
        }
        cout << '\n';
    }
}

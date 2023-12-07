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

    freopen("tests.txt", "r", stdin);

    int tt;
    cin >> tt;

    vector<int> tests_n(tt);
    vector<vector<int>> tests(tt, vector<int>(4));

    for (int i = 0; i < tt; i++) {
        int n;
        cin >> n;
        tests_n[i] = n;

        for (int j = 0; j < n; j++) {
            cin >> tests[i][j];
        }
    }

    vector<int> n1(tt), n2(tt);
    vector<vector<int>> ans1(tt), ans2(tt);
    freopen("out.txt", "r", stdin);
    for (int i = 0; i < tt; i++) {
        cin >> n1[i];
        ans1[i] = vector<int>(n1[i]);
        for (int j = 0; j < n1[i]; j++) {
            cin >> ans1[i][j];
        }
    }

    freopen("out2.txt", "r", stdin);
    for (int i = 0; i < tt; i++) {
        cin >> n2[i];
        ans2[i] = vector<int>(n2[i]);
        for (int j = 0; j < n2[i]; j++) {
            cin >> ans2[i][j];
        }
    }

    for (int i = 0; i < tt; i++) {
//        cout << ans1[i] << ' ' << ans2[i] << '\n';
        if (ans1[i] != ans2[i]) {
            cout << "Failed on test case: " << '\n';

            cout << tests[i].size() << '\n';
            for (int j : tests[i]) cout << j << ' ';
            cout << '\n';

//            cout << "Expected: " << ans2[i] << '\n';
//            cout << "Got: " << ans1[i] << '\n';

            cout << "Expected: ";
            for (int j = 0; j < tests_n[i]; j++) {
                cout << ans2[i][j] << ' ';
            } cout << '\n';
            cout << "Got: ";
            for (int j = 0; j < tests_n[i]; j++) {
                cout << ans1[i][j] << ' ';
            } cout << '\n';
        }
    }

}

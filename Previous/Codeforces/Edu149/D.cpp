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
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> ans(n, -1);
        set<int> open_ind, closed_ind;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') open_ind.insert(i);
            else closed_ind.insert(i);
        }

        if (open_ind.size() != closed_ind.size()) {
            cout << "-1\n";
            continue;
        }

        int color = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) continue;
            color++;
            if (s[i] == '(') {
                while (!open_ind.empty()) {
                    int curr_ind = *open_ind.begin();

                    auto it = closed_ind.upper_bound(curr_ind);
                    if (it == closed_ind.end()) break;
                    int next_brac = *it;
                    open_ind.erase(open_ind.begin());
                    closed_ind.erase(next_brac);
                    ans[curr_ind] = ans[next_brac] = color;
                }
            } else {
                while (!closed_ind.empty()) {
                    int curr_ind = *closed_ind.begin();

                    auto it = open_ind.upper_bound(curr_ind);
                    if (it == open_ind.end()) break;
                    int next_brac = *it;
                    closed_ind.erase(closed_ind.begin());
                    open_ind.erase(next_brac);
                    ans[curr_ind] = ans[next_brac] = color;
                }
            }
        }

        cout << color << '\n';
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << "\n";


    }
}

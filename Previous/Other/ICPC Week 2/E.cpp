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

//    freopen("tests.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int tt;
//    cin >> tt;
tt = 1;
    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n);
        set<pii > s; // {value, ind}
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert({a[i], i});
        }

        auto it = s.begin();
        while (true) {
            if (it == s.end() || ++it == s.end()) break;
            it--;
            auto it2 = it;

            pii curr = *it;
            pii nxt = *(++it2);
            if (nxt.first == curr.first) {
                auto it3 = it2;
                bool change = false;
                it3++;
                pii to_find = {-1, -1};
                if (it3 != s.end()) {
                    change = true;
                    to_find = *it3;
                }
                s.erase(nxt);
                s.erase(curr);
                s.insert({2 * curr.first, nxt.second});
                if (!change) it = s.begin();
                else it = s.lower_bound({curr.first, -1});
            } else it++;
        }

        vector<pii > res;
        for (pii p: s) {
            res.push_back({p.second, p.first});
        }
        sort(res.begin(), res.end());
        cout << res.size() << '\n';
        for (pii p: res) cout << p.second << ' ';
        cout << '\n';
    }


}
/*
4
1 1 2 2
Expected: 4 2 2 4
Got: 2 4 2 4
 */

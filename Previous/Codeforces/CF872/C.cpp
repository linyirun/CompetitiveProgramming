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
        int n, m;
        cin >> n >> m;

        set<int> s;
        int cnt_left = 0, cnt_right = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
//x = -1;
            if (x == -1) cnt_left++;
            else if (x == -2) cnt_right++;
            else {
                s.insert(x);
            }
        }

        vector<int> a;
        for (int i : s) a.push_back(i);

        int best = max(cnt_left, cnt_right) + s.size();
        for (int i = 0; i < s.size(); i++) {
            int curr = s.size() + min(cnt_left, a[i] - i - 1) + min(cnt_right, m - a[i] - ((int) s.size() - i - 1));
            best = max(curr, best);
        }

        cout << min(best, m) << '\n';


    }
}

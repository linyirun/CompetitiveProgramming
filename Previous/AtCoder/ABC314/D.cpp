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
    string s;
    cin >> n >> s;
    int q;
    cin >> q;

    vector<pair<int, pair<int, char>>> queries(q);
    int last = q;
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second.first >> queries[i].second.second;
        if (queries[i].first == 2 || queries[i].first == 3) last = i;
//        else if (last == q) {
//            s[queries[i].second.first - 1] = queries[i].second.second;
//        }
    }

    for (int i = 0; i < q; i++) {
        if (i < last && queries[i].first == 1) {
            s[queries[i].second.first - 1] = queries[i].second.second;
        }
    }

    for (int i = last; i < q; i++) {
        int t = queries[i].first, x = queries[i].second.first;
        x--;
        char c = queries[i].second.second;

        if (t == 2) {
            for (char &ch : s) ch = tolower(ch);
        } else if (t == 3) {
            for (char &ch : s) ch = toupper(ch);
        } else s[x] = c;
    }
    cout << s << '\n';

}

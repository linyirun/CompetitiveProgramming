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

    int L, n1, n2;
    cin >> L >> n1 >> n2;

    int curr_l = 0;
    vector<pair<pii, int>> segments(n1);
    for (int i = 0; i < n1; i++) {
        int v, l;
        cin >> v >> l;
        segments[i] = {{curr_l, curr_l + l - 1}, v};
        curr_l += l;
    }

    int total = 0;
    curr_l = 0;
    int ptr = 0;
    for (int i = 0; i < n2; i++) {
        int v, l;
        cin >> v >> l;
        int seg_end = curr_l + l - 1;

        while (ptr < n1 && segments[ptr].first.first <= seg_end) {
            if (v == segments[ptr].second) {
                total += min(seg_end, segments[ptr].first.second) - max(curr_l, segments[ptr].first.first) + 1;
            }
            if (segments[ptr].first.second <= seg_end) {
                ptr++;
            } else break;
        }

        curr_l = seg_end + 1;
    }
    cout << total << '\n';
}

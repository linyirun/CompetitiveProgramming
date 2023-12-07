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

    int n, k, c;
    cin >> n >> k >> c;

    vector<pii> inelig;

    vector<pii> ans(k);
    // {rank, id}
    vector<int> cnt(n + 1);

    int curr = 0;
    for (int rank = 0; rank < n; rank++) {
        int id, school;
        cin >> id >> school;
        if (cnt[school] >= c) {
            inelig.push_back({rank, id});
        } else {
            if (curr < k) {
                ans[curr++] = {rank, id};
                cnt[school]++;
            }
        }
    }
    int ptr = 0;
    while (curr < k) {
        ans[curr++] = inelig[ptr++];
    }

    sort(ans.begin(), ans.end());
    for (pii i : ans) cout << i.second << '\n';
}

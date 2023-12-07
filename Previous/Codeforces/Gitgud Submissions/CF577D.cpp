#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

#define int ll
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INF = 1e18;

const int MAX = 3e5 + 2;

vector<int> leftmost(MAX, LLONG_MAX), rightmost(MAX, LLONG_MIN);

int best_dist(int row, int start, int end) {
    int dist_a = abs(leftmost[row] - start);
    dist_a += abs(rightmost[row] - leftmost[row]) + abs(rightmost[row] - end);

    int dist_b = abs(rightmost[row] - start);
    dist_b += abs(rightmost[row] - leftmost[row]) + abs(leftmost[row] - end);
    return min(dist_a, dist_b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<pii> treasures(k);
    int mx_x = 0;
    for (int i = 0; i < k; i++) {
        cin >> treasures[i].first >> treasures[i].second;
        mx_x = max(mx_x, treasures[i].first);
    }
    sort(treasures.begin(), treasures.end());

    int num_rows = -1;
    vector<vector<int>> a(MAX);


    for (int i = 0; i < k; i++) {
//        if (!i || treasures[i].first != treasures[i - 1].first) {
//            num_rows++;
//        }
        num_rows = treasures[i].first;
        leftmost[num_rows] = min(leftmost[num_rows], treasures[i].second);
        rightmost[num_rows] = max(rightmost[num_rows], treasures[i].second);
        a[num_rows].push_back(treasures[i].second); // cols should be sorted already
    }

    vector<int> safe_cols(q);
    for (int i = 0; i < q; i++) cin >> safe_cols[i];
    sort(safe_cols.begin(), safe_cols.end());


    vector<int> safe_right(MAX, m + 1), safe_left(MAX, -1);
    for (int col : safe_cols) {
        safe_left[col] = col;
        safe_right[col] = col;
    }
    for (int i = 1; i < MAX; i++) {
        safe_left[i] = max(safe_left[i], safe_left[i - 1]);
    }
    for (int i = MAX - 2; i >= 0; i--) {
        safe_right[i] = min(safe_right[i], safe_right[i + 1]);
    }


    if (leftmost[1] == LLONG_MAX) leftmost[1] = rightmost[1] = 1;
    // min time to reach an endpoint from each row
    vector<vector<int>> dp(MAX, vector<int>(2, INF));

    set<pii> prev_cols; // {col, cost}
    prev_cols.insert({1, 0});
    for (int i = 1; i <= num_rows; i++) {
        if (leftmost[i] == LLONG_MAX) {
            set<pii> ne;
            for (auto p : prev_cols) {
                p.second++;
                ne.insert(p);
            }
            prev_cols = ne;
            dp[i][0] = dp[i - 1][0] + 1, dp[i][1] = dp[i - 1][1] + 1;
            continue;
        }
        for (pii p : prev_cols) {
            int col = p.first, cost = p.second;

            dp[i][0] = min(dp[i][0], best_dist(i, col, leftmost[i]) + cost);
            dp[i][1] = min(dp[i][1], best_dist(i, col, rightmost[i]) + cost);
        }

        prev_cols.clear();

        if (safe_left[leftmost[i]] != -1) prev_cols.insert({safe_left[leftmost[i]], dp[i][0] + abs(leftmost[i] - safe_left[leftmost[i]]) + 1});
        if (safe_right[leftmost[i]] != m + 1) prev_cols.insert({safe_right[leftmost[i]], dp[i][0] + abs(leftmost[i] - safe_right[leftmost[i]]) + 1});
        if (safe_left[rightmost[i]] != -1) prev_cols.insert({safe_left[rightmost[i]], dp[i][1] + abs(rightmost[i] - safe_left[rightmost[i]]) + 1});
        if (safe_right[rightmost[i]] != m + 1) prev_cols.insert({safe_right[rightmost[i]], dp[i][1] + abs(rightmost[i] - safe_right[rightmost[i]]) + 1});
    }

    cout << min(dp[num_rows][0], dp[num_rows][1]) << '\n';


}

/*
3 3 4 2
1 1
2 1
3 1
2 3
2 3

5 3 5 2
1 3
2 1
3 3
4 1
5 3
1 3
 */
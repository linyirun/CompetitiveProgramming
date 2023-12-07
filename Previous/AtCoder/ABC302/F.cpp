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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n);

    vector<int> contains_1, contains_m;

    // For an element i, which a set of the indices that contain i
    vector<set<int>> contains(m + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s[i].resize(a);
        bool has_one = false, has_m = false;
        for (int j = 0; j < a; j++) {
            cin >> s[i][j];
            if (s[i][j] == 1) has_one = true;
            if (s[i][j] == m) has_m = true;
            contains[s[i][j]].insert(i);
        }
        if (has_one) contains_1.push_back(i);
        if (has_m) contains_m.push_back(i);
    }

    vector<int> dist(n + 1, INF);

    queue<int> q;
    for (int ind : contains_1) {
        for (int i : contains_1) {
            for (int elem : s[i]) {
                contains[elem].erase(ind);
            }
        }
        dist[ind] = 0;
        q.push(ind);
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i : s[curr]) {
            vector<int> to_erase;
            for (int dest : contains[i]) {
                if (dest != curr && dist[dest] > dist[curr] + 1) {
                    dist[dest] = dist[curr] + 1;
                    q.push(dest);
                    to_erase.push_back(dest);
                }
            }
            for (int erase : to_erase) {
                for (int elem : s[erase]) {
                    if (contains[elem].count(erase)) contains[elem].erase(erase);
                }
            }
        }
    }

    int best = INF;
    for (int i : contains_m) {
        best = min(best, dist[i]);
    }

    if (best == INF) cout << "-1\n";
    else cout << best << '\n';


}

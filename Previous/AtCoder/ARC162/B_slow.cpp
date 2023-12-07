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

set<vector<int>> vis;
vector<int> sorted;
vector<vector<int>> res;

vector<pii> seq;
int n;

int MAX_DEPTH = 100;

void recur(vector<int> a, vector<pii> moves, int depth, vector<vector<int>> v) {
    if (a == sorted) {
        if (seq.empty() || moves.size() < seq.size()) {
            seq = moves;
            res = v;
        }
        return;
    }
    if (depth >= MAX_DEPTH || vis.count(a)) return;
    vis.insert(a);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 2; j++) {
            vector<pii> new_moves = moves;
            vector<int> new_arr = a;
            vector<vector<int>> new_v = v;

            int first = a[i], second = a[i + 1];
            new_arr.erase(new_arr.begin() + i);
            new_arr.erase(new_arr.begin() + i);

            new_arr.insert(new_arr.begin() + j, second);
            new_arr.insert(new_arr.begin() + j, first);

            new_v.push_back(new_arr);
            new_moves.push_back({i, j});
            recur(new_arr, new_moves, depth + 1, new_v);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<int> a(n);
    sorted = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = i + 1;
    }

    recur(a, {}, 0, {a});

    cout << seq.size() << '\n';
    for (pii p : seq) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }

    for (vector<int> &v : res) {
        for (int i : v) cout << i << ' ';
        cout << '\n';
    }

}
/*
7
7 3 4 2 5 1 6

not solvable
7
7 3 4 2 1 5 6
 */

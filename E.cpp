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

vector<int> order(26);
int ptr = 0;
bool can = true;

vector<vector<int>> adj(26);

vector<bool> vis(26), in_stack(26);

void dfs(int node) {
    // to topological sort this graph, and place it into order
    in_stack[node] = true;
    for (int child : adj[node]) {
        if (in_stack[child]) {
            can = false;
            return;
        } else if (!vis[child]) dfs(child);
    }
    order[ptr++] = node;
    in_stack[node] = false;
    vis[node] = true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++) cin >> strs[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= min(strs[i].size(), strs[i - 1].size()); j++) {
            if (j == min(strs[i].size(), strs[i - 1].size())){
                if (strs[i - 1].size() > strs[i].size()) can = false;
                else break;
            }

            if (strs[i][j] != strs[i - 1][j]) {
                // then this means that strs[i - 1][j] < strs[i][j];
                int first_char = strs[i - 1][j] - 'a';
                int second_char = strs[i][j] - 'a';
//                cout << first_char << ' ' << second_char << '\n';
                adj[second_char].push_back(first_char);


                break; // go to next
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!vis[i]) dfs(i);
    }

    if (!can) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        cout << (char) (order[i] + 'a');
    }


}

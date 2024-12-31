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

int n;
vector<int> col, total_freq;
vector<vector<int>> adj;

map<pii, int> edge_to_idx;
vector<int> edge_pairs;



int dfs(int node, int par, vector<int> **ret_indices, map<int, int> **ret_freq) {
    // ret_indices, ret_freq should be empty
    if (node != par && adj[node].size() == 1) {
        // Leaf node
        vector<int> ind = {node};
        map<int, int> new_freq;
        new_freq[col[node]] = 1;

        *ret_indices = &ind;
        *ret_freq = &new_freq;

        edge_pairs[edge_to_idx[{node, par}]] = total_freq[col[node]] - 1;
        return total_freq[col[node]] - 1;
    }

    // Not leaf
    int biggest_sz = 0, biggest_idx = -1;
    vector<vector<int>*> ret_ind_arr;
    vector<map<int, int>*> ret_freq_arr;
    vector<int> pair_cnts;

    int idx = 0;
    for (int dest : adj[node]) {
        if (dest == par) continue;

        vector<int> * inds;
        map<int, int> * freq;

        pair_cnts.push_back(dfs(dest, node, &inds, &freq));

        if ((*inds).size() > biggest_sz) {
            biggest_idx = idx;
            biggest_sz = inds->size();
        }

        ret_ind_arr.push_back(inds);
        ret_freq_arr.push_back(freq);

        idx++;
    }

    (*ret_freq) = ret_freq_arr[biggest_idx];
    (*ret_indices) = ret_ind_arr[biggest_idx];

    int curr_cnt = pair_cnts[biggest_idx];

    map<int, int> freq_added_nodes;
    // Merge indices of all smaller subarrs
    for (int i = 0; i < ret_ind_arr.size(); i++) {
        if (i == biggest_idx) continue;
        for (int dest : *ret_ind_arr[i]) {
            freq_added_nodes[col[dest]]++;
            (**ret_indices).push_back(dest);
        }
    }

    freq_added_nodes[col[node]]++;
    (**ret_indices).push_back(node);

    for (auto &p : freq_added_nodes) {
        int curr_col = p.first, new_freq_count = p.second;
        int not_in_subtree = total_freq[curr_col] - ((**ret_freq)[curr_col] + new_freq_count);
        curr_cnt += (new_freq_count * not_in_subtree) - (new_freq_count * (**ret_freq)[curr_col]);
        (**ret_freq)[curr_col] += new_freq_count;
    }

    if (node != par) {
        edge_pairs[edge_to_idx[{node, par}]] = curr_cnt;
    }
    return curr_cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    edge_pairs = vector<int>(n - 1);

    col = total_freq = vector<int>(n);
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> col[i];
        col[i]--;
        total_freq[col[i]]++;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        edge_to_idx[{u, v}] = edge_to_idx[{v, u}] = i;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ret_indices;
    map<int, int> ret_freq;

    vector<int> *ret_indices_ptr = & ret_indices;
    map<int, int> *ret_freq_ptr = &ret_freq;
    dfs(0, 0, &ret_indices_ptr, &ret_freq_ptr);

    for (int i : edge_pairs) {
        cout << i << '\n';
    }


}

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

// segtree (sum)
struct segtree {
    vector<ll> seg;
    int n, sz;

    segtree(int N, vector<ll> &v) {
        n = N;
        sz = 1;
        while (sz < 4 * n) sz *= 2;
        seg.assign(sz, 0);
        build(0, 0, n - 1, v);
    }

    void build(int idx, int l, int r, vector<ll> &v) {
        if (l == r) {
            seg[idx] = v[l];
            return;
        }
        int mp = (l + r) / 2;
        build(2 * idx + 1, l, mp, v);
        build(2 * idx + 2, mp + 1, r, v);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void set(int idx, ll v) {
        set(0, 0, n - 1, idx, v);
    }

    void set(int idx, int l, int r, int setIdx, ll v) {
        if (l == r) {
            seg[idx] = v;
            return;
        }
        int mp = (l + r) / 2;
        if (setIdx <= mp) set(2 * idx + 1, l, mp, setIdx, v);
        else set(2 * idx + 2, mp + 1, r, setIdx, v);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    ll get(int l, int r) {
        return get(0, 0, n - 1, l, r);
    }

    ll get(int idx, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return INF;
        else if (l >= ql && r <= qr) return seg[idx];
        int mp = (l + r) / 2;
        return min(get(2 * idx + 1, l, mp, ql, qr), get(2 * idx + 2, mp + 1, r, ql, qr));
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> important;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        important.insert(x);
        important.insert(y);
        important.insert(z);
        a[i] = {x, y, z};
        sort(a[i].begin(), a[i].end());
    }

    map<int, int> mp;
    int ptr = 1;
    for (int i : important) {
        mp[i] = ptr++;
    }
    ptr += 100;

    // Compress coordinates
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = mp[a[i][j]];
        }
    }

    vector<int> v(ptr, INF);
    segtree seg(ptr, v);
//    seg.set(0, ptr - 1, INF);

    bool can = false;

    vector<int> to_erase;
    for (int i = 0; i < n; i++) {
        if (i && a[i][0] != a[i - 1][0]) {
            for (int ind : to_erase) {
                if (a[ind][2] < seg.get(a[ind][1], a[ind][1]))
                    seg.set(a[ind][1], a[ind][2]);
            }
            to_erase.clear();
        }

        if (seg.get(0, a[i][1] - 1) < a[i][2]) {
            can = true;
            break;
        }
        to_erase.push_back(i);
    }

    if (can) cout << "Yes\n";
    else cout << "No\n";


}

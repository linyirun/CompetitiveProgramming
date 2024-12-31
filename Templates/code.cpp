#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double

#define MOD 1000000007

using namespace std;


// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Add this to CMake
set(CMAKE_EXE_LINKER_FLAGS "-ld_classic")


int main() {
    fastIO;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
    }
}

// rng
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// usaco
//    freopen("diamond.in", "r", stdin);
//    freopen("diamond.out", "w", stdout);

// factorial
ll fac[MAX + 1];
ll inv[MAX + 1];
fac[0] = inv[0] = 1;
for (ll i = 1; i <= MAX; i++) {
fac[i] = i * fac[i - 1];
fac[i] %= MOD;
inv[i] = binpow(fac[i], MOD - 2);
}

// binexp
ll binpow(ll base, ll exp) {
    if (exp == 0) return 1;
    ll tmp = binpow(base, exp / 2);
    if (exp % 2 == 1) return (tmp * tmp) % MOD * base % MOD;
    else return (tmp * tmp) % MOD;
}

// gcd
int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    if (a == 0) return b;
    return gcd(b, a % b);
}

// dsu
struct DSU {
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            sz[i] = 1;
            par[i] = i;
        }
    }

    int find_par(int x) {
        if (par[x] == x) return x;
        else return par[x] = find_par(par[x]);
    }

    bool merge(int a, int b) {
        a = find_par(a);
        b = find_par(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        return true;
    }
};

template<ll M>
struct modint {

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }

    ll v; modint(ll n = 0) : v(n%M) { v += (M&(0-(v<0))); }

    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }

    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};


// msb
int msb(int n) {
    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) return i;
    }
    return -1;
}

// popcountll
int popcountll(ll x) {
    int cnt = 0;
    for (ll i = 63; i >= 0; i--) {
        if (x & (1LL << i)) cnt++;
    }
    return cnt;
}

int popcount(int x) {
    int cnt = 0;
    for (int i = 31; i >= 0; i--) {
        if (x & (1 << i)) cnt++;
    }
    return cnt;
}
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
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
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
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    ll get(int l, int r) {
        return get(0, 0, n - 1, l, r);
    }

    ll get(int idx, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        else if (l >= ql && r <= qr) return seg[idx];
        int mp = (l + r) / 2;
        return get(2 * idx + 1, l, mp, ql, qr) + get(2 * idx + 2, mp + 1, r, ql, qr);
    }
};

// segtree (mn/add w/ lazy prop)
struct segtree {
    vector<int> mn, lazy;
    int n, sz;

    segtree(int N) {
        n = N;
        sz = 1;
        while (sz < 4 * n) sz *= 4;
        mn.assign(sz, 0);
        lazy.assign(sz, 0);
    }

    void push_down(int idx) {
        lazy[LEFT] += lazy[idx];
        mn[LEFT] += lazy[idx];
        lazy[RIGHT] += lazy[idx];
        mn[RIGHT] += lazy[idx];
        lazy[idx] = 0;
    }

    // add to a segment
    void add(int l, int r, int val) {
        add(0, 0, n - 1, l, r, val);
    }

    void add(int idx, int l, int r, int ql, int qr, int val) {
        if (l > qr || r < ql) return;
        else if (l >= ql && r <= qr) {
            lazy[idx] += val;
            mn[idx] += val;
            return;
        }

        int mp = (l + r) / 2;
        push_down(idx);
        add(LEFT, l, mp, ql, qr, val);
        add(RIGHT, mp + 1, r, ql, qr, val);
        mn[idx] = min(mn[LEFT], mn[RIGHT]);
    }


    int get(int l, int r) {
        return get(0, 0, n - 1, l, r);
    }

    int get(int idx, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return INT_MAX;
        else if (l >= ql && r <= qr) return mn[idx];
        int mp = (l + r) / 2;
        push_down(idx);
        return min(get(LEFT, l, mp, ql, qr), get(RIGHT, mp + 1, r, ql, qr));

    }
};

// segtree (max)
struct segtree {
    vector<int> seg;
    int n, sz;

    int NO_OP = -INF;

    int op(int a, int b) {
        return max(a, b);
    }

    segtree(int n, vector<int> &a) {
        this->n = n;
        sz = 1;
        while (sz < 4 * n) sz *= 2;
        seg.assign(sz, 0);
        build(0, 0, n - 1, a);
    }

    void build(int idx, int l, int r, vector<int> &a) {
        if (l == r) {
            seg[idx] = a[l];
            return;
        }
        int mp = (l + r) / 2;
        build(2 * idx + 1, l, mp, a);
        build(2 * idx + 2, mp + 1, r, a);
        seg[idx] = op(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int get(int l, int r) {
        return get(0, 0, n - 1, l, r);
    }

private:
    int get(int idx, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return NO_OP;
        else if (l >= ql && r <= qr) return seg[idx];
        int mp = (l + r) / 2;
        return op(get(2 * idx + 1, l, mp, ql, qr), get(2 * idx + 2, mp + 1, r, ql, qr));
    }
};

// range set range min
struct segtree {
    vector<int> lazy, arr;
    int n, sz;

    // lazy arr: -1 -> no operation, 0 -> set to 0, 1: set to 1
    const int NO_OP = -1;
    const int MAX = 10000000;

    segtree(int n) {
        this->n = n;
        sz = 1;
        while (sz < 4 * n) sz *= 2;
        lazy.assign(sz, -1);
        arr.assign(sz, 0);
    }

    void set(int l, int r, int op) {
        set(0, 0, n - 1, l, r, op);
    }

    void set(int idx, int l, int r, int ql, int qr, int op) {
        if (l > qr || r < ql) return;
        else if (l >= ql && r <= qr) {
            arr[idx] = op;
            lazy[idx] = op;
            return;
        }
        if (lazy[idx] != NO_OP && l != r) {
            // propagate
            lazy[LEFT] = lazy[RIGHT] = arr[LEFT] = arr[RIGHT] = lazy[idx];
            lazy[idx] = NO_OP;
        }
        int mp = (l + r) / 2;
        set(LEFT, l, mp, ql, qr, op);
        set(RIGHT, mp + 1, r, ql, qr, op);
        arr[idx] = min(arr[LEFT], arr[RIGHT]);
    }

    int get_min(int l, int r) {
        return get_min(0, 0, n - 1, l, r);
    }

    int get_min(int idx, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return MAX;
        else if (l >= ql && r <= qr) {
            return arr[idx];
        }
        if (lazy[idx] != NO_OP && l != r) {
            // propagate
            lazy[LEFT] = lazy[RIGHT] = arr[LEFT] = arr[RIGHT] = lazy[idx];
            lazy[idx] = NO_OP;
        }
        int mp = (l + r) / 2;
        return min(get_min(LEFT, l, mp, ql, qr), get_min(RIGHT, mp + 1, r, ql, qr));

    }
};

// range set, range add, range sum
struct segtree {
    vector<ll> arr, lazy_add, lazy_assign;

    const ll NO_OP = -1;
    int n, sz;

    segtree(int n) {
        this->n = n;
        sz = 1;
        while (sz < 4 * n) sz *= 2;
        arr.assign(sz, 0);
        lazy_add.assign(sz, -1);
        lazy_assign.assign(sz, -1);
    }

    void merge_assign(int idx, int l, int r, ll val) {
        lazy_add[idx] = NO_OP;
        arr[idx] = (ll) (r - l + 1) * val;
        lazy_assign[idx] = val;
    }

    void merge_add(int idx, int l, int r, ll val) {
        arr[idx] += (ll) (r - l + 1) * val;
        if (lazy_assign[idx] != NO_OP) {
            lazy_assign[idx] += val;
        } else {
            if (lazy_add[idx] == NO_OP) {
                lazy_add[idx] = val;
            } else lazy_add[idx] += val;
        }
    }

    void propagate(int idx, int l, int r) {
        int mp = (l + r) / 2;
        if (l == r) return;
        if (lazy_assign[idx] != NO_OP) {
            merge_assign(LEFT, l, mp, lazy_assign[idx]);
            merge_assign(RIGHT, mp + 1, r, lazy_assign[idx]);
            lazy_assign[idx] = NO_OP;
        } else if (lazy_add[idx] != NO_OP) {
            merge_add(LEFT, l, mp, lazy_add[idx]);
            merge_add(RIGHT, mp + 1, r, lazy_add[idx]);
            lazy_add[idx] = NO_OP;
        }
    }

    ll get_sum(int l, int r) {
        return get_sum(0, 0, n - 1, l, r);
    }

    ll get_sum(int idx, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        else if (l >= ql && r <= qr) return arr[idx];
        propagate(idx, l, r);
        int mp = (l + r) / 2;
        return get_sum(LEFT, l, mp, ql, qr) + get_sum(RIGHT, mp + 1, r, ql, qr);
    }

    void range_add(int l, int r, ll v) {
        range_add(0, 0, n - 1, l, r, v);
    }

    void range_add(int idx, int l, int r, int ql, int qr, ll v) {
        if (l > qr || r < ql) return;
        else if (l >= ql && r <= qr) {
            merge_add(idx, l, r, v);
            return;
        }
        propagate(idx, l, r);
        int mp = (l + r) / 2;
        range_add(LEFT, l, mp, ql, qr, v);
        range_add(RIGHT, mp + 1, r, ql, qr, v);
        arr[idx] = arr[LEFT] + arr[RIGHT];
    }

    void range_assign(int l, int r, ll v) {
        range_assign(0, 0, n - 1, l, r, v);
    }

    void range_assign(int idx, int l, int r, int ql, int qr, ll v) {
        if (l > qr || r < ql) return;
        else if (l >= ql && r <= qr) {
            merge_assign(idx, l, r, v);
            return;
        }
        int mp = (l + r) / 2;
        propagate(idx, l, r);
        range_assign(LEFT, l, mp, ql, qr, v);
        range_assign(RIGHT, mp + 1, r, ql, qr, v);
        arr[idx] = arr[LEFT] + arr[RIGHT];
    }
};

// BIT
struct BIT {
    vector<int> bit;
    int n;

    BIT(int n) {
        bit.assign(n + 1, 0);
        this->n = n + 1;
    }

    int sum(int idx) {
        int res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int add) {
        for (++idx; idx < n; idx += idx & -idx) {
            bit[idx] += add;
        }
    }
};

// alternate
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define fl cout.flush()

const int MOD = 1000000007;

using namespace std;
const int INF = 1000000;

void solve() {

}

int main() {
    fastIO;

//    freopen("input.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

}

// sparse table for maximum in an array
struct SparseTable {
    vector<vector<int>> sparse;
    int n, K;
    SparseTable(int n, vector<int> &a) {
        this->n = n;
        this->K = log2(n) + 1;

        sparse = vector<vector<int>>(n, vector<int>(K + 1));

        for (int i = 0; i < n; i++) {
            sparse[i][0] = a[i];
        }

        for (int j = 1; j <= K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int lg = (int) log2(r - l + 1);
        return max(sparse[l][lg], sparse[r - (1 << lg) + 1][lg]);
    }
};

struct Fraction {
    /*
     If denom is 0, num will always be = 1
     If num is 0, denom will always be = 1
     */
    ll num, denom;

    void check() {
        if (num == 0) denom = 1;
        if (denom == 0) num = 1;
        else {
            if (num < 0 && denom < 0) {
                num *= -1;
                denom *= -1;
            }
            ll tmp_gcd = __gcd(num, denom);
            num /= tmp_gcd;
            denom /= tmp_gcd;
        }
    }

    Fraction(pll p) {
        num = p.first, denom = p.second;
        check();
    }

    Fraction(ll n) {
        num = n;
        denom = 1;
    }

    ll __gcd(ll a, ll b) {
        if (a == 0) return b;
        if (b == 0) return a;
        return __gcd(b, a % b);
    }

    void operator=(const Fraction& other) {
        this->num = other.num;
        this->denom = other.denom;
    }

    void operator=(const pll &other) {
        this->num = other.first;
        this->denom = other.second;
        check();
    }

    Fraction operator+(const Fraction& other) {
        ll new_num = this->num * other.denom + this->denom * other.num;
        ll new_denom = this->denom * other.denom;

        ll tmp_gcd = __gcd(new_num, new_denom);
        new_num /= tmp_gcd;
        new_denom /= tmp_gcd;

        if (new_num == 0) new_denom = 1;
        Fraction curr_frac(make_pair(new_num, new_denom));
        return curr_frac;
    }

    void operator+=(const Fraction& other) {
        ll new_num = this->num * other.denom + this->denom * other.num;
        ll new_denom = this->denom * other.denom;

        ll tmp_gcd = __gcd(new_num, new_denom);
        new_num /= tmp_gcd;
        new_denom /= tmp_gcd;

        if (new_num == 0) new_denom = 1;
        this->num = new_num;
        this->denom = new_denom;
        check();
    }

    Fraction operator*(const Fraction& other) {
        ll new_num = this->num * other.num;
        ll new_denom = this->denom * other.denom;

        ll tmp_gcd = __gcd(new_num, new_denom);
        new_num /= tmp_gcd;
        new_denom /= tmp_gcd;

        if (new_num == 0) new_denom = 1;
        Fraction curr_frac(make_pair(new_num, new_denom));
        return curr_frac;
    }

    void operator*=(const Fraction& other) {
        ll new_num = this->num * other.num;
        ll new_denom = this->denom * other.denom;

        ll tmp_gcd = __gcd(new_num, new_denom);
        new_num /= tmp_gcd;
        new_denom /= tmp_gcd;

        if (new_num == 0) new_denom = 1;
        this->num = new_num;
        this->denom = new_denom;
        check();
    }

    bool operator==(const Fraction &other) {
        return this->num == other.num && this->denom == other.denom;
    }

    bool operator>(const Fraction &other) {
        return this->num * other.denom > other.num * this->denom;
    }

//    bool operator<(const Fraction &other) {
//        return this->num * other.denom < other.num * this->denom;
//    }

};

const int maxn = 1e2 + 14, lg = 15;

/*
  ######################################################################
  #######################   THE   BIG   INT   ##########################
*/
const int base = 1000000000;
const int base_digits = 9;
struct bigint {
    vector<int> a;
    int sign;
    /*<arpa>*/
    int size(){
        if(a.empty())return 0;
        int ans=(a.size()-1)*base_digits;
        int ca=a.back();
        while(ca)
            ans++,ca/=10;
        return ans;
    }
    bigint operator ^(const bigint &v){
        bigint ans=1,a=*this,b=v;
        while(!b.isZero()){
            if(b%2)
                ans*=a;
            a*=a,b/=2;
        }
        return ans;
    }
    string to_string(){
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }
    int sumof(){
        string s = to_string();
        int ans = 0;
        for(auto c : s)  ans += c - '0';
        return ans;
    }
    /*</arpa>*/
    bigint() :
            sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        a.clear();
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    void operator*=(long long v) {
        if (v < 0)
            sign = -sign, v = -v;
        if(v > base){
            *this = *this * (v / base) * base + *this * (v % base);
            return ;
        }
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(long long v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};
/*
  #######################   THE   BIG   INT   ##########################
  ######################################################################
*/

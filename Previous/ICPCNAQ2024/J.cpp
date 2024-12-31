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
                res.push_back((int)(cur % p[new_digits]));
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

struct Fraction {
    /*
     If denom is 0, num wibigint always be = 1
     If num is 0, denom wibigint always be = 1
     */
    bigint num, denom;

    void check() {
        if (num == 0) denom = 1;
        if (denom == 0) num = 1;
        else {
            if (num < 0 && denom < 0) {
                num *= -1;
                denom *= -1;
            }
            bigint tmp_gcd = __gcd(num, denom);
            num /= tmp_gcd;
            denom /= tmp_gcd;
        }
    }

    Fraction(ll a, ll b) {
        num = a, denom = b;
        check();
    }

    Fraction(pair<bigint, bigint> p) {
        num = p.first, denom = p.second;
        check();
    }

    Fraction(int n) {
        num = n;
        denom = 1;
    }

    bigint __gcd(bigint a, bigint b) {
        if (a == 0) return b;
        if (b == 0) return a;
        return __gcd(b, a % b);
    }

    void operator=(const Fraction &other) {
        this->num = other.num;
        this->denom = other.denom;
    }

    void operator=(const pair<bigint, bigint> &other) {
        this->num = other.first;
        this->denom = other.second;
        check();
    }

    Fraction operator+(const Fraction &other) {
        bigint new_num = this->num * other.denom + this->denom * other.num;
        bigint new_denom = this->denom * other.denom;

        bigint tmp_gcd = __gcd(new_num, new_denom);
        new_num /= tmp_gcd;
        new_denom /= tmp_gcd;

        if (new_num == 0) new_denom = 1;
        Fraction curr_frac(make_pair(new_num, new_denom));
        return curr_frac;
    }

    void operator+=(const Fraction &other) {
        bigint new_num = this->num * other.denom + this->denom * other.num;
        bigint new_denom = this->denom * other.denom;

        bigint tmp_gcd = __gcd(new_num, new_denom);
        new_num /= tmp_gcd;
        new_denom /= tmp_gcd;

        if (new_num == 0) new_denom = 1;
        this->num = new_num;
        this->denom = new_denom;
        check();
    }

    Fraction operator-(const Fraction &other) {
        bigint new_num = this->num * other.denom - this->denom * other.num;
        bigint new_denom = this->denom * other.denom;

        bigint tmp_gcd = __gcd(new_num, new_denom);
        new_num /= tmp_gcd;
        new_denom /= tmp_gcd;

        if (new_num == 0) new_denom = 1;
        Fraction curr_frac(make_pair(new_num, new_denom));
        return curr_frac;
    }

    Fraction operator*(const Fraction &other) {
        bigint new_num = this->num * other.num;
        bigint new_denom = this->denom * other.denom;

        bigint tmp_gcd = __gcd(new_num, new_denom);
        new_num /= tmp_gcd;
        new_denom /= tmp_gcd;

        if (new_num == 0) new_denom = 1;
        Fraction curr_frac(make_pair(new_num, new_denom));
        return curr_frac;
    }

    void operator*=(const Fraction &other) {
        bigint new_num = this->num * other.num;
        bigint new_denom = this->denom * other.denom;

        bigint tmp_gcd = __gcd(new_num, new_denom);
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

    bool operator<(const Fraction &other) {
        return this->num * other.denom < other.num * this->denom;
    }

    bool operator<=(const Fraction &other) {
        return this->num * other.denom <= other.num * this->denom;
    }
};

bool check_in(Fraction x, Fraction y, Fraction z, Fraction x0, Fraction y0, Fraction z0, Fraction x1, Fraction y1, Fraction z1) {
    return x0 <= x && x <= x1 && y0 <= y && y <= y1 && z0 <= z && z <= z1;
}

vector<vector<Fraction>> generate_cubes(Fraction x0, Fraction y0, Fraction z0, Fraction x1, Fraction y1, Fraction z1) {
    Fraction l = (x1 - x0) * Fraction(1, 3);

    vector<Fraction> x(4, 0), y(4, 0), z(4, 0);
    for (int i = 0; i < 4; i++) {
        x[i] = x0 + Fraction(i) * l;
        y[i] = y0 + Fraction(i) * l;
        z[i] = z0 + Fraction(i) * l;
    }

    vector<vector<Fraction>> cubes;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == 1 && j == 1) continue;
                if (j == 1 && k == 1) continue;
                if (i == 1 && k == 1) continue;
                cubes.push_back({x[i], y[j], z[k], x[i + 1], y[j + 1], z[k + 1]});
            }
        }
    }
    return cubes;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l;
    cin >> l;
    int xnum, xdenom, ynum, ydenom, znum, zdenom;
    cin >> xnum >> xdenom >> ynum >> ydenom >> znum >> zdenom;

    Fraction x(xnum, xdenom), y(ynum, ydenom), z(znum, zdenom);
//    Fraction x = xnum / xdenom;
//    Fraction y = ynum / ydenom;
//    Fraction z = znum / zdenom;

    Fraction x0(0), y0(0), z0(0), x1(1), y1(1), z1(1);
    bool in_cube = true;
    for (int i = 0; i < min(l, 200LL); i++) {
        vector<vector<Fraction>> cubes = generate_cubes(x0, y0, z0, x1, y1, z1);

        for (vector<Fraction> &cube : cubes) {
            if (check_in(x, y, z, cube[0], cube[1], cube[2], cube[3], cube[4], cube[5])) {
                x0 = cube[0], y0 = cube[1], z0 = cube[2], x1 = cube[3], y1 = cube[4], z1 = cube[5];
                goto done;
            }
        }

        in_cube = false;
        break;
        done:;
    }

    if (in_cube) cout << "1\n";
    else cout << "0\n";

}

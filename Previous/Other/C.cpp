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

    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int a = sqrt(s1 * s2 / s3);
    int b = sqrt(s3 * s1 / s2);
    int c = sqrt(s3 * s2 / s1);

    int sum = a + b + c;

    cout << 4 * sum;
}

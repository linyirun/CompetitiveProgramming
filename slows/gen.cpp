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

// Returns a random number in [a, b]
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int32_t main(int32_t argc, char* argv[]) {
    srand(stoi(argv[1]));

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = rand(1, 4);
    int m = rand(1, 3);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    shuffle(a.begin(), a.end(), random_device());
    cout << n << ' ' << m << '\n';
    for (int i : a) cout << i << ' ';
    cout << '\n';
    for (int i = 0; i < m; i++) {
        int a = rand(1, n), b = rand(1, n);
        cout << a << ' ' << b << '\n';
    }

}

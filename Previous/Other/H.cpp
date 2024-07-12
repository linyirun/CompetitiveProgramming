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


const int MAT_SZ = 101;
vector<vector<int>> identity(MAT_SZ, vector<int>(MAT_SZ));

vector<vector<int>> matmul(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<vector<int>> c(MAT_SZ, vector<int>(MAT_SZ));
    for (int i = 0; i < MAT_SZ; i++) {
        for (int j = 0; j < MAT_SZ; j++) {
            for (int k = 0; k < MAT_SZ; k++) {
                c[i][j] += A[i][k] * B[k][j] % MOD;
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

vector<vector<int>> binexp(vector<vector<int>> &A, int n) {
    if (n == 0) return identity;
    vector<vector<int>> res = binexp(A, n / 2);
    res = matmul(res, res);
    if (n % 2 == 1) res = matmul(res, A);
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < MAT_SZ; i++) {
        identity[i][i] = 1;
    }

    vector<vector<int>> mat(MAT_SZ, vector<int>(MAT_SZ));

    int n, x;
    cin >> n >> x;

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        mat[0][d[i] - 1]++;
    }

    // Set identity
    for (int i = 1; i < MAT_SZ; i++) {
        mat[i][i - 1] = 1;
    }

    mat = binexp(mat, x);

//    for (int i = 0; i < MAT_SZ; i++) {
//        for (int j = 0; j < MAT_SZ; j++) {
//            cout << mat[i][j] << ' ';
//        }
//        cout << '\n';
//    }

//    const int MX = 101;
    vector<int> vec(101);
    vec[0] = 1;


    for (int i = 1; i < 100; i++) {
        vec[i] = 1;
        for (int j = 0; j < n; j++) {
            if (i - d[j] >= 0) {
                vec[i] = (vec[i] + vec[i - d[j]]) % MOD;
            }
        }
    }

    vector<int> rev(101);
//    rev[100] = 1;
    for (int i = 0; i < 100; i++) {
        rev[99 - i] = vec[i];
    }


    // Calculate the first 100 values via dp and then multiply the matrix by it
    // Result is vec[99]

    // Multiply vec by mat
    vector<int> res(101);

    for (int row = 0; row < 101; row++) {
        for (int col = 0; col < 101; col++) {
            res[row] += mat[row][col] * rev[col] % MOD;
            res[row] %= MOD;
        }
    }

    cout << res[99] << '\n';
//    cout << vec[x] << '\n';


}

#include <iostream>
using namespace std;

const int N = 1000 + 100;
long long x[N];
long long y[N];
long long mat[N][N];
int n, m;

long long mygcd(long long x, long long y) {
    if (y == 0) return x;
    return mygcd(y, x % y);
}

bool solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = x[i];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            long long d = mygcd(y[j], mat[i][j]);
            mat[i][j] *= y[j] / d;
        }
    }

    for (int i = 0; i < n; i++) {
        long long d = 0;
        for (int j = 0; j < m; j++) {
            d = mygcd(d, mat[i][j]);
        }
        if (d != x[i]) return false;
    }
    for (int j = 0; j < m; j++) {
        long long d = 0;
        for (int i = 0; i < n; i++) {
            d = mygcd(d, mat[i][j]);
        }
        if (d != y[j]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) { cin >> x[i]; }
        for (int i = 0; i < m; i++) { cin >> y[i]; }
        bool ok = solve();
        if (!ok) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << mat[i][j];
                    if (j + 1 == m) cout << endl;
                    else cout << " ";
                }
            }
        }
    }
    return 0;
}

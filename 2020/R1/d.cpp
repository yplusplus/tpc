#include <iostream>
#include <string>
using namespace std;

const int MOD = 1000000007;
const int N = 5000 + 50;

int dp[2][N][8];
int n, m;
string s;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void solve() {
    cin >> n >> m;
    cin >> s;
    for (int j = 0; j <= m; j++) {
        for (int k = 0; k < 8; k++) {
            dp[0][j][k] = 0;
        }
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 8; k++) {
                dp[(i+1)%2][j][k] = 0;
            }
        }

        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 8; k++) {
                //cout << i << " " << j << " " << k << endl;
                if (dp[i%2][j][k] == 0) continue;
                if (s[i] == '?') {
                    for (int l = 0; l < 3; l++) {
                        int nj = j;
                        int nk = k | (1 << l);
                        if (nk == 7) nk = 0, nj++;
                        add(dp[(i+1)%2][min(nj, m)][nk], dp[i%2][j][k]);
                    }
                } else {
                    int l = s[i] - '0';
                    int nj = j;
                    int nk = k | (1 << l);
                    if (nk == 7) nk = 0, nj++;
                    add(dp[(i+1)%2][min(nj, m)][nk], dp[i%2][j][k]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) add(ans, dp[n%2][m][i]);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

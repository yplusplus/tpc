#include <iostream>
using namespace std;

const int N = 1000 + 100;
long long a[N][N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                sum += a[i][j];
            }
        }
        long long primary = 0;
        long long secondery = 0;
        long long x = 0;
        long long y = 0;
        for (int i = 0; i < n; i++) {
            primary += a[i][i];
            secondery += a[i][n - i - 1];
            y = max(y, a[i][i]);
            y = max(y, a[i][n - i - 1]);
            for (int j = 0; j < n; j++) {
                if (i == j || n - i - 1 == j) continue;
                x = max(x, a[i][j]);
            }
        }
        //cout << primary << " " << secondery << endl;
        //cout << x << endl;
        long long ans = primary + secondery;
        for (int i = 0; i < n; i++) {
            if (i == n - i - 1) {
                ans = max(ans, primary + secondery - a[i][i] * 2 + x * 2);
            } else {
                ans = max(ans, primary + secondery - a[i][i] + x);
                ans = max(ans, primary + secondery - a[i][n - i - 1] + x);
            }
        }
        if (n % 2 == 1 && y != a[n / 2][n / 2]) {
            ans = max(ans, primary + secondery + y - a[n / 2][n / 2]);
        }
        ans += sum * 2;
        cout << ans << endl;
    }
    return 0;
}

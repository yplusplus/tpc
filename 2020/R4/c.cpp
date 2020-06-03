#include <iostream>
using namespace std;

const int N = 200000 + 200;
int a[N];
long long sum[N];
int idx[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            idx[i] = -1;
            sum[i] = a[i] + sum[i - 1];
        }
        long long x = sum[n] / 2;
        int L = 0, R = 0;
        idx[0] = 0;
        for (int i = 1; i <= n; i++) {
            int y = sum[i] % x;
            //cout << i << " " << y << " " << idx[y] << endl;
            if (idx[y] == -1) {
                idx[y] = i;
            } else {
                L = idx[y] + 1;
                R = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i >= L && i <= R) {
                cout << 'a';
            } else {
                cout << 'b';
            }
        }
        cout << endl;
    }
    return 0;
}

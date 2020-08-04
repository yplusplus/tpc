#include <iostream>
using namespace std;

const int N = 100000 + 100;
int a[N];
int n;
long long m;

bool check() {
    for (int i = 2; i < n; i++) {
        int cc = 0;
        long long sum = 0;
        for (int j = 0; j < 3; j++) {
            if (a[i - j] == -1) cc++;
            else sum += a[i - j];
        }
        if (sum < m && cc == 0) return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (!check()) {
        cout << "Impossible" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != -1) continue;
        long long v = 0;
        if (i - 2 >= 0) {
            v = max(v, m - a[i - 1] - a[i - 2]);
        }
        if (i - 1 >= 0 && i + 1 < n && a[i + 1] != -1) {
            v = max(v, m - a[i + 1] - a[i - 1]);
        }
        if (i + 2 < n && a[i + 1] != -1 && a[i + 2] != -1) {
            v = max(v, m - a[i + 1] - a[i + 2]);
        }
        a[i] = v;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

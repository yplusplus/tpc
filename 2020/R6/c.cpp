#include <iostream>
#include <vector>
using namespace std;

const int N = 100000 + 100;
int a[N];

bool check(const int l, const int r) {
    if (l == r) { return true; }
    int mid = (l + r) >> 1;
    if (!check(l, mid) || !check(mid + 1, r)) return false;
    vector<int> left = {a[mid]};
    vector<int> right = {a[mid+1]};
    for (int i = mid; i >= l; i--) {
        if (a[i] < left.back()) left.push_back(a[i]);
    }
    for (int i = mid + 1; i <= r; i++) {
        if (a[i] < right.back()) right.push_back(a[i]);
    }
    for (int x: left) {
        for (int y: right) {
            if (x % y == 0 || y % x == 0) continue;
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        bool ok = check(0, n - 1);
        if (!ok) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}

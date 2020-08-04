#include <iostream>
#include <set>

using namespace std;

const int N = 100000 + 100;
int a[N];
int b[N];
int n;
int p[N];

int find(int now) {
    set<int> s;
    for (int i = now; i < n; i++) {
        s.insert(a[i]);
        s.insert(b[i]);
        if (s.size() == i - now + 1) {
            break;
        }
    }
    return s.size();
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }
    if (a[0] != b[0]) {
        cout << "No" << endl;
        return;
    }

    p[a[0]] = -1;
    int now = 1;
    int ans = 0;
    int pre = a[0];
    while (now < n) {
        int len = find(now);
        //cout << now << " " << len << endl;
        for (int i = 0; i < len; i++) {
            p[a[now + i]] = pre;
        }
        pre = a[now];
        now += len;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1;
        if (i + 1 == n) cout << endl;
        else cout << " ";
    }
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

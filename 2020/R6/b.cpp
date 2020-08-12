#include <iostream>
#include <vector>
using namespace std;

const int N = 15;
struct Applicant {
    int c, v, x, y;
    void read() {
        cin >> v >> c >> y >> x;
        //cin >> c >> v >> x >> y;
    }
} app[N];

pair<int, int> table[1 << N];
int cnt[1 << N];
int m, n;

pair<int, int> calc(int mask) {
    pair<int, int> res{0, 0};
    for (int i = 0; i < n; i++) {
        if (mask >> i & 1) {
            pair<int, int> t = table[mask];
            t.first += app[i].x;
            t.second -= app[i].y;
            res = max(res, t);
        }
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        app[i].read();
    }

    table[0] = {0, 0};
    cnt[0] = 0;
    pair<int, int> ans{0, 0};
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                table[i] = table[i ^ (1 << j)];
                table[i].first += app[j].c;
                table[i].second -= app[j].v;
                cnt[i] = cnt[i ^ (1 << j)] + 1;
            }
        }
        if (cnt[i] == m) {
            ans = max(ans, calc(i));
        }
    }

    cout << ans.first << " " << -ans.second << endl;
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

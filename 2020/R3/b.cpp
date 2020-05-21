#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

void solve() {
    string str;
    cin >> str;
    int cnt[10] = {0};
    for (char ch: str) {
        cnt[ch - '0']++;
    }
    if (cnt[1] == 0) {
        cout << "Impossible" << endl;
        return;
    }
    if (cnt[0] > 2 * (cnt[1] + 1)) {
        cout << "Impossible" << endl;
        return;
    }
    if (cnt[0] <= 2) {
        cout << string(cnt[1], '1') + string(cnt[0], '0') << endl;
        return;
    }
    string ans;
    if (cnt[0] % 2 == 1) {
        ans = "0";
        cnt[0]--;
    } else {
        ans = "00";
        cnt[0] -= 2;
    }
    assert(cnt[0] % 2 == 0);
    while (cnt[0] > 0) {
        ans += '1';
        cnt[1]--;
        ans += "00";
        cnt[0] -= 2;
    }
    ans += string(cnt[1], '1');
    reverse(ans.begin(), ans.end());
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

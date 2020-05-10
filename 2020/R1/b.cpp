#include <iostream>
#include <string>
using namespace std;

const int N = 100000 + 100;
string s, t;
int n;

int solve() {
    cin >> n >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) continue;
        if (i > 0 && s[i] == s[i - 1]) return -1;
        for (int j = i + 1; j < n; j++) {
            if (s[j] == s[i]) s[j] ^= 1;
            else break;
        }
        s[i] ^= 1;
        ans++;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}

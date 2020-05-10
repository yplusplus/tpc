#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = n / 2;
        if (ans == 0) ans = 1;
        cout << ans << endl;
    }
    return 0;
}

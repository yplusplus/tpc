#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int calc(int h, int div) {
    //cout << h << " " << div << endl;
    for (int i = 0; i < 5; i++) {
        if ((h + i) % div == 0) {
            return i;
        }
    }
    assert(false);
}

bool is_prime(int x) {
    if (x == 1) return false;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int calc_prime(int h) {
    for (int i = 0; i < 5; i++) {
        if (is_prime(h + i)) return i;
    }
    assert(false);
}

void solve() {
    int h;
    string cmd;
    cin >> h >> cmd;
    if (cmd == "divide_by_three") {
        cout << calc(h, 3) << endl;
    } else if (cmd == "divide_by_four") {
        cout << calc(h, 4) << endl;
    } else if (cmd == "divide_by_five" ){
        cout << calc(h, 5) << endl;
    } else {
        cout << calc_prime(h) << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

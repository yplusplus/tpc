#include <iostream>
#include <vector>
using namespace std;

vector<int> boards;
const int SZ = 16;
const int N = 4;
const int K = 9;

int count_ones(int x) {
    int cnt = 0;
    for (int j = 0; j < SZ; j++) {
        if (x >> j & 1) {
            cnt++;
        }
    }
    return cnt;
}

bool check(int mask) {
    int lines = 0;
    for (int i = 0; i < N; i++) {
        bool empty = false;
        for (int j = 0; j < N; j++) {
            if (~mask >> (i * N + j) & 1) {
                empty = true;
            }
        }
        if (!empty) lines++;
    }
    for (int j = 0; j < N; j++) {
        bool empty = false;
        for (int i = 0; i < N; i++) {
            if (~mask >> (i * N + j) & 1) {
                empty = true;
            }
        }
        if (!empty) lines++;
    }
    bool diag_empty = false;
    for (int i = 0; i < N; i++) {
        if (~mask >> (i * N + i) & 1) {
            diag_empty = true;
        }
    }
    if (!diag_empty) lines++;
    bool rdiag_empty = false;
    for (int i = 0; i < N; i++) {
        if (~mask >> ((i+1) * N - i - 1) & 1) {
            rdiag_empty = true;
        }
    }
    if (!rdiag_empty) lines++;
    return lines >= 3;
}

void init() {
    for (int i = 0; i < (1 << SZ); i++) {
        int ones = count_ones(i);
        if (ones == 9 && check(i)) {
            boards.push_back(i);
        }
    }
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        string line;
        int mask = 0;
        for (int i = 0; i < N; i++) {
            cin >> line;
            for (int j = 0; j < N; j++) {
                if (line[j] == '#') {
                    mask |= (1 << (i * N + j));
                }
            }
        }
        int ans = SZ;
        for (const int x: boards) {
            ans = min(ans, count_ones(x ^ mask) / 2);
        } 
        cout << ans << endl;
    }
    return 0;
}

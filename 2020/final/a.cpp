#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000 + 100;
long long a[N];
int n;
char ans[N];

struct Shard {
    int x, id;
    bool flag;
    void read(int id_) {
        flag = 0;
        id = id_;
        cin >> x;
    }
    bool operator<(const Shard &o) const {
        return x > o.x;
    }
} s[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long total = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            s[i].read(i);
            total += s[i].x;
        }
        sort(s, s + n);
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            long long left = total / 2;
            //cout << left << endl;
            for (int i = 0; i < n; i++) {
                if (s[i].flag > 0) continue;
                if (left >= s[i].x) {
                    left -= s[i].x;
                    ans[s[i].id] = '1' + j;
                    //cout << i << " " << s[i].id << endl;
                    s[i].flag = 1;
                    cnt++;
                }
            } 
        }
        if (cnt == n) {
            ans[n] = 0;
            cout << ans << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}

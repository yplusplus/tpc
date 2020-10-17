#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000000 + 100;
vector<int> vec;

struct BIT {
    void clear(int n) {
        for (int i = 0; i < n; i++) {
            c[i] = 0;
        }
    }
    int lowbit(int x) { return x & (-x); }
    void upd(int x, int y) {
        x++;
        for (int i = x; i < N; i += lowbit(i)) {
            c[i] = max(c[i], y);
        }
    }
    int qmax(int x) {
        x++;
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            res = max(res, c[i]);
        }
        return res;
    }
    int c[N];
} bit;

struct Point {
    int x, y, id;
    void read(int _id) {
        cin >> x >> y;
        id = _id;
    }
    bool operator<(const Point &p) const {
        if (x != p.x) return x < p.x;
        if (y != p.y) return y > p.y;
        return id > p.id;
    }
} point[N];
int ans[N];

int get_y(int y) {
    int res = std::lower_bound(vec.begin(), vec.end(), y) - vec.begin();
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y;
            point[i].read(-1);
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            point[i + n].read(i);
        }

        //cout << n << " " << q << endl;
        int m = n + q;
        sort(point, point + m);

        vec.clear();
        for (int i = 0; i < m; i++) {
            vec.push_back(point[i].y);
            vec.push_back(point[i].y - 1);
        }
        sort(vec.begin(), vec.end());
        vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
        //cout << vec.size() << endl;
        bit.clear(vec.size());
           
        for (int i = 0; i < m; i++) {
            const Point &p = point[i];
            //cout << p.x << " " << p.y << " " << p.id << endl;
            if (p.id == -1) {
                // road
                int y = get_y(p.y - 1);
                int res = bit.qmax(y);
                //cout << "res = " << res << endl;
                bit.upd(y + 1, res + 1);
            } else {
                // query
                int y = get_y(p.y - 1);
                int res = bit.qmax(y);
                //cout << "res = " << res << endl;
                ans[p.id] = p.x + p.y - res;
            }
        }

        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}

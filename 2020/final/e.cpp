#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100000 + 100;
int n, m, L, R;

struct Edge {
    int u, v;
    long long a, b;
    void read() { cin >> u >> v >> a >> b; }
    long long get_value(long long x) const { return a + b * x; }
};
vector<Edge> edges;

struct UFS {
    int fa[N];
    void init() {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    bool Union(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return false;
        fa[rx] = ry;
        return true;
    }
} ufs;

long long calc(int x) {
    ufs.init();
    sort(edges.begin(), edges.end(), [x](const Edge &p, const Edge &q) {
            return p.get_value(x) < q.get_value(x);
    });
    long long res = 0;
    for (const auto &e: edges) {
        if (ufs.Union(e.u, e.v)) {
            res += e.get_value(x);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> L >> R;
        edges.resize(m);
        for (int i = 0; i < m; i++) { edges[i].read(); }
        cout << min(calc(L), calc(R)) << endl;
    }
    return 0;
}

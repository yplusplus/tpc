#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 500000 + 500;

set<int> vec[N];
vector<int> g[N];
bool visit[N];
int n, m;
vector<int> ans;

void dfs(int u) {
    visit[u] = true;
    for (auto it = vec[u].rbegin(); it != vec[u].rend(); it++) {
        int v = *it;
        if (visit[v]) continue;
        //cout << u << " -> " << v << endl;
        g[u].push_back(v);
        dfs(v);
    }
}

void bfs() {
    for (int i = 0; i <= n; i++) {
        visit[i] = false;
    }
    set<int> s;
    s.insert(1);
    vector<int> ans;
    while (!s.empty()) {
        int u = *s.begin();
        s.erase(u);
        ans.push_back(u);
        s.insert(g[u].begin(), g[u].end());
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            vec[i].clear();
            visit[i] = false;
            g[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            vec[a].insert(b);
            vec[b].insert(a);
        }
        dfs(1);
        bfs();
    }
    return 0;
}

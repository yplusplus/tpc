#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int n = 3;

const vector<int> row_trans[3] = {
    {2, 0, 1, 3, 4, 5, 6, 7, 8},
    {0, 1, 2, 5, 3, 4, 6, 7, 8},
    {0, 1, 2, 3, 4, 5, 8, 6, 7},
};

string rotate_row(int i, const string &s) {
    string t = s;
    for (int j = 0; j < 9; j++) {
        t[j] = s[row_trans[i][j]];
    }
    return t;
}

const vector<int> col_trans[3] = {
    {6, 1, 2, 0, 4, 5, 3, 7, 8},
    {0, 7, 2, 3, 1, 5, 6, 4, 8},
    {0, 1, 8, 3, 4, 2, 6, 7, 5},
};

string rotate_col(int i, const string &s) {
    string t = s;
    for (int j = 0; j < 9; j++) {
        t[j] = s[col_trans[i][j]];
    }
    return t;
}

map<string, int> dist;

void init() {
    queue<string> que;
    string s = "123456789";
    dist[s] = 0;
    que.push(s);
    while (!que.empty()) {
        s = que.front();
        que.pop();
        int dis = dist[s];

        // row
        for (int i = 0; i < n; i++) {
            string t = rotate_row(i, s);
            if (dist.count(t) > 0) continue;
            dist[t] = dis + 1;
            que.push(t);
        }

        // column
        for (int i = 0; i < n; i++) {
            string t = rotate_col(i, s);
            if (dist.count(t) > 0) continue;
            dist[t] = dis + 1;
            que.push(t);
        }
    }
}

char trans[256];
char str[100];
void solve() {
    string s, t;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        s += str;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        t += str;
    }
    for (int i = 0; i < 9; i++) {
        trans[s[i]] = i + 1 + '0';
    }
    for (int i = 0; i < 9; i++) {
        t[i] = trans[t[i]];
    }
    if (dist.count(t) == 0) {
        puts("impossible");
        return;
    }
    printf("%d\n", dist[t]);
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

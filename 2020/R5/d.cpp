#include <iostream>
#include <cassert>
using namespace std;

const int N = 100000 + 100;
const int M = 7;
char color[N];
//               0123456
char mapper[] = "rybopgx";

int char2int(char ch) {
    for (int i = 0; i < M; i++) {
        if (ch == mapper[i]) 
            return i;
    }
    assert(false);
    return -1;
}

inline char int2char(int x) { return mapper[x]; }

int calc(int a, int b) {
    assert(a >= 0 && a < 7);
    assert(b >= 0 && b < 7);
    int srcb = b;
    if (a > b) swap(a, b);
    if (a == 0 && b == 1) return 3;
    if (a == 0 && b == 2) return 4;
    if (a == 1 && b == 2) return 5;
    if (a == 2 && b == 3) return 6;
    if (a == 1 && b == 4) return 6;
    if (a == 0 && b == 5) return 6;
    return srcb;
}

int calc(int a, int b, int n) {
    for (int i = 0; i < n && a != b; i++) {
        a = calc(a, b);
    }
    return a;
}

struct Node {
    int trans[M];
    int col;
    int lazy;
} node[N << 2];

void push_up(int p, int l, int r) {
    for (int i = 0; i < M; i++) {
        node[p].trans[i] = node[p << 1 | 1].trans[node[p << 1].trans[i]];
    }
}

void push_down(int p, int l, int r) {
    if (node[p].lazy == -1) return;
    int mid = (l + r) >> 1;
    for (int i = 0; i < M; i++) {
        node[p << 1].trans[i] = calc(i, node[p].lazy, mid - l + 1);
        node[p << 1 | 1].trans[i] = calc(i, node[p].lazy, r - mid);
    }
    node[p << 1].col = node[p << 1 | 1].col = node[p].lazy;
    node[p << 1].lazy = node[p << 1 | 1].lazy = node[p].lazy;
    node[p].lazy = -1;
}

void build(int p, int l, int r, char *color) {
    node[p].lazy = -1;
    if (l == r) {
        node[p].col = char2int(color[l]);
        for (int i = 0; i < M; i++) {
            node[p].trans[i] = calc(i, node[p].col, r - l + 1);
        }
        return;
    }

    int mid = (l + r) >> 1;
    build(p << 1, l, mid, color);
    build(p << 1 | 1, mid + 1, r, color);
    push_up(p, l, r);
}

void query(int p, int l, int r, int L, int R, int &ans) {
    if (L <= l && r <= R) {
        ans = node[p].trans[ans];
        return;
    }

    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) query(p << 1, l, mid, L, R, ans);
    if (mid < R) query(p << 1 | 1, mid + 1, r, L, R, ans);
    push_up(p, l, r);
}

int query_col(int p, int l, int r, int x) {
    if (l == r) {
        return node[p].col;
    }

    push_down(p, l, r);
    int mid = (l + r) >> 1;
    int res = 0;
    if (x <= mid) res = query_col(p << 1, l, mid, x);
    else res = query_col(p << 1 | 1, mid + 1, r, x);
    push_up(p, l, r);
    return res;
}

void update(int p, int l, int r, int L, int R, int c) {
    if (L <= l && r <= R) {
        node[p].lazy = node[p].col = c;
        for (int i = 0; i < M; i++) {
            node[p].trans[i] = calc(i, c, r - l + 1);
        }
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(p << 1, l, mid, L, R, c);
    if (mid < R) update(p << 1 | 1, mid + 1, r, L, R, c);
    push_up(p, l, r);
}

void solve() {
    int n, m;
    cin >> n >> m;
    cin >> color;

    build(1, 0, n - 1, color);
    while (m--) {
        int cmd;
        int L, R;
        cin >> cmd >> L >> R;
        L--;
        R--;
        if (cmd == 1) {
            static char col[10];
            cin >> col;
            update(1, 0, n - 1, L, R, char2int(col[0]));
        } else {
            int col = query_col(1, 0, n - 1, L);
            //cout << col << endl;
            if (L < R) query(1, 0, n - 1, L + 1, R, col);
            //cout << col << endl;
            cout << int2char(col) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

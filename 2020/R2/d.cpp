#include <iostream>
#include <random>
using namespace std;

const int N = 300000 + 300;

using PII = pair<int, int>;

struct TreapNode {
    int key, size, l, r, add;
    void inc() {
        key++;
        add++;
    }
    void push_up();
    void push_down();
} node[N];

void TreapNode::push_up() {
    size = 1;
    if (l > 0) size += node[l].size;
    if (r > 0) size += node[r].size;
}

void TreapNode::push_down() {
    if (add == 0) return;
    if (l != 0) {
        node[l].key += add;
        node[l].add += add;
    }
    if (r != 0) {
        node[r].key += add;
        node[r].add += add;
    }
    add = 0;
}

int alloc;
int new_node(int key) {
    alloc++;
    node[alloc] = {key, 1, 0, 0, 0};
    return alloc;
}

int merge(int a, int b) {
    if (a == 0 || b == 0) return a | b;
    static mt19937 rnd(0);
    const bool less = (int)rnd() % (node[a].size + node[b].size) >= node[a].size;
    if (less) {
        node[a].push_down();
        node[a].r = merge(node[a].r, b);
        node[a].push_up();
        return a;
    } else {
        node[b].push_down();
        node[b].l = merge(a, node[b].l);
        node[b].push_up();
        return b;
    }
}

PII split_key(int p, int key) {
    if (p == 0) return PII{0, 0};
    node[p].push_down();
    if (node[p].key < key) {
        PII ret = split_key(node[p].r, key);
        node[p].r = ret.first;
        node[p].push_up();
        return {p, ret.second};
    } else {
        PII ret = split_key(node[p].l, key);
        node[p].l = ret.second;
        node[p].push_up();
        return {ret.first, p};
    }
}

PII split_cnt(int p, int c) {
    if (p == 0) return PII{0, 0};
    if (c == 0) return PII{0, p};
    node[p].push_down();
    if (node[node[p].l].size >= c) {
        PII ret = split_cnt(node[p].l, c);
        node[p].l = ret.second;
        node[p].push_up();
        return {ret.first, p};
    } else {
        PII ret = split_cnt(node[p].r, c - node[node[p].l].size - 1);
        node[p].r = ret.first;
        node[p].push_up();
        return {p, ret.second};
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, L, R;
        alloc = 0;
        int root = 0;
        scanf("%d", &n);
        int tot = 1;
        while (n--) {
            scanf("%d%d", &L, &R);
            PII r1 = split_key(root, L);
            PII r2 = split_key(r1.second, R);
            if (r2.first != 0) { node[r2.first].inc(); }
            root = merge(merge(r1.first, new_node(L)), merge(r2.first, split_cnt(r2.second, 1).second));
        }
        printf("%d\n", node[root].size);
    }
    return 0;
}

#include <stdio.h>

//typedef struct node_t Node;
typedef struct Node {
    int val;
    struct Node *right, *down;
} Node;
Node nodes[2510][2510];

#define MOD 998244353
int n, m, q;

void output(int a) {
    Node *p = &nodes[a][0];
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        p = p->right;
        ans += p->val;
    }
    printf("%lld\n", ans);
}

Node *get_node(int x, int y) {
    Node *p = &nodes[x][0];
    for (int i = 1; i <= y; i++)
        p = p->right;
    return p;
}

void swap(Node **a, Node **b) {
    Node *t = *a;
    *a = *b;
    *b = t;
}

void mod_down(Node *p, Node *q, int len) {
    for (int i = 1; i <= len; i++) {
        swap(&p->down, &q->down);
        p = p->right;
        q = q->right;
    }
}

void mod_right(Node *p, Node *q, int len) {
    for (int i = 1; i <= len; i++) {
        swap(&p->right, &q->right);
        p = p->down;
        q = q->down;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            nodes[i][j].down = &nodes[i + 1][j];
            nodes[i][j].right = &nodes[i][j + 1];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            nodes[i][j].val = i * m + j;
    scanf("%d", &q);
    int x1, y1, x2, y2, x3, y3, x4, y4, a;
    while (q--) {
        scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &a);
        Node *p[] = {get_node(x1, y2), get_node(x2, y1), get_node(x1, y1 - 1), get_node(x1 - 1, y1)};
        Node *q[] = {get_node(x3, y4), get_node(x4, y3), get_node(x3, y3 - 1), get_node(x3 - 1, y3)};
        mod_right(p[0], q[0], x2 - x1 + 1);
        mod_down(p[1], q[1], y2 - y1 + 1);
        mod_right(p[2], q[2], x2 - x1 + 1);
        mod_down(p[3], q[3], y2 - y1 + 1);
        output(a);
    }
    return 0;
}
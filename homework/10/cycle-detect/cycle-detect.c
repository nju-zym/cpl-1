//
// Created by 35861 on 24-12-20.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *s;
    int next;
}node;

int entrance;
node nodes[100002];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        nodes[i].s = calloc(21, sizeof(char));
        scanf("%s %d", nodes[i].s, &nodes[i].next);
    }
    node *t = &nodes[1], *h = &nodes[1];
    while (h->next > 0 && t->next > 0) {
        t = &nodes[t->next];
        h = &nodes[h->next];
        if (h->next > 0) {
            h = &nodes[h->next];
        }
        if (t == h) break;
    }
    if (h->next <= 0 || t->next <= 0) {
        printf("-1\n");
        return 0;
    }
    t = &nodes[1];
    while (t != h) {
        t = &nodes[t->next];
        h = &nodes[h->next];
    }
    printf("%s\n", t->s);
    return 0;
}

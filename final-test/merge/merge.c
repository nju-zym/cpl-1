#include <stdio.h>
#define maxn 200005
#define max(a, b) ((a) > (b) ? (a) : (b))
int main(void) {
    int n1, n2, m1 = 0, m2 = 0, a1[maxn], a2[maxn], i, j;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", a1 + i);
        if (a1[i] > a1[m1])
            m1 = i;
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", a2 + i);
        if (a2[i] > a2[m2])
            m2 = i;
    }
    for (i = 0, j = 0; i <= m1 && j <= m2;)
        if (a1[i] < a2[j]) {
            printf("%d ", a1[i]);
            i++;
        } else {
            printf("%d ", a2[j]);
            j++;
        }
    while (i <= m1)
        printf("%d ", a1[i++]);
    while (j <= m2)
        printf("%d ", a2[j++]);
    for (; i < n1 && j < n2;)
        if (a1[i] < a2[j]) {
            printf("%d ", a2[j]);
            j++;
        } else {
            printf("%d ", a1[i]);
            i++;
        }
    while (i < n1)
        printf("%d ", a1[i++]);
    while (j < n2)
        printf("%d ", a2[j++]);
    return 0;
}
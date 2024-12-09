//
// Created by 35861 on 24-12-8.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
    int offen;
}country_offen;
typedef struct {
    char name[21];
    int defen;
}country_defen;
typedef struct {
    char name[21];
    int tact;
}country_tact;
country_offen countries_offen[1000];
country_defen countries_defen[1000];
country_tact countries_tact[1000];
int cmp_offen(const void *a, const void *b) {
    country_offen *cna = (country_offen *) a;
    country_offen *cnb = (country_offen *) b;
    return cnb->offen - cna->offen;
}
int cmp_defen(const void *a, const void *b) {
    country_defen *cna = (country_defen *) a;
    country_defen *cnb = (country_defen *) b;
    return cnb->defen - cna->defen;
}
int cmp_tact(const void *a, const void *b) {
    country_tact *cna = (country_tact *) a;
    country_tact *cnb = (country_tact *) b;
    return cnb->tact - cna->tact;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", countries_offen[i].name);
        strcpy(countries_defen[i].name, countries_offen[i].name);
        strcpy(countries_tact[i].name, countries_offen[i].name);
        for (int j = 0; j < 11; j++) {
            char name[21];
            int temp_offen,temp_defen,temp_tact;
            scanf("%s", name);
            scanf("%d%d%d", &temp_offen, &temp_defen, &temp_tact);
            countries_offen[i].offen+=temp_offen;
            countries_defen[i].defen+=temp_defen;
            countries_tact[i].tact+=temp_tact;
        }
    }
    qsort(countries_offen, n, sizeof(country_offen), cmp_offen);
    qsort(countries_defen, n, sizeof(country_defen), cmp_defen);
    qsort(countries_tact, n, sizeof(country_tact), cmp_tact);
    for (int i = 0; i < n; i++) {
        printf("%s ", countries_offen[i].name);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", countries_defen[i].name);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", countries_tact[i].name);
    }
    return 0;
}
//
// Created by 35861 on 24-12-20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2000000

typedef struct hash_strs{
    char *str;
    struct hash_strs *next;
}hash_strs;

hash_strs *values[N];

char *strdup(char *str);

int hash(char *s){
    int len=strlen(s);
    int ret=0;
    for(int i=0;i<len;i++)ret=(ret+s[i]*(i+1))%N;
    return ret;
}

void insert(char *s) {
    int hash_value=hash(s);
    if (values[hash_value]==NULL) {
        values[hash_value]=malloc(sizeof(hash_strs));
        values[hash_value]->str = strdup(s);
        values[hash_value]->next=NULL;
    }
    else {
        hash_strs *temp=values[hash_value];
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=malloc(sizeof(hash_strs));
        temp->next->str=strdup(s);
        temp->next->next=NULL;
    }
}

void query(char *s) {
    int hash_value=hash(s);
    if (values[hash_value]==NULL) {
        printf("No\n");
    }
    else {
        hash_strs *temp=values[hash_value];
        while (temp!=NULL) {
            if (strcmp(temp->str, s)==0) {
                printf("Yes\n");
                return;
            }
            temp=temp->next;
        }
        printf("No\n");
    }
}

int main() {
    int m, q;
    scanf("%d %d", &m, &q);
    getchar();
    for (int i = 0; i < m; i++) {
        char *s = calloc(1002, sizeof(char));
        scanf("%s", s);
        insert(s);
        free(s);
    }
    for (int i = 0; i < q; i++) {
        char *s = calloc(1002, sizeof(char));
        scanf("%s", s);
        query(s);
        free(s);
    }
    return 0;
}
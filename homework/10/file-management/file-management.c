//
// Created by 35861 on 24-12-20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    enum { FNODE, DNODE } type; // 文件类型
    struct node **dirents; // if DTYPE 子文件（普通和目录）的地址
    void *content; // if FNODE 文件的地址
    int nrde; // 子节点的数量
    char *name; // 节点名称
    int size; // 节点大小 if FNODE 为文件的字节 if DNODE 为0
    struct node *parent; //父节点
} node;

node *root = NULL;

node *find(const char *pathname, node **parent, int *flag) {
    //flag == 0:合法目录地址 flag == 1:合法的文件地址flag ==2:最后的地址不存在 flag == 3:地址中包含不存在的文件/目录（不是最后）  flag == 4:地址中包含了文件（不是最后）
    if (pathname == NULL || *pathname != '/') {
        *parent = NULL;
        *flag = 3;
        return NULL;
    }
    *parent = NULL;
    node *cur = root;
    if (strcmp(pathname, "/") == 0) {
        *flag = 0;
        return root;
    }
    char *path_copy = strdup(pathname);
    size_t len = strlen(path_copy);
    path_copy = realloc(path_copy, len + 2);
    while (len > 1 && path_copy[len - 1] == '/') {
        path_copy[len - 1] = '\0';
        len--;
    }
    if (path_copy[len - 1] != '/') {
        path_copy[len] = '/';
        path_copy[len + 1] = '\0';
    }
    const char *token = strtok(path_copy, "/");
    const char *next_token = NULL;
    while (token != NULL) {
        next_token = strtok(NULL, "/");
        node *child = NULL;
        for (int i = 0; i < cur->nrde; i++) {
            if (cur->dirents[i] == NULL) continue;
            if (strcmp(cur->dirents[i]->name, token) == 0) {
                child = cur->dirents[i];
                if (child->type == FNODE && next_token != NULL) {
                    *flag = 4;
                    free(path_copy);
                    return NULL;
                }
                if (child->type == FNODE && next_token == NULL) {
                    *flag = 1;
                    free(path_copy);
                    *parent = cur;
                    return child;
                }
                break;
            }
        }
        *parent = cur;
        if (child == NULL && next_token == NULL) {
            *flag = 2;
            free(path_copy);
            return NULL;
        }
        if (child == NULL) {
            *flag = 3;
            free(path_copy);
            *parent = NULL;
            return NULL;
        }
        cur = child;
        token = next_token;
    }
    *flag = 0;
    free(path_copy);
    return cur;
}
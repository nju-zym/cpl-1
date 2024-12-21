//
// Created by 35861 on 24-12-20.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct ch_node {
    char ch;
    struct ch_node *prev;
    struct ch_node *next;
    struct ch_node *last_same;
} ch_node;

void print(int k);

void add_node(char ch);

void del_node(char ch);

int flag_up(char ch);

ch_node *head = NULL;
ch_node *tail = NULL;
ch_node *up_tail = NULL;
ch_node *low_tail = NULL;

int main() {
    int q;
    scanf("%d", &q);
    getchar();
    while (q--) {
        char ch;
        while ((ch = getchar()) != '\n') {
            if (ch == '?') {
                getchar();
                int k;
                scanf("%d", &k);
                print(k);
            } else if (ch == 'm' || ch == 'M') del_node(ch);
            else add_node(ch);
        }
    }
    return 0;
}

int flag_up(char ch) {
    if (ch >= 'a' && ch <= 'z') return 0;
    if (ch >= 'A' && ch <= 'Z') return 1;
    return -1;
}

void add_node(char ch) {
    if (head == NULL) {
        head = (ch_node *) malloc(sizeof(ch_node));
        tail = head;
        head->ch = ch;
        head->prev = NULL;
        head->next = NULL;
        head->last_same = NULL;
        if (flag_up(ch)) up_tail = head;
        else low_tail = head;
    } else {
        ch_node *new_node = (ch_node *) malloc(sizeof(ch_node));
        new_node->ch = ch;
        new_node->prev = tail;
        new_node->next = NULL;
        new_node->last_same = NULL;
        if (flag_up(ch)) {
            if (up_tail) new_node->last_same = up_tail;
            else new_node->last_same = NULL;
            up_tail = new_node;
        } else {
            if (low_tail) new_node->last_same = low_tail;
            else new_node->last_same = NULL;
            low_tail = new_node;
        }
        tail->next = new_node;
        tail = new_node;
    }
}

void print(int k) {
    int temp = k;
    ch_node *temp_node = tail;
    char *str = (char *) calloc(k + 2, sizeof(char));
    str[k] = '\n';
    str[k + 1] = '\0';
    while (temp--) {
        str[temp] = temp_node->ch;
        temp_node = temp_node->prev;
    }
    printf("%s", str);
    free(str);
}

void del_node(char ch) {
    if (flag_up(ch) && up_tail) {
        if (up_tail == head) {
            if (head->next != NULL) {
                head = head->next;
                head->prev = NULL;
            }
            else {
                head = NULL;
                tail = NULL;
            }
            free(up_tail);
            up_tail = NULL;
        }
        else if (up_tail == tail) {
            tail = tail->prev;
            tail->next = NULL;
            ch_node *temp_node = up_tail;
            if (up_tail->last_same != NULL) {
                up_tail = up_tail->last_same;
            }
            else up_tail = NULL;
            free(temp_node);
        }
        else {
            if (up_tail->prev) {
                if (up_tail->next) up_tail->prev->next = up_tail->next;
                else up_tail->prev->next = NULL;
            }
            if (up_tail->next) {
                if (up_tail->prev) up_tail->next->prev = up_tail->prev;
                else up_tail->next->prev = NULL;
            }
            ch_node *temp = up_tail;
            up_tail = up_tail->last_same ? up_tail->last_same : NULL;
            free(temp);
        }
    } else if (!flag_up(ch) && low_tail) {
        if (low_tail == head) {
            if (head->next != NULL) {
                head = head->next;
                head->prev = NULL;
            }
            else {
                head = NULL;
                tail = NULL;
            }
            free(low_tail);
            low_tail = NULL;
        }
        else if (low_tail == tail) {
            tail = tail->prev;
            tail->next = NULL;
            ch_node *temp_node = low_tail;
            if (low_tail->last_same != NULL) {
                low_tail = low_tail->last_same;
            }
            else low_tail = NULL;
            free(temp_node);
        }
        else {
            if (low_tail->prev) {
                if (low_tail->next) low_tail->prev->next = low_tail->next;
                else low_tail->prev->next = NULL;
            }
            if (low_tail->next) {
                if (low_tail->prev) low_tail->next->prev = low_tail->prev;
                else low_tail->next->prev = NULL;
            }
            ch_node *temp = low_tail;
            low_tail = low_tail->last_same ? low_tail->last_same : NULL;
            free(temp);
        }
    }
}


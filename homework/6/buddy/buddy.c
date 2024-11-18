//
// Created by 35861 on 24-11-17.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    int memory;
    struct node *next;
}node;
node *create_node(const int id, const int memory) {
    node*temp = (node *)malloc(sizeof(node));
    temp->id = id;
    temp->memory = memory;
    temp->next = NULL;
    return temp;
}
void divide(node *p) {
    int new_memory=p->memory-1;
    p->memory = new_memory;
    node *new_node = create_node(0, new_memory);
    new_node->next = p->next;
    p->next = new_node;
}

void free_node(node *head) {
    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}
int confirm(int x) {
    int i=0;
    int temp=1;
    while(temp<x) {
        temp*=2;
        i++;
    }
    return i;
}
void searchandpush(node *head,int id,int memory) {
    int require=confirm(memory);
    node *temp=head;
    while(temp!=NULL) {
        if(temp->id==0 && temp->memory==require) {
            temp->id=id;
            return;
        }
        else if(temp->id==0 && temp->memory>require) {
            divide(temp);
            continue;
        }
        temp=temp->next;
    }
}
void display(const node *head) {
    int nums=0;
    const node *temp = head;
    while(temp!=NULL) {
        nums++;
        temp=temp->next;
    }
    printf("%d\n",nums);
    temp=head;
    while (temp != NULL) {
        printf("%d ", temp->id);
        temp = temp->next;
    }
    printf("\n");
}
int n;
int main(void) {
    int q;
    scanf("%d %d",&n,&q);
    node *head=create_node(0,n);
    while(q--) {
        char op;
        scanf(" %c",&op);
        if(op=='A') {
            int id,memory;
            scanf("%d %d",&id,&memory);
            searchandpush(head,id,memory);
        }
        else if(op=='Q') {
            display(head);
        }
    }
    free_node(head);
    return 0;
}
//
// Created by 35861 on 24-11-24.
//
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
void mystrcat(char* s1, char* s2);
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    while(n--) {
        char* s1 = malloc(2002);
        char* s2 = malloc(1002);
        scanf("%s", s1);
        scanf("%s", s2);
        mystrcat(s1, s2);
        free(s1);
        free(s2);
    }
    return 0;
}
void mystrcat(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int p1=0;
    for(int i = 0; i <= len2; i++) {
        char temp = *(s2+len2-i);
        *(s2+len2-i)='\0';
        if(strcmp(s1+len1-len2+i,s2)==0) {
            p1=len2-i;
            *(s2+len2-i)=temp;
            break;
        }
        *(s2+len2-i)=temp;
    }
    strcat(s1,s2+p1);
    printf("%s\n",s1);
}


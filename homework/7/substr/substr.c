//
// Created by 35861 on 24-11-22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_substr(char *s, char *t);
int main() {
    char *s=malloc(100005*sizeof(char));
    char *t=malloc(100005*sizeof(char));
    scanf("%s",s);
    scanf("%s",t);
    find_substr(s,t);
    free(s);
    free(t);
    return 0;
}
void find_substr(char *s, char *t) {
    int point=0;
    int index=0;
    int len=strlen(t);
    while(*(s+point)!='\0') {
        if(*(s+point)==*t) {
            index=point;
            int i=1;
            for(;i<len;i++) {
                if(*(s+point+i)!=*(t+i)) break;
            }
            if(i==len) {
                printf("%d ",index);
            }
        }
        point++;
    }
}

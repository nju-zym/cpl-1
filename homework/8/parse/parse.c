//
// Created by 35861 on 24-11-28.
//
#include <stdio.h>
#include <string.h>
int rule_index[52];
int rule_value_index[52];
char command[2049];
char rule[129];
void mapping();
void parse();
int main() {
    scanf("%s", rule);
    mapping();
    parse();
    return 0;
}
void mapping() {
    for (int i = 0; i < strlen(rule); i++) {
        if(rule[i]>='a'&&rule[i]<='z')rule_index[rule[i] - 'a'+26] = 1;
        if(rule[i]>='A'&&rule[i]<='Z')rule_index[rule[i] - 'A'] = 1;
        if(rule[i]==':') {
            if(rule[i-1]>='a'&&rule[i-1]<='z')rule_value_index[rule[i-1] - 'a'+26] = 1;
            if (rule[i-1]>='A'&&rule[i-1]<='Z')rule_value_index[rule[i-1] - 'A'] = 1;
        }
    }
}
void parse() {
    scanf("%s", command);
    char name[1024];
    strcpy(name, command);
    char temp[1024];
    while (scanf("%s", temp) != EOF) {
        if (temp[0]=='-') {
            int trans=-1;
            if (temp[1]>='a'&&temp[1]<='z') {
                trans = temp[1] - 'a' + 26;
            }
            else if(temp[1]>='A'&&temp[1]<='Z') {
                trans = temp[1] - 'A';
            }
            if (rule_value_index[trans]==1) {
                char temp2[1024];
                if (scanf("%s", temp2)!=EOF) {
                    snprintf(command + strlen(command), sizeof(command) - strlen(command), "\n%c=%s", temp[1], temp2);
                } else {
                    printf("%s: option requires an argument -- '%c'",name, temp[1]);
                    return;
                }
            } else if (rule_index[trans]==1) {
                snprintf(command +strlen(command), sizeof(command) - strlen(command),"\n%c", temp[1]);
            } else {
                printf("%s: invalid option -- '%c'",name, temp[1]);
                return;
            }
        }
    }
    printf("%s", command);
}
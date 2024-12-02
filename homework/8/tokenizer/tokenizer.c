//
// Created by 35861 on 24-11-29.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
const char* reserved[] = {
    "const", "int", "float", "double", "long", "static", "void", "char",
    "extern", "return", "break", "enum", "struct", "typedef", "union", "goto"
};
const int resvered_sum = 16;
const char* operators[] = {"+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"};
const int operators_sum = 11;
char* output[500000];
int output_index = 0;
char* s;
bool flag = true;
bool is_reserved(const char* str);
bool is_integer(const char* str);
bool is_float(const char* str);
bool is_operator(const char* str);
bool is_variable(const char* str);
void process(char* s);
int main() {
    s=malloc(10000);
    while (scanf("%s", s) != EOF) {
        for (char *pos = strchr(s, ';');pos; s = pos + 1, pos = strchr(s, ';')) {
            *pos = '\0';
            if(s[0]!='\0')process(s);
            output[output_index++] = "\n";
            if (flag!=true) {
                printf("Compile Error\n");
                return 0;
            }
        }
        if(s[0]!='\0') {
            process(s);
            output[output_index++] = " ";
        }
    }
    if (s[0]!='\0') {
        printf("Compile Error\n");
        return 0;
    }
    output_index--;
    for (int i = 0; i < output_index; i++) {
        printf("%s", output[i]);
    }
    return 0;
}
bool is_reserved(const char* str) {
    for (int i = 0; i < resvered_sum; i++) {
        if (!strcmp(str, reserved[i])) {
            return true;
        }
    }
    return false;
}
bool is_integer(const char* str) {
   for (int i = 0; i < strlen(str); i++) {
        if (str[i]<'0'||str[i]>'9')return false;
    }
    return true;
}
bool is_float(const char* str) {
    char* pos = strchr(str, '.');
    if (pos==NULL) return false;
    *pos = '\0';
    char* dec = pos + 1;
    if (str[0]=='\0'&&dec[0]!='\0') {
        if (is_integer(dec)) {
            *pos = '.';
            return true;
        } else {
            *pos = '.';
            return false;
        }
    }
    else if(dec[0]=='\0'&&str[0]!='\0') {
        if (is_integer(str)) {
            *pos = '.';
            return true;
        } else {
            *pos = '.';
            return false;
        }
    }
    else if(dec[0]!='\0'&&str[0]!='\0') {
        if (is_integer(str)==true&&is_integer(dec)==true) {
            *pos = '.';
            return true;
        }
        else {
            *pos = '.';
            return false;
        }
    }
    *pos = '.';
    return false;
}
bool is_operator(const char* str) {
    for (int i = 0; i < operators_sum; i++) {
        if (!strcmp(str, operators[i])) {
            return true;
        }
    }
    return false;
}
bool is_variable(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i]<'0'||str[i]>'9')&&(str[i]<'a'||str[i]>'z')
            &&(str[i]<'A'||str[i]>'Z')&&str[i]!='_') return false;
    }
    if (str[0]>='0'&&str[0]<='9') return false;
    return true;
}
void process(char* s) {
    if (is_reserved(s)) {
        output[output_index++] = "reserved";
        return;
    }
    if (is_integer(s)) {
        output[output_index++] = "integer";
        return;
    }
    if (is_float(s)) {
        output[output_index++] = "float";
        return;
    }
    if (is_operator(s)) {
        output[output_index++] = "operator";
        return;
    }
    if (is_variable(s)) {
        output[output_index++] = "variable";
        return;
    }
    flag = false;
}
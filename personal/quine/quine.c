//
// Created by 35861 on 24-11-8.
//
#include <stdio.h>
int main(){
    char* s = "#include <stdio.h>%cint main(){%c    char* s = %c%s%c;%c    printf(s,10,10,34,s,34,10,10);%c}";
    printf(s,10,10,34,s,34,10,10,10,10,34,s,34,10,10);
}

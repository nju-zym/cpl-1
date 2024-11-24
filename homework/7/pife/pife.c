//
// Created by 35861 on 24-11-22.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1002


int nearnums(int *arr,int j,int size);
int main() {
    int n;
    scanf("%d", &n);
    char *str=malloc(MAX*sizeof(char));
    memset(str,0,sizeof(str));
    scanf("%s", str);
    int len = strlen(str);
    int *arr = malloc(sizeof(int) * len);
    int *arr2 = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        if (*(str+i) == 'A') {
            *(arr+i) = 1;
        } else if (*(str+i) == 'B') {
            *(arr+i) = -1;
        } else if (*(str+i) == '.') {
            *(arr+i) = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            int sum=nearnums(arr,j,len);
            if (*(arr+j) == 1||*(arr+j) == -1) {
                if(sum==6||sum==5||sum==1||sum==0||sum==111||sum==-6||sum==-5||sum==-1) {
                    *(arr2+j) = 0;
                }
                else if(*(arr+j)==1) {
                    *(arr2+j) = 1;
                }
                else if(*(arr+j)==-1) {
                    *(arr2+j) = -1;
                }
            }
            else if (*(arr+j) == 0) {
                if(sum==2||sum==3||sum==4) {
                    *(arr2+j) = 1;
                }else if(sum==-2||sum==-3||sum==-4) {
                    *(arr2+j) = -1;
                }
                else {
                    *(arr2+j) = 0;
                }
            }
        }
        for (int j = 0; j < len; j++) {
            *(arr+j) = *(arr2+j);
        }
    }
    for (int i = 0; i < len; i++) {
        if (*(arr+i) == 1) {
            printf("A");
        }
        if (*(arr+i) == -1) {
            printf("B");
        }
        if (*(arr+i) == 0) {
            printf(".");
        }
    }
    free(arr);
    free(arr2);
    free(str);
    return 0;
}

int nearnums(int *arr,int j,int size) {
    int sum = 0;
    if (*(arr+j)==1) {
        for(int i =j-3; i <= j+3; i++) {
            if(i>=0&&i<size&&i!=j) {
                if(*(arr+i)==-1) {
                    return 111;
                }
                else if(*(arr+i)==1) {
                    sum=sum+1;
                }
            }
        }
    }
    if (*(arr+j)==-1) {
        for(int i =j-3; i <= j+3; i++) {
            if(i>=0&&i<size&&i!=j) {
                if(*(arr+i)==1) {
                    return 111;
                }
                 if(*(arr+i)==-1) {
                    sum=sum-1;
                }
            }
        }
    }
    if (*(arr+j) == 0) {
        int flag1 = 0;
        int flag2 = 0;
        for(int i =j-3; i <= j+3; i++) {
            if(i>=0&&i<size) {
                if(*(arr+i)==1) {
                    flag1 = 1;
                }
                if(*(arr+i)==-1) {
                    flag2 = 1;
                }
            }
        }
        if(flag1==flag2) {
            return 111;
        } else {
            for(int i =j-3; i <= j+3; i++) {
                if(i>=0&&i<size) {
                    sum+=*(arr+i);
                }
            }
        }
    }
    return sum;
}
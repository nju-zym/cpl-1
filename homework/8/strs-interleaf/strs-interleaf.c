//
// Created by 35861 on 24-11-28.
//
#include <stdio.h>
#include <string.h>
char s1[1002], s2[1002], s3[2002];
void ils(int s1_len, int s2_len, int ds1, int ds2, int size);
int main() {
    int n,ds1,ds2,size;
    scanf("%d",&n);
    while(n--) {
        getchar();
        int s1_len=0,s2_len=0;
        char ch;
        while ((ch=getchar())!=';') {
            s1[s1_len++]=ch;
        }
        s1[s1_len]='\0';
        while ((ch=getchar())!=';') {
            s2[s2_len++]=ch;
        }
        s2[s2_len]='\0';
        scanf("%d;%d;%d",&ds1,&ds2,&size);
        ils(s1_len,s2_len,ds1,ds2,size-1);
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        memset(s3,0,sizeof(s3));
    }
}
void ils(int s1_len, int s2_len, int ds1, int ds2, int size) {
    int index1=0,index2=0,index3=0;
    while (index1<s1_len && index2<s2_len && index3<size) {
        int takes1=s1_len-index1>ds1? ds1:s1_len-index1;
        for(int i=0;i<takes1&&index3<size;i++) {
            s3[index3++]=s1[index1++];
        }
        if(index3==size) break;
        int takes2=s2_len-index2>ds2? ds2:s2_len-index2;
        for(int i=0;i<takes2&&index3<size;i++) {
            s3[index3++]=s2[index2++];
        }
        if(index3==size) break;
    }
    if(index3!=size&&(index1!=s1_len||index2!=s2_len)) {
       if(index1!=s1_len) {
           int takes1=s1_len-index1>size-index3? size-index3:s1_len-index1;
           for(int i=0;i<takes1;i++) {
               s3[index3++]=s1[index1++];
           }
       }
        if(index2!=s2_len) {
            int takes2=s2_len-index2>size-index3? size-index3:s2_len-index2;
            for(int i=0;i<takes2;i++) {
                s3[index3++]=s2[index2++];
            }
        }
    }
    s3[index3]='\0';
    printf("%s\n",s3);
}
//
// Created by 35861 on 24-11-17.
//
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Rule_Len 128
#define Line_Max 1024

// 用于存储每个命令行参数的结构体
typedef struct {
    char cmd;          // 命令参数
    char *line;        // 参数值
    bool with_args;    // 是否需要值
    int status;        // 当前参数的状态 0: 正常, 1: 无效, 2: 缺少值
} Args;

// 获取规则中字符的索引，A-Z为0-25，a-z为26-51
int get_rule_index(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    return -1;
}

// 处理并保存命令行参数
int save(Args *Command, char *cmd, char *rule) {
    int len = strlen(cmd);
    int ruleLen = strlen(rule);
    int flag = 1;  // 默认标记无效参数

    // 如果是单个短参数
    if (len == 2 && *cmd == '-') {
        Command->cmd = cmd[1]; // 存储命令字符
        for (int i = 0; i < ruleLen; i++) {
            if (cmd[1] == rule[i]) {
                flag = 0;  // 找到有效选项
                Command->with_args = false;
                if (rule[i + 1] == ':') {
                    Command->line = malloc(Line_Max * sizeof(char));
                    memset(Command->line, 0, Line_Max * sizeof(char));
                    scanf("%s", Command->line); // 读取参数值
                    Command->with_args = true;
                    if (strlen(Command->line) == 0) {
                        flag = 2;  // 缺少参数值
                        free(Command->line);
                        Command->line = NULL;
                    }
                }
                break;
            }
        }
    } else {
        flag = 0;
        Command->cmd = 0;
        Command->line = cmd;
        Command->with_args = true;
    }
    Command->status = flag; // 保存当前状态
    return flag;
}

// 处理异常情况并输出错误信息
void Exception(Args *Command, char *name) {
    if (Command->status == 2) {
        printf("%s: option requires an argument -- '%c'\n", name, Command->cmd);
    } else {
        printf("%s: invalid option -- '%c'\n", name, Command->cmd);
    }
}

// 主函数
int main() {
    char *rule = malloc(Rule_Len * sizeof(char));
    scanf("%s", rule);  // 读取规则
    char *name = malloc(Line_Max * sizeof(char));
    scanf("%s", name);  // 读取程序名

    Args *Command = malloc(Line_Max * sizeof(Args)); // 命令存储
    int count = 0;  // 用于计数已经解析的命令行参数
    char *tmp = malloc(Line_Max * sizeof(char));

    // 读取命令行参数并进行处理
    while (scanf("%s", tmp) != EOF) {
        if (save(&Command[count], tmp, rule) == 1) {
            Exception(&Command[count], name); // 无效选项
            free(tmp);
            free(rule);
            free(name);
            free(Command);
            return 0;
        }
        count++;
    }

    // 检查参数是否缺少值
    for (int i = 0; i < count; i++) {
        if (Command[i].status == 2) {
            Exception(&Command[i], name);
            free(tmp);
            free(rule);
            free(name);
            free(Command);
            return 0;
        }
    }

    // 打印程序名
    printf("%s\n", name);

    // 输出有效的命令行参数
    for (int i = 0; i < count; i++) {
        if (Command[i].cmd != 0) {
            if (Command[i].with_args) {
                printf("%c=%s\n", Command[i].cmd, Command[i].line);
            } else {
                printf("%c\n", Command[i].cmd);
            }
        }
    }

    // 释放动态分配的内存
    free(tmp);
    free(rule);
    free(name);
    for (int i = 0; i < count; i++) {
        free(Command[i].line);
    }
    free(Command);

    return 0;
}

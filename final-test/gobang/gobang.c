//
// Created by 35861 on 24-12-24.
//
#include <stdio.h>
#include <stdlib.h>

int vector[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

char map[20][20];

int win(int color);

int can_connect_line(int row, int col);//4个连成线， 需要检查头尾有没有被堵



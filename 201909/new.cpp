#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int m, n; //m宽n高
int p, q;
int len;
const int N = 1085;
const int M = 1925;

int colors[M][N][3] = {0};
int newcolors[M][N][3] = {0};
char buffer[1000000];

void printRes(const char *str){
    int i;
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        printf("\\x%02X", str[i]);
    }
}

int main(){
    printRes("\033[0m");
    return 0;
}
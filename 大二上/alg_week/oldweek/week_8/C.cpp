#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 110
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0;
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0;
char s1[MAXSIZE][MAXSIZE];
bool s2[MAXSIZE][MAXSIZE];

/*
 * 检查函数
 * 把有水的方格的四周8个方块都遍历
 * 递归调用，即可遍历整个池塘
 */
void check(int i, int j) {
    if (s2[i][j]) {
        s2[i][j] = false;
        /* R L */
        check(i, j-1);
        check(i, j+1);
        /* U D */
        check(i-1, j);
        check(i+1, j);

        check(i-1, j+1);
        check(i-1, j-1);

        check(i+1, j+1);
        check(i+1, j-1);
    }
}

int main() {
    int2;
    cin2;
    int number = 0;
    memset(s2, false, sizeof(s2));
    for (int i = 1; i <= a; ++i) {  // 输入
        for (int j = 1; j <= b; ++j) {
            cin >> s1[i][j];
            if (s1[i][j] == 'W') {
                s2[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (s1[i][j] == 'W' && s2[i][j]) { // 遍历每个方格，这样，遍历每个池塘
                number++;
                check(i, j);
            }
        }
    }
    cout << number << endl; // 输出

    return 0;
}

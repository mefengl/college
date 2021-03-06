#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 10000

/* sum_way[i][j] = sum_way[i - j][j] + sum_way[i - 1][j - 1] */

int main() {
    int sum_way[210][10];
    memset(sum_way, 0, sizeof(sum_way)); // 初始化
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j > i) { // 符合题意
                break;
            }
            if (j == i) {
                sum_way[i][j] = 1; // 元条件
            } else {
                sum_way[i][j] = sum_way[i - j][j] + sum_way[i - 1][j - 1]; // 递推公式
            }
        }
    }
    cout << sum_way[n][k] << endl; // 输出
    return 0;
}

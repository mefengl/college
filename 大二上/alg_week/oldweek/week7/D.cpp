#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 10000


/*
 * 重点在于想出下面的递推式
 * f[i] = min(min(f[i-1] + x[i], f[i-2] + x[i-1]), min(f[i-3] + x[i-2],f[i-4]+x[i-3]+x[i-2]))
 */

int main() {
    int loop_times, candy_number;
    cin >> loop_times;
    while (loop_times--) {
        cin >> candy_number;
        int x[candy_number + 1];
        int f[candy_number + 1];
        for (int i = 1; i <= candy_number; ++i) { // 输入
            cin >> x[i];
        }
        f[0] = 0;
        f[1] = x[1];
        f[2] = min((f[1] + x[2]), f[1]);
        f[3] = min(min(f[2] + x[3], f[1] + x[2]), x[1]);
        f[4] = min(min(f[3] + x[4], f[2] + x[3]), min(f[1] + x[2], x[1]+x[2])); // 初始化前4个值
        for (int i = 5; i <= candy_number; ++i) { // 遍历求解
            f[i] = min(min(f[i-1] + x[i], f[i-2] + x[i-1]), min(f[i-3] + x[i-2],f[i-4]+x[i-3]+x[i-2]));
        }
        cout << f[candy_number] << endl; // 输出
    }
    return 0;
}

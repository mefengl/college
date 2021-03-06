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
 * 动态规划的例题
 * 递推式也很容易想到
 * tower_base[floor][width] += max(tower_base[floor-1][width], tower_base[floor-1][width+1])
 */

int main() {
    int tower_number, tower_height;
    cin >> tower_number;
    while (tower_number--) {
        cin >> tower_height;
        int tower_base[tower_height+1][tower_height+1];
        for (int floor = tower_height; floor >= 1; --floor) { // 输入数据
            for (int width = 1; width <= tower_height - floor + 1; ++width) {
                cin >> tower_base[floor][width];
            }
        }
        for (int floor = 2; floor <= tower_height; ++floor) { // 一层一层遍历
            for (int width = 1; width <= tower_height - floor + 1; ++width) {
                tower_base[floor][width] += max(tower_base[floor-1][width], tower_base[floor-1][width+1]);
            }
        }
        cout << tower_base[tower_height][1] << endl; // 输出
    }
    return 0;
}

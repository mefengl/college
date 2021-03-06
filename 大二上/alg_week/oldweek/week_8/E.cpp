#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0;
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0;

#define MAXSIZE 110
int s[MAXSIZE][MAXSIZE];
int2;
int k, by, bx, ey, ex;

/*
 * 核心思路是遍历在k次转向内能够到达的地方
 * 在此前提下，终点被遍历便意味着能到达
 */
int main() {
    int n;
    char ch;
    cin >> n;
    while (n--) {
        cin2;
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                cin >> ch;
                if (ch == '*') {
                    s[i][j] = -2; // 禁区
                } else {
                    s[i][j] = -1; // 非禁区
                }
            }
        }
        cin >> k >> by >> bx >> ey >> ex;
        s[bx][by] = 0; // 起始点

        for (int l = 0; l <= k; ++l) { // 转向k次，起始点转向不算所以从0开始
            for (int i = 1; i <= a; ++i) {
                for (int j = 1; j <= b; ++j) {
                    if (s[i][j] == l) { // 确定可行动点


                        for (int m = j+1; m <= b; ++m) {
                            if (s[i][m] == -2 || s[i][m] == l) break; // 遇到禁区或者已行动点，停止
                            s[i][m] = l + 1;
                        }
                        for (int m = j-1; m >= 1; --m) {
                            if (s[i][m] == -2 || s[i][m] == l) break;
                            s[i][m] = l + 1;
                        }

                        for (int m = i+1; m <= a; ++m) {
                            if (s[m][j] == -2 || s[m][j] == l) break;
                            s[m][j] = l + 1;
                        }
                        for (int m = i-1; m >= 1; --m) {
                            if (s[m][j] == -2 || s[m][j] == l) break;
                            s[m][j] = l + 1;
                        }


                    }
                }
            }
        }
        if (s[ex][ey] == -1) { // 检查是否遍历到
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }
    return 0;
}
// 山山到此一游

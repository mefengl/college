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
#define int2 char a[5], b[5];
int2;
#define MAXSIZE 10
bool s[MAXSIZE][MAXSIZE];

int ex, ey;
int to[8][2] = {{2,-1},{2,1},{1,-2},{1,2},{-1,-2},{-1,2},{-2,-1},{-2,1}}; // 马走日的8种方式

class pos {
public:
    int x;
    int y;
    int step;
};

/*
 * 检查函数
 * 防止越界和重复
 */
bool check(int x, int y) {
    if (x>=1&&y>=1&&x<=8&&y<=8&&s[x][y]) {
        return true;
    }
    return false;
}

/*
 * 核心函数
 * 广度优先搜索
 */
int BFS() {
    ex = b[0] - 'a' + 1;
    ey = b[1] - '0'; // 特别容易错，这里是字符型数字，需要转换成整数
    pos p, t, v;
    p.x = a[0] - 'a' + 1;
    p.y = a[1] - '0';
    p.step = 0;
    queue<pos> q;
    q.push(p);
    while (!q.empty()) {
        t = q.front();
        if (t.x == ex && t.y == ey) {
            return t.step;
        }
        for (int i = 0; i < 8; ++i) {
            v = t;
            v.x += to[i][0];
            v.y += to[i][1];
            if (check(v.x, v.y)) {
                s[v.x][v.y] = false; // 留下足迹
                v.step++;
                q.push(v);
            }
        }
        q.pop();
    }
}

int main() {
    while (scanf("%s%s",a,b)!=EOF) { // 遍历所有数据
        memset(s, true, sizeof(s)); // 初始化
        printf("To get from %s to %s takes %d knight moves.\n", a, b, BFS()); // 输出
    }
    return 0;
}

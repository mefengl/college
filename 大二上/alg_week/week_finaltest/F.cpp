#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 100
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0;
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0;
int size;
char s[MAXSIZE][MAXSIZE];
int to[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; // 上下左右
class pos {
public:
    int i, j;
    int time;
};

/*
 * 检查函数确保不越界，不重复
 */
bool check(int i, int j) {
    if (i>=0&&j>=0&&i<size&&j<size&&s[i][j]!='#') {
        return true;
    }
    return false;
}

int BFS(int i, int j) {
    queue<pos> q;
    pos p, t;
    p.i = i;
    p.j = j;
    p.time = 0;
    s[p.i][p.j] = '#';
    q.push(p);
    while (!q.empty()) { // 判断队列是否完成
        t = q.front();
        for (int l = 0; l < 4; ++l) {
            pos e;
            e = t;
            e.i += to[l][0];
            e.j += to[l][1];
            if (check(e.i, e.j)) {
                e.time++;
                if (s[e.i][e.j] == 'e') { // 终止条件
                    return e.time;
                }
                s[e.i][e.j] = '#';
                q.push(e);
            }
        }
        q.pop();
    }
    return -1;
}

/* 广度优先 队列来解决 */
int main() {
    cin >> size;
    for (int i = 0; i < size; ++i) { // 输入
        for (int j = 0; j < size; ++j) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < size; ++i) { // 遍历找起始位置
        for (int j = 0; j < size; ++j) {
                if (s[i][j] == 's') {
                    int time = BFS(i, j);
                    cout << time;
//                    if (time == -1) {
//                        cout << -1;
//                    } else {
//                        cout << time; // 输出
//                    }
                }
        }
    }
    return 0;
}
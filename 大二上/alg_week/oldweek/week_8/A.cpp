#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MAXSIZE 40
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0;
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0;
char s[MAXSIZE][MAXSIZE][MAXSIZE];
int to[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}}; // 上下前后左右六个方向
int3;
class pos {
public:
    int i, j ,k;
    int time;
};

/*
 * 检查函数确保不越界，不重复
 */
bool check(int i, int j, int k) {
    if (i>=0&&j>=0&&k>=0&&i<a&&j<b&&k<c&&s[i][j][k]!='#') {
        return true;
    }
    return false;
}

int BFS(int i, int j, int k) {
    queue<pos> q;
    pos p, t;
    p.i = i;
    p.j = j;
    p.k  = k;
    p.time = 0;
    s[p.i][p.j][p.k] = '#';
    q.push(p);
    while (!q.empty()) { // 判断队列是否完成
        t = q.front();
        for (int l = 0; l < 6; ++l) {
            pos e;
            e = t;
            e.i += to[l][0];
            e.j += to[l][1];
            e.k += to[l][2];
            if (check(e.i, e.j, e.k)) {
                e.time++;
                if (s[e.i][e.j][e.k] == 'E') { // 终止条件
                    return e.time;
                }
                s[e.i][e.j][e.k] = '#';
                q.push(e);
            }
        }
        q.pop();
    }
    return -1;
}

/* 广度优先 队列来解决 */
int main() {
    while (cin3) {
        if (a+b+c == 0) {
            break;
        }
        for (int i = 0; i < a; ++i) { // 输入
            for (int j = 0; j < b; ++j) {
                for (int k = 0; k < c; ++k) {
                    cin >> s[i][j][k];
                }
            }
        }
        for (int i = 0; i < a; ++i) { // 遍历找起始位置
            for (int j = 0; j < b; ++j) {
                for (int k = 0; k < c; ++k) {
                    if (s[i][j][k] == 'S') {
                        int time = BFS(i, j, k);
                        if (time == -1) {
                            cout << "Trapped!" << endl;
                        } else {
                            cout << "Escaped in ";
                            cout << time << " minute(s)." << endl; // 输出
                        }
                    }
                }
            }
        }
    }
    return 0;
}
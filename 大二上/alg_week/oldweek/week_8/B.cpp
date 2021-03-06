#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <queue>
using namespace std;
#define MAXSIZE 100010
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0;
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0;
bool s[MAXSIZE];
int2;

class pos {
public:
    int x;
    int time;
};

/*
 * 检查函数
 * 防止越界
 * 防止重复
 */
bool check(int x) {
    if (x>=0 && x <= 100000 && s[x]) {
        return true;
    }
    return false;
}

/*
 * 移动函数
 */
int to(int x, int i) {
    if (i == 0) {
        return x+1;
    } else if (i == 1) {
        return x-1;
    } else {
        return x*2;
    }
}

/*
 * 核心函数：广度优先搜索
 */
int BFS() {
    queue<pos> q;
    pos p, t, v;
    p.x = a;
    p.time = 0;
    q.push(p);
    while (!q.empty()) {
        t = q.front();
        if (t.x == b) {
            return t.time;
        }
        for (int i = 0; i < 3; ++i) {
            v = t;
            v.x = to(v.x, i);
            if (check(v.x)) {
                v.time++;
                s[v.x] = false;
                q.push(v);
            }
        }
        q.pop();
    }
}


int main() {

    while (cin2) {
        memset(s, true, MAXSIZE);
        cout << BFS() << endl; // 输出
    }
    return 0;
}

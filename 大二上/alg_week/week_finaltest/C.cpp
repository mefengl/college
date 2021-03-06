#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>
#include <iomanip>
using namespace std;
#define MAXSIZE 10000
#define cin2 cin >> a >> b
#define int2 int a = 0, b = 0;
#define cin3 cin >> a >> b >> c
#define int3 int a = 0, b = 0, c = 0;
long long number;
long long s[MAXSIZE];

void fac(long long x) {
    if (x == 1) {
        return;
    }
    long long flag = 0;
    for (long long i = 2; i < x; ++i) {
        if (x % i == 0) {
            s[flag++] = i;
        }
    }
}

class pos {
public:
    long long x;
    long long step;
};
/*
 * 检查函数
 * 防止越界和重复
 */
bool check(int x) {
    if (x>0) {
        return true;
    }
    return false;
}
int BFS() {
    pos p, t, v;
    p.x = number;
    p.step = 0;
    queue<pos> q;
    q.push(p);
    while (!q.empty()) {
        t = q.front();
        if (t.x == 1) {
            return t.step;
        }
        for (int i = -1; ; ++i) {
            if (i == -1) {
                v = t;
                v.x -= 1;
                if (check(v.x)) {
//                    s[v.x][v.y] = false; // 留下足迹
                    v.step++;
                    q.push(v);
                }
                continue;
            }
            if (s[i] == -1) {
                break;
            }
            v = t;
            if (v.x % s[i] == 0) {
                v.x /= s[i];
                if (check(v.x)) {
//                    s[v.x][v.y] = false; // 留下足迹
                    v.step++;
                    q.push(v);
                }
            }
        }
        q.pop();
    }
}

int main() {
    while (cin >> number) {
        memset(s, -1, MAXSIZE); // 初始化
        fac(number);
        cout << BFS() << endl;
    }

    return 0;
}
